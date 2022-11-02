#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

//#define int long long
#define ll long long
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
ll mod1=998244353;

const bool multi=0;

int DP[5007][5007],sum[5007][5007];
ll f[5007];
vector<int>G[5007];
int n,k;

void dfs(int v,int o)
{
    vector<int>child;
    for(auto u:G[v])
    {
        if(u!=o)
        {
            dfs(u,v);
            child.pb(u);
        }
    }
    child.pb(n+1);
    f[n+1]=1;
    DP[v][0]=1;
    for(auto u:G[v]) if(u!=o) DP[v][0]=(ll)DP[v][0]*(ll)sum[u][k]%mod1;
    for(int i=1;i<=k;i++)
    {
        for(int j=sz(child)-2;j>=0;j--)
        {
            if(i==k) f[child[j]]=f[child[j+1]]*((ll)sum[child[j]][k])%mod1;
            else f[child[j]]=f[child[j+1]]*((ll)sum[child[j]][k]+sum[child[j]][min(k-i-1,i-1)])%mod1;
        }
        ll f1=1;
        for(int j=0;j<sz(child)-1;j++)
        {
            DP[v][i]=((ll)DP[v][i]+(f1*(ll)DP[child[j]][i-1]%mod1*f[child[j+1]]))%mod1;
            if(i==1||i==k) f1=f1*(ll)sum[child[j]][k]%mod1;
            else f1=f1*((ll)sum[child[j]][k]+(ll)sum[child[j]][min(k-i-1,i-2)])%mod1;
        }
    }
    sum[v][0]=DP[v][0];
    for(int i=1;i<=k;i++) sum[v][i]=(sum[v][i-1]+DP[v][i])%mod1;
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
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        cout<<sum[1][k];
    }

    return 0;
}