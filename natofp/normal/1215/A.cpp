#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    // min
    ll suma=a1*k1+a2*k2;
    ll mini=min(a1+a2,suma-n);
    mini=a1+a2-mini;
    cout<<mini;
    if(k1>k2)
    {
        swap(k1,k2);
        swap(a1,a2);
    }
    int res=0;
    while(a1>0 && n>=k1)
    {
        res++;
        a1--;
        n-=k1;
    }
    while(a2>0 && n>=k2)
    {
        res++;
        a2--;
        n-=k2;
    }
    cout<<" "<<res;
    return 0;
}