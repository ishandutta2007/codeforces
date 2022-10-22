//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
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
const ll INF=ll(2e9);
ll dep[MAXN],size[MAXN],a[MAXN];
bool cmp(ll x,ll y)
{
    return dep[x]-size[x]>dep[y]-size[y];
}
void dfs(ll u,ll fa=0)
{
    size[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        size[u]+=size[v];
    }
}
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)a[i]=i;
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    dep[1]=1;
    dfs(1);
    std::sort(a+1,a+n+1,cmp);
    ll ans=0;
    for(ll i=1;i<=m;++i)ans+=dep[a[i]]-size[a[i]];
    std::cout<<ans;
}