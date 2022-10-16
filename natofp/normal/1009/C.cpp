#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long  n,m;
    cin>>n>>m;
    long long av=0;
    for(int i=0;i<m;i++)
    {
        double x,d;
        cin>>x>>d;
        av+=(n*x);
        if(d>=0)
        {
            av+=(d*(n-1)*n/2);
        }
        else
        {
            av+=(d*((((n/2)*(n/2+1)/2)+(n-n/2-1)*(n-n/2)/2)));
        }
    }
    cout<<setprecision(30)<<(double)av/n;


    return 0;
}