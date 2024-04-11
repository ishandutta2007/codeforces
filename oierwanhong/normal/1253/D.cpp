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
/**********/
#define MAXN 200011
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
ll maxv=0;bool vis[MAXN];
void dfs(ll u)
{
    umax(maxv,u);vis[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
        if(!vis[e[i].v])dfs(e[i].v);
}
int main()
{
    ll n=read(),m=read(),ans=0;
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    for(ll i=1;i<=n;++i)
        if(!vis[i])
        {
            if(i<maxv)++ans;
            dfs(i);
        }
    printf("%lld",ans);
    return 0;
}