/*
    It's a simple calculator.
    for gui fltk library is used.
    In this it's read two input from the user and show it sum


*/
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Output.H>


class calculator{
    public :
    float add (float num1 ,float num2);
    float sub (float num1, float num2);
    float mul (float num1, float num2);
    float div (float num1 , float num2);
};


float calculator::add(float num1 , float num2){
    return num1+num2;
}

float calculator::sub(float num1, float num2){
    return num1-num2;
}

float calculator::mul(float num1,float num2){
    return num1*num2;
}

float calculator::div(float num1, float num2){
    return num1/num2;
}






//here intializing needed gui components ( needed gui classes and etc....) as gloabal
Fl_Window *window = new Fl_Window(600, 600);

//below input1 and input2 for reading values
Fl_Input *input1 = new Fl_Input(10, 55, 100, 25);
Fl_Input *input2 = new Fl_Input(120, 55, 100, 25);

//below buttons for calculator operations
Fl_Button *AddButton = new Fl_Button(230, 10, 70, 25, "Add");
Fl_Button *SubButton = new Fl_Button(230, 40, 70, 25, "Sub");
Fl_Button *MulButton = new Fl_Button(230, 70, 70, 25, "Mul");
Fl_Button *DivButton = new Fl_Button(230, 100, 70, 25, "Div");

//below answerOutBox for to place or show the result
Fl_Value_Output *answerOutBox = new Fl_Value_Output(320, 55,100,25);




// object for calculator class
calculator cal;

// creating input and result variables are global

float num1 , num2 , answer=0;

void readValues(){
    //atof function is convert string to floating point number
    num1 = atof(input1->value()); //input1->value() :- this value() function give as the value in that box
    num2  = atof(input2->value());
    return;
}
void outResult(){
    answerOutBox->value(answer); //this code place sum in answerOutBox
    Fl::warning("The answer is %f", answer); //this code showing the sum in terminal
    return;
}


// add_numbers funciton 
void add_numbers(Fl_Widget *w, void *data){ 
    readValues();
    answer = cal.add(num1,num2);
    outResult();
    return;
}

void sub_numbers(Fl_Widget *w, void *data){ 
    readValues();
    answer = cal.sub(num1,num2);
    outResult();
    return;
}
void mul_numbers(Fl_Widget *w, void *data){ 
    readValues();
    answer = cal.mul(num1,num2);
    outResult();
    return;
}
void div_numbers(Fl_Widget *w, void *data){ 
    readValues();
    answer = cal.div(num1,num2);
    outResult();
    return;
}


int main(int argc, char **argv) {


    // calling function when button are clicked
    AddButton->callback(add_numbers); 
    SubButton->callback(sub_numbers);
    MulButton->callback(mul_numbers);
    DivButton->callback(div_numbers);


    window->show();
    Fl::run();

  return 0;
}
