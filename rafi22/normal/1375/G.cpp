#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>G[200007];
int o[200007];
int DP[200007];
int sum[200007];

void dfs_DP(int v)
{
    for(auto u:G[v])
    {
        if(u==o[v]) continue;
        o[u]=v;
        dfs_DP(u);
        DP[v]+=sum[u];
        sum[v]+=DP[u]+1;
    }
}

void reroot(int v,int u)
{
    DP[v]-=sum[u];
    sum[v]-=DP[u]+1;
    DP[u]+=sum[v];
    sum[u]+=DP[v]+1;
}

int ans=inf;

void dfs_reroot(int v)
{
    ans=min(ans,DP[v]);
    for(auto u:G[v])
    {
        if(u==o[v]) continue;
        reroot(v,u);
        dfs_reroot(u);
    }
    reroot(v,o[v]);
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs_DP(1);
        dfs_reroot(1);
        cout<<ans;
    }

    return 0;
}