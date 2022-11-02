#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
vector<int> g[MAXN],c;
int hd,n,p[MAXN],par[MAXN],rez;
bool h[MAXN];
void sp(int u,int v)
{
	if(hd==n-3) return;
	p[u]=v; p[v]=u;
	hd+=2;
}
int dfs(int s,int f)
{
	int sz=1;
	par[s]=f;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) sz+=dfs(g[s][i],s);
	if(sz>1 && hd+sz!=n-1) {h[s]=true; hd+=sz; sz=0; rez-=2;}
	return sz;
}
void dfsa(int s,int f)
{
	c.push_back(s);
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f && !h[g[s][i]]) dfsa(g[s][i],s);
}
int main()
{
	cin>>n; rez=2*n;
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++) if(h[i])
	{
		c.clear();
		dfsa(i,par[i]);
		for(int i=0;i+1<c.size();i++) p[c[i]]=c[i+1];
		p[c[c.size()-1]]=c[0];
	}
	printf("%d\n",rez);
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
}