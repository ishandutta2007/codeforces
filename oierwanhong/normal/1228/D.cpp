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
#define MAXN 300011
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;
}
ll c[MAXN],f[4];
bool vis[MAXN];
int main()
{
    ll n=read(),m=read(),num=0;
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    for(ll u=1;u<=n;++u)
        if(!c[u])
        {
            c[u]=++num;
            if(num>3)return puts("-1")&0;
            for(ll i=1;i<=n;++i)vis[i]=0;
            for(ll i=last[u];i;i=e[i].nxt)
                vis[e[i].v]=1;
            for(ll v=1;v<=n;++v)
                if(!vis[v])c[v]=num,++f[num];
        }
        else
        {
            for(ll i=last[u];i;i=e[i].nxt)
                if(c[e[i].v]==c[u])return puts("-1")&0;
        }
        
    if(num<3||f[1]*f[2]+f[1]*f[3]+f[2]*f[3]!=m)puts("-1");
    else
    {
        for(ll i=1;i<=n;++i)printf("%lld ",c[i]);
    }
    return 0;
}