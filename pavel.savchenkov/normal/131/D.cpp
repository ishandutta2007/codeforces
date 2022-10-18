#include <cstdio>
#include <vector>
#include <iostream>
const int inf = 2000000000; 
using namespace std;
vector < vector < int > > g;
vector < int > color;
vector < bool > on_cycle;
vector < int > parent;
int n; bool isexit = false;

void dfs(int v,int p = -1)
{
	if (isexit) return;
	color[v] = 1;
	parent[v] = p; 
 	for (int i=0;i<(int)g[v].size();i++)
	{
		if (isexit) break; 
		if (color[g[v][i]] == 0) dfs(g[v][i],v); else
			if (color[g[v][i]] == 1 && g[v][i]!=parent[v])
			{
				int j = v;
				while (j!=g[v][i]) { on_cycle[j] = true; j = parent[j];}
				on_cycle[g[v][i]] = true;
				isexit = true;
			}
	}
	color[v] = 3;
}

void dfs2(int v)
{
	for (int i=0; i<(int)g[v].size(); i++)
		if (color[g[v][i]]>color[v]+1) { color[g[v][i]] = color[v]+1; dfs2(g[v][i]); }
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	g.resize(n+1); color.resize(n+1); on_cycle.resize(n+1,false); parent.resize(n+1);
	for (int i=1;i<=n;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i=1;i<=n;i++)
		if (color[i] == 0) dfs(i);

	for (int i=1; i<=n; i++) 
		if (on_cycle[i]) color[i] = 0; else color[i] = inf;
	for (int i=1;i<=n;i++)
		if (on_cycle[i]) dfs2(i);


	for (int i=1;i<=n;i++)
		printf("%d ",color[i]);
	return 0;
}