#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[200005],t,f[200005][20],g[200005][20];
int deg[200005],vis[200005],sz[200005],lg[200005],rt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
inline int lowbit(int x)
{
	return x&-x;
}
void dfs2(int u,int fa)
{
	if(sz[u]==1)
	{
		f[u][1]=1;
		return;
	}
	int fnw=-1,gnw=-1,fl1=0,fl2=0;
	if(lowbit(sz[u]+1)==sz[u]+1) fnw=lg[sz[u]+1];
	if(lowbit((1<<m)-sz[u])==(1<<m)-sz[u]) gnw=lg[(1<<m)-sz[u]];
	if(fnw!=-1) f[u][fnw]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		if(fnw!=-1)
			f[u][fnw]&=f[v][fnw-1];
		if(gnw!=-1)
		{
			if(f[v][gnw]) fl2=1;
			if(g[v][gnw+1]) fl1=1;
			if(deg[u]==2&&f[v][m-1]) fl1=fl2=1;
		}
	}
	if(gnw!=-1&&fl1&&fl2) g[u][gnw]=1;
}
void dfs3(int u,int fa)
{
	int mx=n-sz[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u);
		mx=max(mx,sz[v]);
	}
	if(mx<=n/2) rt=u;
}
int main()
{
	for(int i=0;i<=17;i++)
		lg[1<<i]=i;
	scanf("%d",&m);
	n=(1<<m)-2;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		deg[u]++,deg[v]++;
	}
	if(m==2)
	{
		printf("2\n1 2\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]>4)
		{
			printf("0\n");
			return 0;
		}
		vis[deg[i]]++;
	}
	if(vis[2]>2)
	{
		printf("0\n");
		return 0;
	}
	if(vis[2]==2)
	{
		dfs(1,0);
		for(int i=1;i<=n;i++)
			if(deg[i]==2)
			{
				int fl=0;
				for(int j=h[i];j;j=e[j].nxt)
				{
					int v=e[j].v;
					if(sz[v]==1) fl=1;
				}
				if(fl) rt=i;
			}
		//printf("rt=%d\n",rt);
		if(!rt)
		{
			printf("0\n");
			return 0;
		}
		dfs(rt,0);
		dfs2(rt,0);
	/*	for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(f[i][j]) printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
				if(g[i][j]) printf("i=%d,j=%d,g=%d\n",i,j,g[i][j]);*/
		for(int i=h[rt];i;i=e[i].nxt)
		{
			int v=e[i].v;
		//	printf("v=%d,g=%d\n",v,g[v][2]);
			if(sz[v]==1) continue;
			if(g[v][2])
			{
				printf("1\n%d\n",rt);
				return 0;
			}
		}
		printf("0\n");
	}
	else if(vis[4])
	{
		if(vis[4]!=1)
		{
			printf("0\n");
			return 0;
		}
		int rt=0,mn=1e9,k;
		for(int i=1;i<=n;i++)
			if(deg[i]==4)
				rt=i;
		dfs(rt,0);
		dfs2(rt,0);
		for(int i=h[rt];i;i=e[i].nxt)
		{
			int v=e[i].v;
			mn=min(mn,sz[v]);
		}
		if(lowbit(mn+1)!=mn+1)
		{
			printf("0\n");
			return 0;
		}
		k=lg[mn+1];
		int ct1=0,ct2=0,ct3=0;
		for(int i=h[rt];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(g[v][k+2]) ct1++;
			if(f[v][k+1]) ct2++;
			if(f[v][k]) ct3++;
		}
	//	printf("k=%d,ct=%d,%d,%d\n",k,ct1,ct2,ct3);
		if(ct1==1&&ct2==1&&ct3==2)
			printf("1\n%d\n",rt);
		else printf("0\n");
	}
	else
	{
	//	printf("---\n");
		if(vis[2])
		{
			printf("0\n");
			return 0;
		}
		dfs(1,0);
		dfs3(1,0);
		dfs(rt,0);
		dfs2(rt,0);
		int mn=1e9;
		for(int i=h[rt];i;i=e[i].nxt)
		{
			int v=e[i].v;
			mn=min(mn,sz[v]);
		}
		if(lowbit(mn+1)!=mn+1)
		{
			printf("0\n");
			return 0;
		}
		int ct1=0,ct2=0,vv=0,k;
		k=lg[mn+1];
		for(int i=h[rt];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(f[v][k+1])
			{
				ct1++;
				vv=v;
			}
			if(f[v][k]) ct2++;
		}
		if(ct1==1&&ct2==2)
			printf("2\n%d %d\n",min(vv,rt),max(vv,rt));
		else printf("0\n");
	}
	return 0;
}