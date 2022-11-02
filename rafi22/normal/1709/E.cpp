#include <bits/stdc++.h>

//#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=200007;

int a[N];
int d[N];
vector<int>G[N];
int head[N];
int s[N];

int ans;

void dfs(int v,int o)
{
    s[v]=1;
    int mx=-1,p=-1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        d[u]=d[v]^a[u];
        dfs(u,v);
        s[v]+=s[u];
    }
}

void dfs2(int v,int o)
{
    int mx=-1,p=-1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        if(s[u]>mx)
        {
            mx=s[u];
            p=u;
        }
    }
    for(auto u:G[v])
    {
        if(u==o) continue;
        if(u==p) head[u]=head[v];
        else head[u]=u;
        dfs2(u,v);
    }
}

set<int>S[N];
bool is[N];

void dfs1(int v,int o)
{
    for(auto u:G[v])
    {
        if(u==o||head[u]==u) continue;
        dfs1(u,v);
    }
    for(auto u:G[v])
    {
        if(u==o||head[u]!=u) continue;
        dfs1(u,v);
    }
    if(S[head[v]].count(d[v]^a[v])) is[v]=1;
    S[head[v]].insert(d[v]);
    if(is[v])
    {
        ans++;
        S[head[v]].clear();
    }
    if(head[v]==v)
    {
        for(auto x:S[v])
        {
            if(S[head[o]].count(x^a[o])) is[o]=1;
        }
        for(auto x:S[v])
        {
            S[head[o]].insert(x);
        }
        S[v].clear();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        head[1]=1;
        dfs(1,0);
        dfs2(1,0);
        dfs1(1,0);
        cout<<ans;
    }

    return 0;
}