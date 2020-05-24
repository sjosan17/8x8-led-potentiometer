/*
 Created by Sander Sjøthun
 14.02.2019
 8x8 Matrix showing a spiral.
 A potentiometer will controll the speed of the spiral. 
*/

// Libary to control the 8x8 matrix
#include "LedControl.h"
#include "binary.h"

/*
 DIN is pin 12
 CS is pin 10
 CLK is pin 11
*/
LedControl lc=LedControl(12,10,11,1);
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM

// Spiral 1 start
byte s1[8]= {B11111111,B00000001,B01111101,B01000101,B01010101,B01011101,B01000001,B01111111};
// Spiral 2
byte s2[8]= {B00000001,B11111101,B10000101,B10110101,B10100101,B10111101,B10000001,B11111111};
// Spiral 3
byte s3[8]= {B11111110,B10000010,B10111010,B10101010,B10100010,B10111110,B10000000,B11111111};
// Spiral 4 end
byte s4[8]= {B11111111,B10000001,B10111101,B10100101,B10101101,B10100001,B10111111,B10000000};

void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,5);
  // Clear the display
  lc.clearDisplay(0);  
}

void loop(){
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  lc.setRow(0,0,s1[0]);
  lc.setRow(0,1,s1[1]);
  lc.setRow(0,2,s1[2]);
  lc.setRow(0,3,s1[3]);
  lc.setRow(0,4,s1[4]);
  lc.setRow(0,5,s1[5]);
  lc.setRow(0,6,s1[6]);
  lc.setRow(0,7,s1[7]);
  delay(outputValue);
  
  // Display spiral 2
  lc.setRow(0,0,s2[0]);
  lc.setRow(0,1,s2[1]);
  lc.setRow(0,2,s2[2]);
  lc.setRow(0,3,s2[3]);
  lc.setRow(0,4,s2[4]);
  lc.setRow(0,5,s2[5]);
  lc.setRow(0,6,s2[6]);
  lc.setRow(0,7,s2[7]);
  delay(outputValue);
  
  // Display spiral 3
  lc.setRow(0,0,s3[0]);
  lc.setRow(0,1,s3[1]);
  lc.setRow(0,2,s3[2]);
  lc.setRow(0,3,s3[3]);
  lc.setRow(0,4,s3[4]);
  lc.setRow(0,5,s3[5]);
  lc.setRow(0,6,s3[6]);
  lc.setRow(0,7,s3[7]);
  delay(outputValue);

  // Display spiral 4 end
  lc.setRow(0,0,s4[0]);
  lc.setRow(0,1,s4[1]);
  lc.setRow(0,2,s4[2]);
  lc.setRow(0,3,s4[3]);
  lc.setRow(0,4,s4[4]);
  lc.setRow(0,5,s4[5]);
  lc.setRow(0,6,s4[6]);
  lc.setRow(0,7,s4[7]);
  delay(outputValue);
}
