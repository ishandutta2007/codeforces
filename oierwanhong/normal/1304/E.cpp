//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 100011
struct Edge
{
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll fa[MAXN],size[MAXN],mson[MAXN],dep[MAXN];
void dfs1(ll u,ll now=1)
{
	dep[u]=now;
	size[u]=1;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v,now+1);
		size[u]+=size[v];
		if(size[v]>size[mson[u]])mson[u]=v;
	}
}
ll top[MAXN];
void dfs2(ll u,ll cur)
{
	top[u]=cur;
	if(mson[u])dfs2(mson[u],cur);
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa[u]||v==mson[u])continue;
		dfs2(v,v);
	}
}
ll LCA(ll u,ll v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	}
	if(dep[u]>dep[v])return v;
	else return u;
}
ll dist(ll u,ll v)
{
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

int main()
{
	ll n=read();
	for(ll i=1;i<n;++i)
	{
		ll u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs1(1),dfs2(1,1);
	ll task=read();
	while(task--)
	{
		ll x=read(),y=read(),a=read(),b=read(),k=read();
		ll d=dist(a,b);
		if(k>=d&&(k-d)%2==0)
		{
			puts("YES");continue;
		}
		d=min(dist(a,x)+dist(b,y),dist(a,y)+dist(b,x))+1;
		if(k>=d&&(k-d)%2==0)puts("YES");
		else puts("NO");
	}
	return 0;
}