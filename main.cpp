
const int buttonPin = 12;     // the number of the pushbutton pin
int redPin = 8;
int greenPin = 9;
int bluePin = 11;
int state = 0;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    if(state == 0) {
      generateColor();
      state = 1;
    }
  } else {
    state = 0;
    }
}

    // Generate a random colour, using the built-in rand() function. 
    void generateColor() {
      setColor(rand() % 255, rand() % 255, rand() % 255);

    }
    
    void setColor(int red, int green, int blue)
    {
      #ifdef COMMON_ANODE
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
      #endif
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);  
    }
