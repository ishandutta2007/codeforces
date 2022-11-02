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
int k;
vector<pair<int,int>>ans;

void dfs(int v,int o,int s)
{
    int deg=sz(G[v])-1;
    int c=s;
    for(auto u:G[v])
    {
        if(u==o) continue;
        if(c==k)
        {
            c=s-1-deg;
            ans.pb({v,c});
        }
        ans.pb({u,++c});
        dfs(u,v,c);
        deg--;
    }
    if(v!=1&&c!=s-1) ans.pb({v,s-1});
    if(v!=1) ans.pb({o,s});
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
        for(int i=1;i<=n;i++) k=max(k,sz(G[i]));
        ans.pb({1,0});
        dfs(1,0,0);
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}