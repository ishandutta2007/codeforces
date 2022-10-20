#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int col[N+N],sum=0;
vector<int>e[N+N],a[N];
void add_edge(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}
void dfs(int now,int c)
{
	if (!c) sum^=now&1;
	col[now]=c;
	for (int to:e[now]) if (col[to]<0) dfs(to,!c);
}

signed main()
{
	int n=read();
	if (n%2==0)
	{
		puts("First");
		for (int i=1;i<=n;i++) print(i,' ');
		for (int i=1;i<=n;i++) print(i," \n"[i==n]);
	}
	else
	{
		memset(col,-1,sizeof(col));
		puts("Second"),fflush(stdout);
		for (int i=1;i<=n+n;i++) a[read()].push_back(i);
		for (int i=1;i<=n;i++) add_edge(i,i+n);
		for (int i=1;i<=n;i++) add_edge(a[i][0],a[i][1]);
		for (int i=1;i<=n;i++) if (col[i]<0) dfs(i,0);
		for (int i=1;i<=n+n;i++) if (col[i]==sum) print(i,' ');
		puts("");
	}
	
	return 0;
}