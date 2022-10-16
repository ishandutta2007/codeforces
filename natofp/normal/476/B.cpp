#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{

    string a,b;
    cin>>a>>b;
    int ile=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='+') ile++;
    }
    int ile2=0;
    int ileznakow=0;
    for(int i=0;i<b.length();i++)
    {
        if(b[i]=='+') ile2++;
        if(b[i]=='?') ileznakow++;
    }
    int n=b.length();
    int k=ile-ile2;
    n=ileznakow;
    double ans=1;
    if(k<0 || k>n) {cout<<0; return 0;}
    else
    {

        for(int i=1;i<=n;i++) ans*=i;
        for(int i=1;i<=k;i++) ans/=i;
        for(int i=1;i<=n-k;i++) ans/=i;
        for(int i=0;i<n;i++) ans/=2;
    }
    cout<<setprecision(20)<<ans;
    return 0;
}