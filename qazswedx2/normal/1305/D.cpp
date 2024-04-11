#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t,vis[100005],size[100005],son[100005],lf;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa)
{
	size[u]=1;
	son[u]=0;
	int fl=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		size[u]+=size[v];
		fl=1;
		if(size[v]>size[son[u]]) son[u]=v;
	}
	if(!fl) lf=u;
}
void getans(int u)
{
	dfs1(u,0);
	if(size[u]==1)
	{
		printf("! %d\n",u);
		fflush(stdout);
		return;
	}
	u=lf;
	dfs1(u,0);
	vis[u]=1;
	int nw=u;
	while(son[nw])
	{
		nw=son[nw];
		vis[nw]=1;
	}
//	printf("u=%d,nw=%d,size=%d,s=%d\n",u,nw,size[3],son[3]);
	printf("? %d %d\n",u,nw);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	vis[v]=0;
	getans(v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	getans(1);
	return 0;
}