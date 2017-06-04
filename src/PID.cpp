#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd){
     Kp = kp;
     Ki = ki;
     Kd = kd;

     data_received = false;
     p_error = 0;
     i_error  = 0;
     d_error = 0;

     err = 0;
     steps = 0;     
}

void PID::UpdateError(double cte) {    
    if (data_received == false){
        p_error = cte;
        data_received = true;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error  += cte;
    err = cte > 0 ? err + cte : err - cte;
    steps++;
}

double PID::getSteer(){
    double steer =  -Kp * p_error - Kd * d_error - Ki * i_error;
    steer = steer < -1 ? -1 : steer;
    steer = steer > 1 ? 1 : steer;            
    return steer;
}

double PID::TotalError() {
    return err;
}

int PID::getSteps(){
    return steps;
}