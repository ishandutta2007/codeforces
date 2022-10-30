#include <bits/stdc++.h>
using namespace std;
vector<int> g[100007];
bool vi[100007];
int x,c,p[100007],ans[100007];
map<int,int> m[100007];
void dfsbroj(int s,int f)
{
	if(vi[s]) return;
	x++;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfsbroj(g[s][i],s);
}
int dfs(int s,int f)
{
	if(vi[s]) return 0;
	int k=1;
	bool moze=true;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f)
	{
	    int a=dfs(g[s][i],s);
        if(a>x/2) moze=false;
	    k+=a;
	}
	if(x-k>x/2) moze=false;
	if(moze) c=s;
	return k;
}
void dfsdist(int s,int f,int d)
{
	if(vi[s]) return;
	m[c][s]=d;
	for(int i=0;i<g[s].size();i++) if(g[s][i]!=f) dfsdist(g[s][i],s,d+1);
}
void centrodecomp(int s,int f)
{
	x=0;
	dfsbroj(s,f);
	dfs(s,f);
	p[c]=f;
	dfsdist(c,0,0);
	vi[c]=true;
	ans[c]=1000000007;
	int r=c;
	for(int i=0;i<g[r].size();i++) if(!vi[g[r][i]]) centrodecomp(g[r][i],r);
}
void paint(int x)
{
	int y=x;
	while(y)
	{
		ans[y]=fmin(ans[y],m[y][x]);
		y=p[y];
	}
}
int find(int x)
{
	int y=x,sol=1000000007;
	while(y)
	{
		sol=fmin(m[y][x]+ans[y],sol);
		y=p[y];
	}
	return sol;
}
int main()
{
	int n,t1,t2,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&t1,&t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	centrodecomp(1,0);
	paint(1);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&t1,&t2);
		if(t1==1) paint(t2);
		else printf("%d\n",find(t2));
	}
}