//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
const ll INF=1ll<<28;
/**********/
#define MAXN 200011
struct edge
{
    ll v,nxt;
}e[MAXN];
ll cnt=0,last[MAXN],deg[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;++deg[v];
    e[cnt].nxt=last[u],last[u]=cnt;
}

ll q[MAXN],n,m;
bool topo()
{
    ll h=1,t=1;
    for(ll i=1;i<=n;++i)
        if(!deg[i])q[t++]=i;
    while(h<t)
    {
        ll u=q[h++];
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(!--deg[v])q[t++]=v;
        }
    }
    return h>n;
}
ll ans[MAXN];
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v);
    }
    if(topo())
    {
        puts("1");
        for(ll i=1;i<=m;++i)printf("1 ");
    }
    else
    {
        puts("2");
        for(ll u=1;u<=n;++u)
            for(ll i=last[u];i;i=e[i].nxt)
                ans[i]=(u<e[i].v?1:2);
        for(ll i=1;i<=m;++i)printf("%lld ",ans[i]);
    }
    return 0;
}