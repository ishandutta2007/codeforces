#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,vis,id,nxt;
}e[2000005];
int n,m,h[500005],t=1,e2[500005][3],deg[500005][2];
void add(int u,int v,int w,int id)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].id=id;
	e[t].nxt=h[u];
	h[u]=t;
	e[++t].v=u;
	e[t].w=w^1;
	e[t].id=id;
	e[t].nxt=h[v];
	h[v]=t;
}
void dfs(int u)
{
	for(int &i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(e[i].vis) continue;
	//	printf("dfs:u=%d,v=%d\n",u,v);
		e[i].vis=1,e[i^1].vis=2;
		dfs(v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		deg[u][w-1]++;
		deg[v][w-1]++;
		if(w==1) add(u,v,0,i);
		else add(u+n,v+n,0,i);
		e2[i][0]=u,e2[i][1]=v,e2[i][2]=w;
	}
	int s=2*n+1,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i][0]%2)
		{
			ans++;
			if(deg[i][1]%2) add(i,i+n,0,0);
			else add(i,s,0,0);
		}
		else if(deg[i][1]%2)
			add(i+n,s,0,0);
	}
	for(int i=1;i<=2*n+1;i++)
		dfs(i);
	printf("%d\n",ans);
	for(int i=2;i<=t;i++)
		if(e[i].vis==1&&e[i].id)
			printf("%d",e[i].w+1);
	return 0;
}