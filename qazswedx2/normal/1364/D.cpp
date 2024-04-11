#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,k,h[100005],t,a[100005],f[100005],at,ct0,ct1,d[100005];
int q[1000005],head,tail,vis[100005],fl,st[100005],tp,s;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	if(dep%2) ct1++;
	else ct0++;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
void dfs2(int u,int fa)
{
	st[++tp]=u;
	vis[u]=2;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]==1||v==fa) continue;
		if(vis[v]==2)
		{
			for(int i=1;i<=tp;i++)
				if(st[i]==v)
				{
					s=i;
					break;
				}
			fl=1;
			return;
		}
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v]) dfs2(v,u);
		if(fl) return;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		f[u]++,f[v]++;
	}
	if(m==n-1)
	{
		dfs(1,0,0);
		if(ct0>ct1)
		{
			for(int i=1;i<=n;i++)
				if(d[i]%2==0)
					a[++at]=i;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(d[i]%2==1)
					a[++at]=i;
		}
		printf("1\n");
		for(int i=1;i<=(k+1)/2;i++)
			printf("%d ",a[i]);
		return 0;
	}
	head=1,tail=0;
	for(int i=1;i<=n;i++)
		if(f[i]==1)
			q[++tail]=i;
	while(head<=tail)
	{
		int u=q[head];
		head++;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			f[v]--;
			if(f[v]==1) q[++tail]=v;
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dfs2(i,0);
			if(tp-s+1<=k)
			{
				printf("2\n%d\n",tp-s+1);
				for(int i=s;i<=tp;i++)
					printf("%d ",st[i]);
			}
			else
			{
				printf("1\n");
				for(int i=s,j=1;j<=(k+1)/2;i+=2,j++)
					printf("%d ",st[i]);
			}
			return 0;
		}
	return 0;
}