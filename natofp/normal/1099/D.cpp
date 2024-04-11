#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=200000;
vector<ll> adj[N];
vector<ll> a(N,-1);
vector<ll> s(N,-1);
vector<bool> visited(N,false);
bool ok=true;
vector<ll> child[N];

void dfs(int v,int p)
{
    visited[v]=true;
    if(v==1) a[1]=s[1];
    else
    {
        if(s[v]==-1)
        {
            ll naj=1000000001;
            for(int k=0;k<child[v].size();k++) naj=min(naj,s[child[v][k]]);
            ll aktsum=s[p];
            if(naj==1000000001)
            {
                a[v]=0;
                s[v]=s[p];
            }
            else
            {
                if(aktsum>naj) {cout<<-1; ok=false; return;}
                else
                {
                    a[v]=naj-aktsum;
                    s[v]=s[p]+a[v];
                }
            }
        }
        else
        {
            ll ile=s[v]-s[p];
            if(ile<0LL) {cout<<-1; ok=false; return;}
            else a[v]=ile;
        }
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false)
        {
            dfs(adj[v][i],v);
        }
    }
    return;
}

int main()
{
    int n; cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x; cin>>x; adj[x].push_back(i);
        adj[i].push_back(x);
        child[x].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>s[i];
    dfs(1,-1);
    if(ok==false) return 0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}