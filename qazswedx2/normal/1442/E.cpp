#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005];
int tt,n,a[500005],h[500005],t,mx,id;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep,int cur)
{
	if(dep>mx)
	{
		mx=dep;
		id=u;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+(a[v]!=cur&&a[v]&&cur),a[v]?a[v]:cur);
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		t=0;
		for(int i=1;i<=n;i++)
			h[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int nw=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=0)
				nw=i;
		mx=-1;
		dfs(nw,0,0,a[nw]);
		mx=-1;
		dfs(id,0,0,a[id]);
		printf("%d\n",(mx+1)/2+1);
	}
	return 0;
}