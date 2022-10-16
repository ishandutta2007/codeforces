#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int nax=1e5+5;

int ile[nax];
vector<int> adj[nax];
int n,m;
int sz[nax];
int p[nax];
bool czy[nax];
int jakie[nax];

vector<int> nieroby;

int ff(int v)
{
    if(p[v]==v) return v;
    return p[v]=ff(p[v]);
}

void uu(int a,int b)
{
    if(ff(a)==ff(b)) return;
    a=ff(a);
    b=ff(b);
    if(sz[a]<sz[b]) swap(a,b);
    sz[a]+=sz[b];
    p[b]=a;
}



int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        ile[x]++;
        ile[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> xd;
    for(int i=1;i<=n;i++)
    {
        sz[i]=1;
        p[i]=i;
    }
    int idx=1;
    int res=ile[1];
    for(int i=2;i<=n;i++)
    {
        if(ile[i]<res)
        {
            ile[i]=res;
            idx=i;
        }
    }
    for(int i=0;i<adj[idx].size();i++)
    {
        jakie[adj[idx][i]]=1;
        nieroby.push_back(adj[idx][i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(jakie[i]==0)
        {
            uu(i,idx);
        }
    }
    for(int i=0;i<nieroby.size();i++)
    {
        int akt=nieroby[i];
        for(int j=1;j<=n;j++)
        {
            jakie[j]=0;
        }
        for(int j=0;j<adj[akt].size();j++)
        {
            jakie[adj[akt][j]]=1;
        }
        for(int j=1;j<=n;j++)
        {
            if(jakie[j]==0) uu(j,akt);
        }
    }
    set<int> xdd;
    for(int i=1;i<=n;i++)
    {
        xdd.insert(ff(p[i]));
    }
    cout<<xdd.size()-1;
    return 0;
}