#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int a[nax];

int first[nax];
int last[nax];
int ile[nax];

struct xd
{
    int a,b,c;
};

bool por(xd a,xd b)
{
    return a.a<b.a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int q; cin>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int akt=a[i];
        ile[akt]++;
        last[akt]=i;
        if(first[akt]==0) first[akt]=i;
    }
    int res=0;
    vector<xd> zz;
    for(int i=1;i<nax;i++)
    {
        if(first[i]==0) continue;
        xd nowy;
        nowy.a=first[i];
        nowy.b=last[i];
        nowy.c=ile[i];
        zz.push_back(nowy);
    }
    sort(zz.begin(),zz.end(),por);
    int k=zz.size();
    //cout<<k<<endl;
    int aktmax=0;
    int maxkon=0;
    int pocz=1;
    vector<pair<int,int> > debug;
    for(int i=0;i<k;i++)
    {
        int koniec=zz[i].b;
        maxkon=max(maxkon,koniec);
        aktmax=max(aktmax,zz[i].c);
        if(i==k-1 || maxkon<zz[i+1].a)
        {
            res+=maxkon-pocz+1-aktmax;
            aktmax=0;
            if(i!=k-1) pocz=zz[i+1].a;
        }
    }
    cout<<res;
    
    return 0;
}