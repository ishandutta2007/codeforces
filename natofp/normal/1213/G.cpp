#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=2e5+5;
int n,m;

ll res[nax];
ll akt=0;

int sz[nax];
int p[nax];

int f(int v)
{
    if(p[v]==v) return v;
    return p[v]=f(p[v]);
}

int u(int a,int b)
{
    a=f(a);
    b=f(b);
    //cout<<"XD"<<a<<" "<<b<<endl;
    p[a]=b;
    akt+=(ll)sz[a]*sz[b];
    //cout<<"XD"<<sz[a]<<" "<<sz[b]<<endl;
    sz[b]+=sz[a];
    //cout<<"XD"<<sz[a]<<endl;

}

struct kraw
{
    int a,b,c;
};

bool por(kraw a,kraw b)
{
    return a.c<b.c;
}

vector<kraw> jd;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<nax;i++) sz[i]=1;
    for(int i=1;i<nax;i++) p[i]=i;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        kraw nowa;
        nowa.a=a;
        nowa.b=b;
        nowa.c=c;
        jd.push_back(nowa);
    }
    sort(jd.begin(),jd.end(),por);
    for(int i=0;i<jd.size();i++)
    {
        u(jd[i].a,jd[i].b);
        res[jd[i].c]=akt;
    }
    for(int i=1;i<nax;i++)
    {
        if(res[i]==0) res[i]=res[i-1];
    }
    while(m--)
    {
        int q; cin>>q;
        cout<<res[q]<<" ";
    }
    return 0;
}