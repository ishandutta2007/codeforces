#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[100005],t,deg[100005],rt,d[100005],f[100005],vis[100005];
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
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
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
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]>1)
		{
			rt=i;
			break;
		}
	dfs(rt,0,0);
	int ans1=1,ans2=n-1,fl=-1;
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
		{
			if(vis[f[i]]) ans2--;
			vis[f[i]]=1;
			if(fl==-1) fl=d[i]%2;
			else if(fl!=d[i]%2) ans1=3;
		}
	printf("%d %d",ans1,ans2);
	return 0;
}