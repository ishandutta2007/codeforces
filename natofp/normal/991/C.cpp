#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sprawdz(long long int k,long long int n)
{
    long long a=0;
    long long b=0;
    while(n>0)
    {
        if(n<k) {a+=n; n=0;}
        else
        {
            a+=k;
            n-=k;
        }
        long long w=n/10;
        b+=w;
        n-=w;

    }
    if(a>=b) return true;
    return false;
}

long long BS(long long int n)
{
    long long dol,gora,srodek;
    dol=1;
    gora=n/10+1;
    while(dol<gora)
    {
        srodek=(dol+gora)/2;
        if(sprawdz(srodek,n))
        {
           gora=srodek;
        }
        else dol=srodek+1;
    }
    return min(dol,gora);
}

int main()
{

   long long int n;
    cin>>n;
    cout<<BS(n);
    return 0;
}