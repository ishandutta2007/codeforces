#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005];
int tt,n,m,a,b,h[500005],t,vis[500005][2];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fl)
{
	vis[u][fl]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v][fl]||v==a||v==b) continue;
		dfs(v,fl);
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		t=0;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=n;i++)
			h[i]=vis[i][0]=vis[i][1]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(a,0);
		dfs(b,1);
		int cta=0,ctb=0;
		for(int i=1;i<=n;i++)
			if(i!=a&&i!=b&&vis[i][0]&&!vis[i][1])
				cta++;	
			else if(i!=a&&i!=b&&!vis[i][0]&&vis[i][1])
				ctb++;
		printf("%I64d\n",1ll*cta*ctb);
	}
	return 0;
}