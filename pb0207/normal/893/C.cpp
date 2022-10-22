#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

int n,m,w[N],fa[N],mn[N],vis[N];

long long ans;

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&mn[i]),fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu==fv)
			continue;
		fa[fv]=fu;
		mn[fu]=min(mn[fu],mn[fv]);
	}
	for(int i=1;i<=n;i++)
	{
		int f=find(i);
		if(!vis[f])
			ans+=mn[f],vis[f]=1;
	}
	printf("%lld",ans);
}