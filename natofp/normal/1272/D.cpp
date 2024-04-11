#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];
int ile[nax];
int pp[nax];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    ile[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1]) ile[i]=ile[i+1]+1;
        else ile[i]=1;
        res=max(res,ile[i]);
    }
    pp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) pp[i]=pp[i-1]+1;
        else pp[i]=1;
    }
    for(int i=2;i<=n-1;i++)
    {
        if(a[i-1]<a[i+1]) res=max(res,pp[i-1]+ile[i+1]);
    }
    cout<<res;
    return 0;
}