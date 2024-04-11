//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
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
#define MAXN 100011
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}
const ll mod=ll(1e9+7);
ll ans=0,a[MAXN];
void dfs(std::map<ll,ll>& pre,ll u,ll fa=0)
{
    std::map<ll,ll> now;
    for(auto x:pre)now[gcd(x.first,a[u])]+=x.second;
    ++now[a[u]];
    for(auto x:now)ans=(ans+x.first*x.second)%mod;
    for(ll i=last[u];i;i=e[i].nxt)
        if(e[i].v!=fa)dfs(now,e[i].v,u);
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    std::map<ll,ll>pre;
    dfs(pre,1);
    printf("%lld",ans);
    return 0;
}