#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
int deep[N],fa[N];
vector<int>e[N],a[N];
void clear(int n){for (int i=1;i<=n;i++) e[i].clear(),a[i].clear(),vis[i]=0;}
int dfs(int now,int father)
{
	vis[now]=1;
	int ret=deep[now]=deep[fa[now]=father]+1;
	a[deep[now]].push_back(now);
	for (int to:e[now])
	{
		if (vis[to]) continue;
		ret=max(ret,dfs(to,now));
	}
	return ret;
}
void work()
{
	int n=read(),m=read();
	clear(n);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int d=dfs(1,0);
	if (d>=(n+1)/2)
	{
		puts("PATH");
		print(d);
		int x=0;
		for (int i=1;i<=n;i++) if (deep[i]==d) x=i;
		for (;x;x=fa[x]) print(x," \n"[fa[x]==0]);
	}
	else
	{
		puts("PAIRING");
		vector<pair<int,int>>ans;
		for (int i=1;i<=d;i++)
		for (int j=0;j+1<(int)a[i].size();j+=2)
		ans.push_back({a[i][j],a[i][j+1]});
		print(ans.size());
		for (auto [x,y]:ans) print(x,' '),print(y);
	}
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}
//