#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,m,h[500005],t,vis[500005],f[500005],fl;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int st[1000005],tp;
void print(int u,int v)
{
	printf("Possible\n");
	tp=0;
	int nw=u;
	st[++tp]=v;
	while(nw)
	{
		st[++tp]=nw;
		nw=f[nw];
	}
	printf("%d\n",tp);
	for(int i=tp;i>0;i--)
		printf("%d ",st[i]);
	printf("\n");
	tp=0;
	nw=v;
	while(nw)
	{
		st[++tp]=nw;
		nw=f[nw];
	}
	printf("%d\n",tp);
	for(int i=tp;i>0;i--)
		printf("%d ",st[i]);
	printf("\n");
}
int s;
void dfs(int u,int fa,int c)
{
	vis[u]=c;
	f[u]=fa;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v])
		{
			if(vis[v]==c) continue;
			print(u,v);
			fl=1;
			return;
		}
		if(v==s) continue;
		dfs(v,u,c);
		if(fl) return;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	int ct=0;
	for(int i=h[s];i;i=e[i].nxt)
	{
		int v=e[i].v;
		ct++;
		if(vis[v])
		{
			print(s,v);
			fl=1;
			break;
		}
		dfs(v,s,ct);
		if(fl) break;
	}
	if(!fl) printf("Impossible\n");
	return 0;
}