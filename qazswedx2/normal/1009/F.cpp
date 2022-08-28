#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
int n,tans[1000005],a[1000005],*p,*f[1000005],d[1000005],sd[1000005];
int h[1000005],son[1000005],t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=sd[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		sd[u]=max(sd[u],sd[v]);
		if(sd[v]>sd[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int fa)
{
	//printf("u=%d,fa=%d\n",u,fa);
	if(son[u])
	{
		f[son[u]]=f[u]+1;
		dfs2(son[u],u);
		tans[u]=tans[son[u]]+1;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||v==son[u]) continue;
		f[v]=p;
		p+=sd[v]-d[v]+1;
		dfs2(v,u);
		for(int j=0;j<=sd[v]-d[v];j++)
		{
			f[u][j+1]+=f[v][j];
			if(f[u][tans[u]]<f[u][j+1]||(f[u][tans[u]]==f[u][j+1]&&tans[u]>j+1))
				tans[u]=j+1;
		}
	}
	if(f[u][tans[u]]==1) tans[u]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		a[i]=1;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	f[1]=a;
	p=a+sd[1];
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",tans[i]);
	return 0;
}