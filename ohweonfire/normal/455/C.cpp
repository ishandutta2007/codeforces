#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=300005;
int f[maxn],d[maxn],n,m,q,x,y,qtype,dep[maxn];
vector<int> g[maxn];
int dfs(int x,int d,int f)
{
	dep[x]=d;
	int ans=x;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=f)
		{
			int t=dfs(g[x][i],d+1,x);
			if(dep[ans]<dep[t])ans=t;
		}
	return ans;
}
int calc(int x)
{
	int t=dfs(x,0,0);
	return dep[dfs(t,0,0)];
}
int find(int u)
{
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
void merge(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v)
		return;
	f[u]=v;
	d[v]=max(max(d[u],d[v]),(d[u]+1)/2+(d[v]+1)/2+1);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		merge(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++)
		if(f[i]==i)
			d[i]=calc(i);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&qtype,&x);
		if(qtype==1)
		{
			x=find(x);
			printf("%d\n",d[x]);
		}
		else
		{
			scanf("%d",&y);
			merge(x,y);
		}
	}
	return 0;
}