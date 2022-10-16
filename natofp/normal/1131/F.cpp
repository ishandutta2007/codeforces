#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int koniec[N][2];
int parent[N];
int rozmiar[N];
vector<int> adj[N];
int n;

void pre()
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        koniec[i][0]=koniec[i][1]=i;
        rozmiar[i]=1;
    }
}

int f(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=f(parent[x]);
}

int p(int a,int b)
{
    int prawo,lewo;
    int x1=f(a);
    int x2=f(b);
    lewo=koniec[x1][0];
    prawo=koniec[x2][1];
    int u,v;
    u=koniec[x1][1];
    v=koniec[x2][0];
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(x1<x2) swap(x1,x2);
    parent[x2]=x1;
    rozmiar[x1]+=rozmiar[x2];
    koniec[x1][0]=lewo;
    koniec[x1][1]=prawo;


}

void dfs(int v,int p)
{
    cout<<v<<" ";
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i]!=p) dfs(adj[v][i],v);
    }
}

int main()
{
    cin>>n;
    pre();
    for(int i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        p(a,b);
    }
    int idx;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()==1) idx=i;
    }
    dfs(idx,idx);
    return 0;
}