#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[500005];
int n,a[200005],h[200005],t,rt,size[200005],vis[200005],id;
double ans,p[200005],nans,tans=1e50;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa)
{
	size[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		size[u]+=size[v];
	}
}
void dfs2(int u,int fa,int sz)
{
	int mx=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,sz);
		mx=max(mx,size[v]);
	}
	mx=max(mx,sz-size[u]);
	if(mx<=sz/2) rt=u;
}
void dfs3(int u,int fa,int dep)
{
	ans+=1.5*a[u]*sqrt(dep);
	nans+=1.0*dep*a[u]*sqrt(dep);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u,dep+e[i].w);
	}
}
void dfz(int u)
{
	dfs1(u,0);
	dfs2(u,0,size[u]);
	vis[rt]=1;
	double sum=0;
	nans=0;
	for(int i=h[rt];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		ans=0;
		dfs3(v,rt,w);
		p[v]=ans;
		sum+=ans;
	}
	if(tans>nans) tans=nans,id=rt; 
	for(int i=h[rt];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v]&&sum-2*p[v]<0)
			dfz(v);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfz(1);
	printf("%d %.10f",id,tans);
	return 0;
}