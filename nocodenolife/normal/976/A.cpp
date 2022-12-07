#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n;
    cin>>n;
    int zero = 0, one = 0;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='0')
            zero++;
        else
            one++;
    }
    if(one>0)
    {
        cout<<"1";
        for(int i=0;i<zero;i++)
        {
            cout<<"0";
        }
    }
    else
    {
        cout<<"0"<<endl;
    }
    
    return 0;
}