#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            
            return 0;
        }
    }
    return 1;
}

int main() {

    string str;
    cin>>str;
    if(isPalindrome(str))
    {
        int k=0;
        int l = 0;
        int h = str.length() - 1;
        while (h > l)
        {
            if (str[l++] != str[0])
            {
                k=1;
                cout<<str.length()-1<<endl;
                return 0;
            }
        }
        if(k==0)
            cout<<"0"<<endl;
    }
    else
    {
        cout<<str.length()<<endl;
    }
    return 0;
}