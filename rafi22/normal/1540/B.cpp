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

vector<int>G[207];
int pre[207],c;
int post[207];
int id[207];
int lca[207][207];
int DP[207][207];
int d[207];

void dfs(int v,int o)
{
    pre[v]=++c;
    id[c]=v;
    for(auto u:G[v])
    {
        if(u==o) continue;
        d[u]=d[v]+1;
        dfs(u,v);
    }
    post[v]=c;
    for(int i=pre[v];i<=post[v];i++) lca[pre[v]][i]=pre[v];
    for(auto u:G[v])
    {
        if(u==o) continue;
        for(int i=pre[u];i<=post[u];i++)
        {
            for(int j=pre[v];j<pre[u];j++) lca[i][j]=pre[v];
            for(int j=post[u]+1;j<=post[v];j++) lca[i][j]=pre[v];
        }
    }
}

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

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
        for(int i=1;i<=n;i++) DP[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                DP[i][j]=(DP[i-1][j]+DP[i][j-1])*pot(2,mod-2)%mod;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            c=0;
            dfs(i,-1);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(id[i]<id[j]) continue;
                    int l=lca[i][j];
                    ans=(ans+DP[d[id[j]]-d[id[l]]][d[id[i]]-d[id[l]]])%mod;
                }
            }
        }
        ans=ans*pot(n,mod-2)%mod;
        cout<<ans;
    }

    return 0;
}