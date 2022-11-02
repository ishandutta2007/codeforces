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

const bool multi=1;

int l[100007],r[100007];
int DP[100007][2];
vector<int>G[100007];

void dfs(int v,int o)
{
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        DP[v][0]+=max(DP[u][0]+abs(l[v]-l[u]),DP[u][1]+abs(l[v]-r[u]));
        DP[v][1]+=max(DP[u][0]+abs(r[v]-l[u]),DP[u][1]+abs(r[v]-r[u]));
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
        int n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        cout<<max(DP[1][0],DP[1][1])<<endl;
        memset(DP,0,sizeof DP);
        for(int i=1;i<=n;i++) G[i].clear();
    }

    return 0;
}