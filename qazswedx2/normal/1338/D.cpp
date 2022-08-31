#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],f[100005][2],ans,t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u][0]=0,f[u][1]=1;
	int ct=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		ct++;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		ans=max(ans,f[u][1]+f[v][0]);
		ans=max(ans,f[u][0]+max(f[v][1],f[v][0])+(u!=1?ct-1:ct-2));
		f[u][0]=max(f[u][0],max(f[v][1],f[v][0]));
		f[u][1]=max(f[u][1],f[v][0]+1);
	}
	if(ct) f[u][0]+=ct-1;
	//printf("u=%d,f=%d,%d\n",u,f[u][0],f[u][1]);
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
	dfs(1,0);
	printf("%d",ans);
	return 0;
}