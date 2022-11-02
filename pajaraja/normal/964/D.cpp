#include <bits/stdc++.h>
using namespace std;
vector<int> g[200007],sol;
bool d[200007];
int root;
void dfsd(int s)
{
	if(d[s]) return;
	d[s]=true;
	sol.push_back(s);
	for(int i=0;i<g[s].size();i++) dfsd(g[s][i]);
}
void dfs(int s)
{
	int deg=0;
	if(s!=root) deg++;
	for(int i=0;i<g[s].size();i++)
	{
		dfs(g[s][i]);
		if(!d[g[s][i]]) deg++;
	}
	if(deg%2==0) dfsd(s);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		g[t].push_back(i);
		if(t==0) root=i;
	}
	dfs(root);
	if(sol.size()<n) printf("NO");
	else 
	{
		printf("YES\n");
		for(int i=0;i<n;i++) printf("%d\n",sol[i]);
	}
}