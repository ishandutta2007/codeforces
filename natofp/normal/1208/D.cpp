#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
ll a[nax];
int n;
const int roz=(1<<20);
ll t[roz];
ll inf=1e12;
ll res[nax];

void ini()
{
    for(int i=roz/2;i<roz;i++) t[i]=inf;
    t[roz/2]=0;
    for(int i=1;i<=n;i++)
    {
        t[roz/2+i]=i;
    }
    for(int i=roz/2-1;i>=1;i--) t[i]=t[i*2]+t[i*2+1];
}

void usun(int k)
{
    int z=k+roz/2;
    while(z>=1)
    {
        t[z]-=k;
        z/=2;
    }
}

int f(int wezel,ll rest)
{
    if(wezel*2+1>=roz) return wezel;
    ll suma=t[wezel*2];
    if(suma>rest)
    {
        return f(wezel*2,rest);
    }
    else
    {
        return f(wezel*2+1,rest-t[wezel*2]);
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int pos=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ini();
    for(int i=n;i>=1;i--)
    {
        int idx=f(1,a[i])-roz/2;
        res[i]=idx;
        usun(idx);
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    return 0;
}