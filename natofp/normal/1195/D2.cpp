#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5;
int n;
vector<int> a(nax);
int mod=998244353;
long long int res=0;
long long int ile[15][15];
long long int ileziomkow[15];

void xd(int t)
{
    int asa=0;
    int s=t;
    while(s>0)
    {
        s/=10; asa++;
    }
    int akt=0;
    ileziomkow[asa]++;
    while(t>0)
    {
        int dig=t%10;
        t/=10;
        ile[asa][akt]+=dig;
        if(ile[asa][akt]>=mod) ile[asa][akt]-=mod;
        akt++;
    }
}

void solve(int i,int j)
{
    int xd=min(i,j);
    long long int waga=1;
    for(int dig=0;dig<xd;dig++)
    {
        long long int akt=0;
        long long int akt2=0;
        akt+=ile[j][dig]*waga;
        akt%=mod;
        akt*=ileziomkow[i];
        akt%=mod;
        akt2=ile[i][dig]*waga;
        akt2%=mod;
        akt2*=10;
        akt2%=mod;
        akt2*=ileziomkow[j];
        akt2%=mod;
        akt+=akt2;
        if(akt>=mod) akt-=mod;
        res+=akt;
        if(res>=mod) res-=mod;
        waga*=100;
        waga%=mod;
    }
    if(j>i) swap(i,j);
    if(j<i)
    {
        for(int dig=xd;dig<i;dig++)
        {
            long long int akt=ile[i][dig]*waga;
            akt%=mod;
            akt*=ileziomkow[j];
            akt%=mod;
            res+=akt;
            if(res>=mod) res-=mod;
            waga*=10;
            waga%=mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        xd(a[i]);
    }
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            solve(i,j);
        }
    }
    cout<<res;
    return 0;
}