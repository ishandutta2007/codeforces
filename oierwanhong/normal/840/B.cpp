//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 300011
std::map<pll,bool>p;
struct edge
{
    ll v,dex,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll dex)
{
    e[++cnt].v=v,e[cnt].dex=dex;
    e[cnt].nxt=last[u],last[u]=cnt;
}
ll fa[MAXN],d[MAXN],all=0,change;
bool vis[MAXN];
void dfs1(ll u)
{
    vis[u]=1;
    if(d[u]==-1)change=u;
    all+=(d[u]==1);
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(vis[v])continue;
        fa[v]=u;
        dfs1(v);
    }
}
std::vector<ll>ans;
void dfs2(ll u)
{
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(fa[v]==u)
        {
            dfs2(v);
            if(d[v]==1){ans.push_back(e[i].dex),d[u]^=1;}
        }
    }
}
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)d[i]=read();
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        if(u>v)std::swap(u,v);
        if(p[pll(u,v)])continue;
        p[pll(u,v)]=1;
        adde(u,v,i),adde(v,u,i);
    }
    dfs1(1);
    if(all&1)
    {
        if(!change){puts("-1");return 0;}
        d[change]=1;
    }
    for(ll i=1;i<=n;++i)
        if(d[i]==-1)d[i]=0;
    dfs2(1);
    printf("%u\n",ans.size());
    for(auto x:ans)printf("%lld\n",x);
    return 0;
}