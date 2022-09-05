#include<bits/stdc++.h>
using namespace std;

vector<int> v[2010];
int rt,n,fa[2010],ans[2010],siz[2010],c[2010];

void add(int x,int V,int vv)
{
	if (ans[x]>=V) ans[x]+=vv;
	for (int i=0,sz=v[x].size(); i<sz; i++)add(v[x][i],V,vv);
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=0,sz=v[x].size(); i<sz; i++) 
	{
		dfs(v[x][i]);
		add(v[x][i],0,siz[x]-1);
		siz[x]+=siz[v[x][i]];
	}
	if (siz[x]-1<c[x]) puts("NO"),exit(0);
	ans[x]=-1;
	add(x,c[x]+1,1);
	ans[x]=c[x]+1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d",&fa[i],&c[i]);
		if (!fa[i]) rt=i; else v[fa[i]].push_back(i);
	}
	dfs(rt);
	puts("YES");
	for (int i=1; i<=n; i++) printf("%d ",ans[i]);puts("");
	return 0;
}