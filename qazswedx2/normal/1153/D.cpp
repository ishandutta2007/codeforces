#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 99999999
struct edge
{
	int v,nxt;
}e[2000005];
int g[500005],a[500005],h[500005],size[500005],n,t=0;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
} 
void dfs(int u,int fa)
{
	int fl=0,ans;
	g[u]=0;
	size[u]=0;
	if(a[u]==1) ans=inf;
	else ans=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		fl=1;
		size[u]+=size[v];
		if(a[u]) ans=min(ans,g[v]);
		else ans=ans+g[v];
	}
	if(!fl) size[u]=g[u]=1;
	else g[u]=ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(v,i);
		add(i,v);
	}
	dfs(1,0);
	printf("%d",size[1]-g[1]+1);
	return 0;
}