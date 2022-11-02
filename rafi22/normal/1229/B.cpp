#include <bits/stdc++.h>

#define int long long
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

vector<int>G[100007];
int a[100007];
vector<pair<int,int>>V[100007];
int ans;

void dfs(int v,int o)
{
    V[o].pb({a[v],1});
    for(auto x:V[o])
    {
        int g=__gcd(a[v],x.st);
        if(sz(V[v])==0||V[v].back().st!=g) V[v].pb({g,x.nd});
        else V[v].back().nd+=x.nd;
    }
    V[o].pop_back();
    for(auto x:V[v]) ans=(ans+x.st*x.nd)%mod;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
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
        int n,x,y;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
        {
            cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
        dfs(1,0);
        cout<<ans;
    }

    return 0;
}