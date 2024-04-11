#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int col[N];
vector<int>u[N],v[N],e[N];
void add_edge(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}
void dfs(int now,int color)
{
	col[now]=color;
	for (int to:e[now]) if (!col[to]) dfs(to,3-col[now]);
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		u[x].push_back(i);
		v[y].push_back(i);
	}
	for (int i=1;i<=2e5;i++)
	for (int j=0;j+1<(int)u[i].size();j+=2)
	add_edge(u[i][j],u[i][j+1]);
	for (int i=1;i<=2e5;i++)
	for (int j=0;j+1<(int)v[i].size();j+=2)
	add_edge(v[i][j],v[i][j+1]);
	for (int i=1;i<=n;i++) if (!col[i]) dfs(i,1);
	for (int i=1;i<=n;i++) putchar(" rb"[col[i]]);
	
	return 0;
}