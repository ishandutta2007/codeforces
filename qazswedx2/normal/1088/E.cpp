#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[2000005];
int n,a[1000005],h[1000005],t,ct;
ll mx=-1e9-100,f[1000005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u]=a[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		f[u]+=max(0ll,f[v]);
	}
	mx=max(mx,f[u]);
}
void dfs2(int u,int fa)
{
	f[u]=a[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		f[u]+=max(0ll,f[v]);
	}
	if(f[u]==mx)
	{
		ct++;
		f[u]=-1e18;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	printf("%lld %d\n",ct*mx,ct);
	return 0;
}