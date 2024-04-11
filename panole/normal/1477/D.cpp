#include<bits/stdc++.h>
using namespace std;

int n,T,m,x,y,tot,ansp[500010],ansq[500010],cnt,id[500010];
vector<int> v[500010],e[500010],grp[500010],E[500010];
bool bo[500010];

bool dfs(int x)
{
	bo[x]=1;
	for (int i=0,sz=e[x].size(); i<sz; i++)
		if (!bo[e[x][i]]) 
			if (!dfs(e[x][i]))
			{
				if (!id[x]) id[x]=++tot,grp[tot].push_back(x);
				grp[id[x]].push_back(e[x][i]);
			}
	if (!id[x]) return 0; else return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m),tot=0;
		for (int i=1; i<=n; i++) v[i].clear(),e[i].clear(),bo[i]=0,id[i]=0;
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y),v[y].push_back(x);
		}
		for (int i=1; i<=n; i++) 
		{
			int p=0;
			for (int j=0,sz=v[i].size(); j<sz; j++) bo[v[i][j]]=1;
			for (int j=1; j<=n; j++) if (i!=j&&!bo[j]) {p=j; break;}
			if (!p) grp[++tot].push_back(i); else e[i].push_back(p),e[p].push_back(i);
			for (int j=0,sz=v[i].size(); j<sz; j++) bo[v[i][j]]=0;
		}
		for (int i=1; i<=n; i++) if (!bo[i]&&e[i].size())
			if (!dfs(i)) grp[id[e[i][0]]].push_back(i);
		cnt=0;
		for (int i=1; i<=tot; i++) 
		{
			int sz=grp[i].size();
			for (int j=0; j<sz; j++) ansp[grp[i][j]]=cnt+1+j,ansq[grp[i][j]]=cnt+j;
			cnt+=sz,ansq[grp[i][0]]=cnt,grp[i].clear();
		}
		for (int i=1; i<=n; i++) printf("%d ",ansp[i]);puts("");
		for (int i=1; i<=n; i++) printf("%d ",ansq[i]);puts("");
	}
	return 0;
}