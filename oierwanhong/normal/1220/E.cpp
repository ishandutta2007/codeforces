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
const ll INF=1ll<<58;
/**********/
#define MAXN 500011
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

ll w[MAXN],f[MAXN],q[MAXN];
int main()
{
    ll n=read(),m=read(),sum=0;
    for(ll i=1;i<=n;++i)w[i]=read(),sum+=w[i];
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    ll s=read(),h=1,t=1;
    for(ll i=1;i<=n;++i)
        if(i!=s&&deg[i]==1)q[t++]=i;
    while(h<t)
    {
        ll u=q[h++];sum-=w[u];
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            --deg[v];umax(f[v],f[u]+w[u]);
            if(v!=s&&deg[v]==1)q[t++]=v;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;++i)umax(ans,f[i]);
    printf("%lld",ans+sum);
    return 0;
}