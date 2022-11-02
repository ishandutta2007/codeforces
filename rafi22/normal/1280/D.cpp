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
ll inf=1000000000000000007;
ll mod=1000000007;
ll mod1=998244353;

const bool multi=1;

vector<pair<int,ll>>DP[3007];
vector<int>G[3007];
ll w[3007];

vector<pair<int,ll>>scal(vector<pair<int,ll>> a,vector<pair<int,ll>>b)
{
    vector<pair<int,ll>>ne(a.size()+b.size(),{0,-inf});
    for(int i=0;i<sz(a);i++)
    {
        for(int j=0;j<sz(b);j++)
        {
            ne[i+j]=max(ne[i+j],{a[i].st+b[j].st,a[i].nd+b[j].nd});
            ne[i+j+1]=max(ne[i+j+1],{a[i].st+b[j].st+(b[j].nd>0),a[i].nd});
        }
    }
    return ne;
}

void dfs(int v,int o)
{
    DP[v].pb({0,w[v]});
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v);
        DP[v]=scal(DP[v],DP[u]);
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            DP[i].clear();
            G[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
            w[i]=-w[i];
        }
        ll x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            w[i]+=x;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1,0);
        cout<<DP[1][m-1].st+(DP[1][m-1].nd>0)<<endl;
    }

    return 0;
}