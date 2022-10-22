//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1011
const ll L=2520;
std::vector<ll>g[MAXN];
ll tim[MAXN][L+11],f[MAXN][L+11],top=0,cur=0;
ll n,w[MAXN],dfn[MAXN];
ll upd(ll x){return (x%L+L)%L;}
ll mdfs(ll u,ll x)
{
    if(f[u][x])return f[u][x];
    if(tim[u][x])
    {
        ll cnt=0;
        for(ll i=1;i<=n;++i)cnt+=(dfn[i]>=tim[u][x]);
        return f[u][x]=cnt;
    }
    tim[u][x]=dfn[u]=++cur;
    return f[u][x]=mdfs(g[u][upd(x+w[u])%g[u].size()],upd(x+w[u]));
}
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)w[i]=read();
    for(ll i=1;i<=n;++i)
    {
        ll len=read();
        while(len--)g[i].push_back(read());
    }
    ll t=read();
    while(t--)
    {
        ll u=read(),x=read();
        printf("%lld\n",mdfs(u,upd(x)));
    }
    return 0;
}