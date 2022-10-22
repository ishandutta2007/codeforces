#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

int d[MAXN];
void dfs0(int u,int pre)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v!=pre)d[v]=d[u]+w,dfs0(v,u);
	}
}
struct one
{
	int u,val;
	one(){}
	one(int u,int val):u(u),val(val) {}
};
bool cmp(one a,one b){return a.val>b.val;}
struct LD
{
int dis[MAXN],fa[MAXN],low[MAXN],top[MAXN];
int ff[18][MAXN];
void dfs1(int u)
{
	ff[0][u]=fa[u];
	for(int k=1;k<18;++k)ff[k][u]=ff[k-1][ff[k-1][u]];
	low[u]=u;
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa[u])continue;
		dis[v]=dis[u]+w,fa[v]=u;
		dfs1(v);
		if(dis[low[v]]>dis[low[u]])low[u]=low[v];
	}
}
void dfs2(int u,int now_top)
{
	top[u]=now_top;
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa[u]&&low[v]==low[u])dfs2(v,now_top);
	}
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa[u]&&low[v]!=low[u])dfs2(v,v);
	}
}
int val[MAXN],rk[MAXN],chains;
ll f[MAXN];
one a[MAXN];
void Mark(int u,int ti)
{
	int p=fa[top[u]];
	while(u!=p)rk[u]=ti,u=fa[u];
}
void init(int n,int s)
{
	dfs1(s),dfs2(s,s);
	chains=0;
	for(int u=1;u<=n;++u)
		if(low[u]==u)a[++chains]=one{u,dis[u]-dis[fa[top[u]]]};
	std::sort(a+1,a+chains+1,cmp);
	for(int i=1;i<=chains;++i)f[i]=f[i-1]+a[i].val,Mark(a[i].u,i);
}
ll Query(int x,int y)
{
	if(2*y-1>=chains)return f[chains];
	int t=2*y-1;
	if(rk[x]<=t)return f[t];
	int u=x;
	for(int k=17;k>=0;--k)
		if(ff[k][u]&&rk[ff[k][u]]>t)u=ff[k][u];
	u=fa[u];
	int cur=dis[low[x]]-dis[u];
	return max(f[t-1]+cur,f[t]-dis[low[u]]+dis[u]+cur);
}
}t1,t2;
int main()
{
	int n=read(),m=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		adde(u,v,w),adde(v,u,w);
	}
	dfs0(1,0);
	int s=0;
	for(int u=1;u<=n;++u)
		if(d[u]>d[s])s=u;
	memset(d,0,sizeof d),dfs0(s,0);
	int t=0;
	for(int u=1;u<=n;++u)
		if(d[u]>d[t])t=u;
	t1.init(n,s),t2.init(n,t);
	ll ans=0;
	while(m--)
	{
		int x=(read()+ans-1)%n+1,y=(read()+ans-1)%n+1;
		printf("%lld\n",ans=max(t1.Query(x,y),t2.Query(x,y)));
	}
	return 0;
}