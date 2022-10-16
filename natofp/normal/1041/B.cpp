#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
    while(b)
    {
        long long int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    long long int a,b,x,y;
    cin>>a>>b>>x>>y;
    long long int t=gcd(x,y);
    x/=t;
    y/=t;
    cout<<min(a/x,b/y);
    return 0;
}