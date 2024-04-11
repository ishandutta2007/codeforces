#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,INF=0x7fffffff;

struct node{
	int ne,to;
}edg[N*2+1];

int n,head[N],cnt,w[N];

ll f[N],g[N],size[N];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int fa)
{
	size[i]=w[i];
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		dfs(v,i);
		size[i]+=size[v];
	}
	f[i]=-INF;
	g[i]=size[i];
	ll mx=-INF;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		if(mx!=-INF)
			f[i]=max(f[i],mx+g[v]);
		mx=max(mx,g[v]);
		g[i]=max(g[i],g[v]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	dfs(1,0);
	ll ans=-INF;
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	if(ans==-INF)
		printf("Impossible");
	else
		printf("%I64d",ans);
}