#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
bool vis[MAXN];
vector<int> g[MAXN],ord;
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(auto& v : g[u])dfs(v);
	ord.push_back(u);
}
int p[MAXN],res[MAXN];
vector<pair<int,int>> e[MAXN];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vector<int> cir;
		int t=i;
		do
		{
			cir.push_back(t);
			vis[t]=1;
			t=p[t];
		}
		while(!vis[t]);
		for(size_t j=0;j<cir.size();j++)
			res[cir[j]]=j;
		for(auto u : cir)
		{
			sort(e[u].begin(),e[u].end(),[&](auto& x,auto& y){
				return (res[x.first]-res[u]+cir.size())%cir.size()
					 < (res[y.first]-res[u]+cir.size())%cir.size();
			});
			for(size_t j=0;j+1<e[u].size();j++)
				g[e[u][j].second].push_back(e[u][j+1].second);
		}
	}
	memset(vis,0,(m+1)*sizeof(vis[0]));
	for(int i=1;i<=m;i++)
		if(!vis[i])dfs(i);
	reverse(ord.begin(),ord.end());
	for(int i=0;i<m;i++)
		printf("%d%c",ord[i]," \n"[i+1==m]);
	return 0;
}