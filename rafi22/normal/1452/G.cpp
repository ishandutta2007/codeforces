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

int d[200007];
int ans[200007];
vector<int>G[200007];
int s[200007];
bool odw[200007];
int act[200007];

void dfs_sz(int v,int o)
{
    s[v]=1;
    for(auto u:G[v])
    {
        if(u==o||odw[u]) continue;
        dfs_sz(u,v);
        s[v]+=s[u];
    }
}
void dfs(int v,int o,int g,int n)
{
    if(d[v]>g) act[min(n,d[v]-g-1)]=max(act[min(n,d[v]-g-1)],d[v]);
    for(auto u:G[v])
    {
        if(u==o||odw[u]) continue;
        dfs(u,v,g+1,n);
    }
}
void dfs1(int v,int o,int g)
{
    ans[v]=max(ans[v],act[g]);
    for(auto u:G[v])
    {
        if(u==o||odw[u]) continue;
        dfs1(u,v,g+1);
    }
}

void centroid(int v,int o,int n)
{
    int nx=-1;
    for(auto u:G[v])
    {
        if(u==o||odw[u]) continue;
        if(s[u]>n/2) nx=u;
    }
    if(nx!=-1)
    {
        centroid(nx,v,n);
        return ;
    }
   // cout<<v<<endl;
    odw[v]=1;
    for(auto u:G[v]) if(!odw[u]) dfs_sz(u,v);
    for(auto u:G[v]) if(!odw[u]) dfs(u,v,1,n);
    if(d[v]>0) act[min(n,d[v]-1)]=max(act[min(n,d[v]-1)],d[v]);
    for(int i=n;i>=0;i--) act[i]=max(act[i],act[i+1]);
    for(auto u:G[v]) if(!odw[u]) dfs1(u,v,1);
    ans[v]=max(ans[v],act[0]);
    for(int i=0;i<=n;i++) act[i]=0;
    for(auto u:G[v]) if(!odw[u]) centroid(u,v,s[u]);
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
        int n,a,b,k;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++) d[i]=-1;
        cin>>k;
        deque<int>Q;
        while(k--)
        {
            cin>>a;
            d[a]=0;
            Q.pb(a);
        }
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            for(auto u:G[v])
            {
                if(d[u]==-1)
                {
                    d[u]=d[v]+1;
                    Q.pb(u);
                }
            }
        }
        for(int i=1;i<=n;i++) ans[i]=d[i];
        dfs_sz(1,0);
        centroid(1,0,n);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}