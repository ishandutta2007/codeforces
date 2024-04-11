#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int tt,n,m,h[500005],t,d[500005],f[500005],vis[500005];
int a[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	f[u]=fa;
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs(v,u,dep+1);
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			h[i]=vis[i]=a[i]=0;
		t=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1,0,1);
		int id=0;
		for(int i=1;i<=n;i++)
			if(d[i]>(n+1)/2)
			{
				id=i;
				break;
			}
		if(id)
		{
			printf("PATH\n");
			printf("%d\n",d[id]);
			int u=id;
			while(u)
			{
				printf("%d ",u);
				u=f[u];
			}
			printf("\n");
			continue;
		}
		printf("PAIRING\n");
		printf("%d\n",(n+3)/4);
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			if(!a[d[i]]) a[d[i]]=i;
			else
			{
				printf("%d %d\n",a[d[i]],i);
				a[d[i]]=0;
				ct++;
				if(ct==(n+3)/4) break;
			}
		}
	}
	return 0;
}