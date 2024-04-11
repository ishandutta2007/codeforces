//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 2011
ll n;
struct Tree
{
    struct edge
    {
        ll v,nxt;
    }e[MAXN];
    ll cnt=0,last[MAXN];
    void adde(ll u,ll v)
    {
        e[++cnt].v=v;
        e[cnt].nxt=last[u],last[u]=cnt;
    }
    ll lca[MAXN][MAXN],dep[MAXN];
    std::vector<ll> dfs(ll u)
    {
        std::vector<ll>a,b;
        a.push_back(u);lca[u][u]=u;
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            dep[v]=dep[u]+1;
            b=dfs(v);
            for(auto x:a)
                for(auto y:b)lca[x][y]=lca[y][x]=u;
            for(auto y:b)a.push_back(y);
        }
        return a;
    }
    ll LCA(ll u,ll v){return !u||!v?1:lca[u][v];}
    ll a[MAXN],w[MAXN][MAXN];
    void init()
    {
        ll m=read();
        for(ll i=2;i<=m;++i)adde(read(),i);
        dfs(1);
        for(ll i=1;i<=n;++i)a[i]=read();
        for(ll i=1;i<=n;++i)
            for(ll j=i;j<=n;++j)
            {
                ll p1=LCA(a[j],a[i-1]),p2=LCA(a[j],a[j+1]);
                w[i][j]=w[i][j-1]+dep[a[j]]-max(dep[p1],dep[p2]);
            }
    }
}t[2];
ll f[MAXN];
int main()
{
    n=read();
    t[0].init(),t[1].init();
    for(ll i=1;i<=n;++i)
    {
        f[i]=0;
        for(ll j=0;j<i;++j)umax(f[i],f[j]+max(t[0].w[j+1][i],t[1].w[j+1][i]));
    }
    printf("%lld",f[n]);
    return 0;
}