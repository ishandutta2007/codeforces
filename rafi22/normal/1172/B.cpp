#include <bits/stdc++.h>

#define int long long
#define double long double
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

int DP[200007];
int fac[200007];
vector<int>G[200007];

void dfs(int v,int o)
{
    DP[v]=fac[sz(G[v])];
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        DP[v]=DP[v]*DP[u]%mod;
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
        mod=mod1;
        int n,a,b;
        cin>>n;
        fac[0]=1;
        for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        cout<<n*DP[1]%mod;
    }

    return 0;
}