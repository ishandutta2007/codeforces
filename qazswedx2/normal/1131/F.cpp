#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[600005];
int n,f[300005],h[300005],cnt,t=0;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	add(x,y);
	add(y,x);
}
void dfs(int u,int fa)
{
	if(u<=n) printf("%d ",u);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	cnt=n;
	for(int i=1;i<=2*n-1;i++)
		f[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cnt++;
		link(x,cnt);
		link(y,cnt);
	}
	dfs(2*n-1,0);
	return 0;
}