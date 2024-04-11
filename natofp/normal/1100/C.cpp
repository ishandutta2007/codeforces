#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n,r;
    cin>>n>>r;
    double pi=3.1415926535;
    double z=cos(2*pi/n);
    double hi,lo;
    lo=0.00000001;
    hi=1e9;
    for(int i=0;i<100;i++)
    {


        double mid=(lo+hi)/2;
        if(4*mid*mid>2*(mid+r)*(mid+r)*(1-z))
        {
            hi=mid;
        }
        else lo=mid;
    }
    cout<<setprecision(20)<<(hi+lo)/2;
    return 0;
}