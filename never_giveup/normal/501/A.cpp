#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long x,y;
    x=max(3*a/10,a-a/250*c);
    y=max(3*b/10,b-b/250*d);
    if(x>y){
        cout<<"Misha";
    }
    else{
        if(x<y){
            cout<<"Vasya";
        }
        else{
            cout<<"Tie";
        }
    }
}