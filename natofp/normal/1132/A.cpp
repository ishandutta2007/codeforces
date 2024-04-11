#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,c,d; cin>>a>>b>>c>>d;
    long long int sum=0;
    sum+=a;
    if(sum==0 && c>0) {cout<<0; return 0;}
    if(d>sum) cout<<0;
    else
    {
        if(a==d) cout<<1;
        else cout<<0;
    }
    return 0;
}