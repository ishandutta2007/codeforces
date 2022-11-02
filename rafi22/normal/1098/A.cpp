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

vector<int>G[200007];
int s[200007];
int p[200007];
int ans=0;
bool good=1;

void dfs(int v)
{
    if(v==1) ans+=s[v];
    int mn=inf;
    for(auto u:G[v])
    {
        dfs(u);
        if(s[v]==-1) mn=min(mn,s[u]-s[p[v]]);
    }
    if(s[v]==-1&&sz(G[v])>0)
    {
        if(mn<0) good=0;
        ans+=mn;
        for(auto u:G[v]) ans+=s[u]-s[p[v]]-mn;
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
        for(int i=2;i<=n;i++)
        {
            cin>>p[i];
            G[p[i]].pb(i);
        }
        for(int i=1;i<=n;i++) cin>>s[i];
        dfs(1);
        if(good) cout<<ans;
        else cout<<-1;
    }

    return 0;
}