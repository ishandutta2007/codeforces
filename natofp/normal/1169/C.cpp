#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nax=3e5+5;
int a[nax];

bool czy(int x)
{
    int tab[nax];
    for(int i=1;i<=n;i++) tab[i]=a[i];
    if(tab[1]+x>=m) tab[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(tab[i]==tab[i-1]) continue;
        else if(tab[i]<tab[i-1])
        {
            if(tab[i]+x>=tab[i-1]) tab[i]=tab[i-1];
            else return false;
        }
        else if(tab[i]>tab[i-1])
        {
            if(tab[i]+x>=m+tab[i-1])
            {
                tab[i]=tab[i-1];
            }
            else continue;
        }

    }
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int lo=0;
    int hi=m;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        bool ok=czy(mid);
        if(ok)
        {
            hi=mid;
        }
        else lo=mid;
    }
    if(czy(lo)) cout<<lo;
    else cout<<hi;
    return 0;
}