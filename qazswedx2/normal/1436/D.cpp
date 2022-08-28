#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int n,h[200005],t,sz[200005];
ll a[200005],ans;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		a[u]+=a[v];
		sz[u]+=sz[v];
	}
	if(!sz[u]) sz[u]++;
	ans=max(ans,(a[u]+sz[u]-1)/sz[u]);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(v,i);
		add(i,v);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}