//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
#define MAXN 200011
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN],deg[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;++deg[v];
    e[cnt].nxt=last[u],last[u]=cnt;
}
ll a[4][MAXN],c[MAXN],ans[MAXN];
ll dfs(ll u,ll fa=0)
{
    ll s=a[c[u]][u];
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        c[v]=6-c[u]-c[fa];
        if(c[v]==c[u]||c[v]==c[fa])return INF;
        s+=dfs(v,u);
    }
    return s;
}
int main()
{
    ll n=read(),minv=INF;
    for(ll x=1;x<=3;++x)
        for(ll u=1;u<=n;++u)a[x][u]=read();
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    ll u=0;
    for(ll i=1;i<=n;++i)
        if(deg[i]>2)return puts("-1")&0;
        else if(deg[i]==1)u=i;
    for(ll x=1;x<=3;++x)
        for(ll y=1;y<=3;++y)
        {
            if(x==y)continue;
            ll v=e[last[u]].v,s=a[x][u];
            c[u]=x,c[v]=y;
            s+=dfs(v,u);
            if(umin(minv,s))memcpy(ans,c,sizeof c);
        }
    printf("%lld\n",minv);
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}