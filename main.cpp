#include <iostream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

/**
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Yeshwanth Mandava
 */

int loadNum();

int main() {
    cout << "Welcome to mini-calculator app!!!\nPlease enter 3 arguments -> 2 single digit numbers in either numerical form or string from, and the operation character (+,-,*,/)\nEnter in the respective order and use spaces [number][operation][number]:  ";    string ErrorM = "Sorry, the input you entered is not a single digit number.\n";
    int op1, op2;
    char operation;
    while (true) {
        op1 = loadNum();
        if (op1 == -1)
        {
            cout << ErrorM;
            break;
        }
        cin >> operation;
        op2 = loadNum();
        if (op2 == -1)
        {
            cout << ErrorM;
            break;
        }
        switch(operation) {
            case '+':
                cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2 << "\n";
                break;
            case '-':
                cout << "The difference between " << op1 << " and " << op2 << " is " << op1 - op2 << "\n";
                break;
            case '*':
                cout << "The product of " << op1 << " and " << op2 << " is " << op1 * op2 << "\n";
                break;
            case '/':
                if(op2 == 0)
                {
                    cout << "Sorry the second number you entered is 0 thus the quotient will be undefined. Try again!\n";
                    break;
                }
                cout << "The quotient of " << op1 << " and " << op2 << " is " << op1 / op2 << "\n";
                break;
            default:
                cout << "Sorry you entered an invalid operation. Please enter one of the following ( +, -, *, /)";
                break;
        }
    }
    return 0;
}

int loadNum()
{
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    if (cin >> num)
    {
        if(num >= 0 && num<10)
        {
            return num;
        }
        return -1;
    }
    cin.clear();
    string numString;
    cin >> numString;
    for (int i = 0; i < nums.size(); i++)
    {
        if (numString == nums[i])
        {
            return i;
        }
    }
    return -1;
}
