#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,w,nxt;
}e[1000005];
int tt,n,h[500005],size[500005],t;
ll ans1=0,ans2=0;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int ww)
{
	size[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,e[i].w);
		size[u]+=size[v];
	}
	ans2+=1ll*ww*min(size[u],n-size[u]);
	ans1+=1ll*ww*(size[u]%2);
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		ans1=ans2=0;
		t=0;
		scanf("%d",&n);
		n*=2;
		for(int i=1;i<=n;i++)
			h[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dfs(1,0,0);
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}