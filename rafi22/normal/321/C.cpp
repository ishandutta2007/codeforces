#include <bits/stdc++.h>

//#define int long long
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
vector<int>G[200007];
int s[200007];
bool odw[200007];
char ans[200007];
void dfs(int v,int o)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u!=o&&!odw[u])
        {
            dfs(u,v);
            s[v]+=s[u];
        }
    }
}
void find_centroid(int v,int o,int k,int n)
{

    int nx=-1;
    for(auto u:G[v]) if(u!=o&&!odw[u]&&s[u]>n/2) nx=u;
    if(nx!=-1) find_centroid(nx,v,k,n);
    else
    {
        ans[v]='A'+k;
        odw[v]=1;
        if(o!=-1&&!odw[o]) dfs(o,v);
        for(auto u:G[v]) if(!odw[u]) find_centroid(u,v,k+1,s[u]);
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
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1,-1);
        find_centroid(1,-1,0,n);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

    }

    return 0;
}