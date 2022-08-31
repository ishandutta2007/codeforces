#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,id,nxt;
}e[5000005];
int T,n,h[1000005],t,deg[1000005],tans[1000005];
void add(int u,int v,int id)
{
	e[++t].v=v;
	e[t].id=id;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int w)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		tans[e[i].id]=w+2;
		dfs(v,u,w^1);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t=0;
		for(int i=0;i<=n+1;i++)
			h[i]=deg[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v,i);
			add(v,u,i);
			deg[u]++,deg[v]++;
		}
		int fl=1;
		for(int i=1;i<=n;i++)
			if(deg[i]>=3)
				fl=0;
		if(!fl)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(deg[i]==1)
			{
				dfs(i,0,0);
				break;
			}
		for(int i=1;i<n;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}