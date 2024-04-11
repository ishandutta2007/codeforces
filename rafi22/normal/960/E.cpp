#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int val[200007];
int odd[200007];
int even[200007];
bool odw[200007];
bool odw1[200007];
int s[200007];
vector<int>G[200007];
int ans,n,a,b;
void dfs(int v)
{
    odw[v]=1;
    s[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            dfs(u);
            odd[v]+=even[u]+1;
            even[v]+=odd[u];
            s[v]+=s[u];
        }
    }
}
void dfs1(int v,int o,int e)
{
    odw1[v]=1;
    int cnt=n+e*s[v]-o*s[v];
    cnt%=mod;
    for(auto u:G[v])
    {
        if(!odw1[u])
        {
            cnt+=odd[u]*(n-s[u])-(even[u]+1)*(n-s[u]);
            cnt%=mod;
        }

    }
    ans+=(cnt*val[v])%mod;
    ans=(ans+mod)%mod;
    for(auto u:G[v])
    {
        if(!odw1[u]) dfs1(u,e+even[v]-odd[u]+1,o+odd[v]-even[u]-1);
    }
}

int ile[10];

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

        cin>>n;
        for(int i=1;i<=n;i++) cin>>val[i];
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1);
        dfs1(1,0,0);
        cout<<ans;
    }

    return 0;
}