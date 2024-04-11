#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<pair<int,int>>g[100010];
struct EDGE
{
	int u,v,w;
	friend bool operator <(const EDGE&a,const EDGE&b){return a.w<b.w;}
}edge[100010];
int par[100010],size[100010],ans,n,m,k;
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
void dfs(int p,int fa)
{
	for(auto i:g[p])
	if(i.first!=fa)
	{
		dfs(i.first,p);
		size[p]+=size[i.first];
		if(size[i.first]!=0&&size[i.first]!=k)ans=max(ans,i.second);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){int x;scanf("%d",&x);size[x]=1;}
	for(int i=1;i<=m;i++)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++)par[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a=find(edge[i].u),b=find(edge[i].v);
		if(a!=b)
		{
			par[a]=b;
			g[edge[i].u].push_back({edge[i].v,edge[i].w});
			g[edge[i].v].push_back({edge[i].u,edge[i].w});
		}
	}
	dfs(1,0);
	for(int i=1;i<=k;i++)printf("%d%c",ans," \n"[i==k]);
	return 0;
}