#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[5000005];
int T,n,deg[1000005],vis[1000005],d[1000005],h[1000005],t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=0;
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			deg[i]=d[i]=h[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			deg[u]++,deg[v]++;
			add(u,v);
			add(v,u);
		}
		dfs(1,0,1);
		for(int i=1;i<=n;i++)
		{
			int nw=deg[i];
			if(d[i]%2) nw=-nw;
			printf("%d ",nw);
		}
		printf("\n");
	/*	for(int i=1;i<=n;i++)
			vis[deg[i]]++;
		int nw=1;
		while(vis[nw]) nw++;*/
		
	}
	return 0;
}