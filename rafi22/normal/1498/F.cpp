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

vector<int>G[100007];
int a[100007];
int x[100007][40];
int root[100007][40];
int tmp[40];
int n,k;

void dfs(int v,int o,int d)
{
    x[v][0]^=a[v];
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v,d+1);
        for(int j=0;j<2*k;j++) x[v][(j+1)%(2*k)]^=x[u][j];
    }
}
void dfs1(int v,int o)
{
    for(auto u:G[v])
    {
        if(u==o) continue;
        for(int j=0;j<2*k;j++) tmp[j]=root[v][j];
        for(int j=0;j<2*k;j++) tmp[(j+1)%(2*k)]^=x[u][j];
        for(int j=0;j<2*k;j++) root[u][(j+1)%(2*k)]^=tmp[j];
        for(int j=0;j<2*k;j++) root[u][j]^=x[u][j];
        dfs1(u,v);
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
        int u,v;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(1,-1,0);
        for(int j=0;j<2*k;j++) root[1][j]=x[1][j];
        dfs1(1,-1);
        for(int i=1;i<=n;i++)
        {
            int XOR=0;
            for(int j=k;j<2*k;j++) XOR^=root[i][j];
            if(XOR==0) cout<<0<<" ";
            else cout<<1<<" ";
        }
    }

    return 0;
}