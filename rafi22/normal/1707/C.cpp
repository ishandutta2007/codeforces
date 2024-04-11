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

const int N=100007;

int r[N];
void Union(int u,int v)
{
    r[u]=v;
}
int Find(int v)
{
    if(r[v]==v) return v;
    return r[v]=Find(r[v]);
}

vector<int>G[N],G1[N];
int pre[N],post[N],id[N],c;

void dfs(int v,int o)
{
    pre[v]=++c;
    id[c]=v;
    for(auto u:G[v])
    {
        if(u!=o)
        {
            dfs(u,v);
            G1[v].pb(u);
        }
    }
    post[v]=c;
}
bool ans[N];

set<int>S;
void del(int l,int r)
{
    while(true)
    {
        int x=*S.lower_bound(l);
        if(x>r) break;
        S.erase(x);
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
        for(int i=1;i<=n;i++) r[i]=i;
        vector<pair<int,int>>Q;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            if(Find(u)!=Find(v))
            {
                G[u].pb(v);
                G[v].pb(u);
                Union(Find(u),Find(v));
            }
            else Q.pb({u,v});
        }
        dfs(1,0);
        for(int i=1;i<=n+1;i++) S.insert(i);
        for(auto x:Q)
        {
            int u=x.st,v=x.nd;
            if(pre[v]<=pre[u]) swap(u,v);
            if((pre[u]<=pre[v]&&post[u]>=post[v]))
            {
                int l=0,r=sz(G1[u])-1,sr,k;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    int x=G1[u][sr];
                    if(post[x]<pre[v]) l=sr+1;
                    else if(pre[x]>pre[v]) r=sr-1;
                    else
                    {
                        k=x;
                        break;
                    }
                }
                del(pre[k],pre[v]-1);
                del(post[v]+1,post[k]);
            }
            else
            {
                del(1,pre[u]-1);
                del(post[u]+1,pre[v]-1);
                del(post[v]+1,n);
            }
        }
        for(auto x:S) ans[id[x]]=1;
        for(int i=1;i<=n;i++) cout<<ans[i];
    }

    return 0;
}