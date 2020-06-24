


//////////////////////Stepper code: ///////////////////////////
#include <Stepper.h>

const int stepsPerMotorRevolution = 32;  //No of steps per internal revolution of motor,
//4-step mode as used in Arduino Stepper library

const int stepsPerOutputRevolution = 32 * 64; //no of steps per revolution of the output shaft

const int motorpin1 = 8;                    //Assign motor (ie board) pins to Arduino pins
const int motorpin2 = 9;                    //
const int motorpin3 = 10;                   //
const int motorpin4 = 11;                   //

// initialize the stepper library on pins 8 through 11, Motor rev steps, "Firing" sequence 1-3-2-4,
Stepper myStepper(stepsPerMotorRevolution, motorpin1, motorpin3, motorpin2, motorpin4);

//////////////////////////////end stepper code///////////////////////

int inByte = 0;         // incoming serial byte

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(800);    
}

void loop() {

  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    switch(inByte){
       case'1': {
         myStepper.step(stepsPerOutputRevolution/8);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8);
         break;
       }
       case'2': {
         myStepper.step(stepsPerOutputRevolution/8*2);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*2);
         break;
       }
       case'3': {
         myStepper.step(stepsPerOutputRevolution/8*3);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*3);
         break;
       }
       case'4': {
         myStepper.step(stepsPerOutputRevolution/8*4);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*4);
         break;
       }
       case'5': {
         myStepper.step(stepsPerOutputRevolution/8*5);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*5);
         break;
       }
       case'6': {
         myStepper.step(stepsPerOutputRevolution/8*6);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*6);
         break;
       }
       case'7': {
         myStepper.step(stepsPerOutputRevolution/8*7);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*7);
         break;
       }
       case'8': {
         myStepper.step(stepsPerOutputRevolution/8*8);
         delay(500);
         myStepper.step(-stepsPerOutputRevolution/8*8);
         break;
       }
      

    }
  }

}
