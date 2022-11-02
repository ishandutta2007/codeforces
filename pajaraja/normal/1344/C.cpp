#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
vector<int> g[MAXN],gt[MAXN];
int n,m,deg[MAXN],sz,res;
char c[MAXN];
bool vi[MAXN],vit[MAXN];
void toposort()
{
	queue<int> q;
	for(int i=1;i<=n;i++) deg[i]=g[i].size();
	for(int i=1;i<=n;i++) if(deg[i]==0) q.push(i);
	while(!q.empty())
	{
		sz++;
		int u=q.front();
		q.pop();
		for(int i=0;i<gt[u].size();i++) {deg[gt[u][i]]--; if(deg[gt[u][i]]==0) q.push(gt[u][i]);}
	}
}
void dfs(int s)
{
	if(vi[s]) return;
	vi[s]=true;
	for(int i=0;i<g[s].size();i++) dfs(g[s][i]);
}
void dfst(int s)
{
	if(vit[s]) return;
	vit[s]=true;
	for(int i=0;i<gt[s].size();i++) dfst(gt[s][i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) 
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		gt[t2].push_back(t1);
	}
	toposort();
	if(sz!=n) {printf("-1"); return 0;}
	for(int i=1;i<=n;i++)
	{
		if(vi[i] || vit[i]) c[i]='E';
		else {c[i]='A'; res++;}
		vi[i]=false; dfs(i); vit[i]=false; dfst(i);
	}
	printf("%d\n",res);
	for(int i=1;i<=n;i++) printf("%c",c[i]);
}