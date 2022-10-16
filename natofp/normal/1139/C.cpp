#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
vector<int> adj[nax];
vector<int> ile;
vector<bool> visited(nax,false);
int licz;
void dfs(int v)
{
    licz++;
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs(adj[v][i]);
    }
}

const int m=1e9+7;

long long binpow(long long a, long long b)
{
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        if(c!=1)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++)
    {
        licz=0;
        if(visited[i]==false) dfs(i);
        ile.push_back(licz);
    }
    long long int res=0;
    res+=binpow(n,k);
    for(int i=0;i<ile.size();i++)
    {
        long long od=binpow(ile[i],k);
        res-=od;
        if(res<0) res+=m;
    }
    cout<<res;
    return 0;
}