#include<bits/stdc++.h>
#define poly vector<int>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

poly merge(poly x,poly y)
{
	int n=x.size(),m=y.size();
	poly ret;
	int i=0,j=0;
	while (i<n&&j<m)
	if (x[i]<y[j]) ret.push_back(x[i++]);
			  else ret.push_back(y[j++]);
	while (i<n) ret.push_back(x[i++]);
	while (j<m) ret.push_back(y[j++]);
	ret.resize(min(n+m,10));
	return ret;
}
vector<int>e[N];
poly a[N],ans[N][20];
int fa[N][20],deep[N];
void dfs(int now,int father)
{
	deep[now]=deep[father]+1;
	fa[now][0]=father;
	ans[now][0]=a[now];
	for (int i=1;i<20;i++)
		fa[now][i]=fa[fa[now][i-1]][i-1],
		ans[now][i]=merge(ans[now][i-1],ans[fa[now][i-1]][i-1]);
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
	}
}
poly query(int x,int y)
{
	poly ret;
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=19;deep[x]!=deep[y];i--)
	if (deep[fa[x][i]]>=deep[y]) ret=merge(ret,ans[x][i]),x=fa[x][i];
	if (x==y) return merge(ret,ans[x][0]);
	for (int i=19;i>=0;i--)
	if (fa[x][i]!=fa[y][i])
		ret=merge(ret,merge(ans[x][i],ans[y][i])),
		x=fa[x][i],y=fa[y][i];
	return merge(ret,merge(ans[x][1],ans[y][0]));
}
void GreenDay()
{
	int n=read(),m=read(),q=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=m;i++) a[read()].push_back(i);
	for (int i=1;i<=n;i++) sort(a[i].begin(),a[i].end()),a[i].resize(min((int)a[i].size(),10));
	dfs(1,0);
	for (int i=1;i<=q;i++)
	{
		int u=read(),v=read(),k=read();
		poly res=query(u,v);
		int tot=min(k,(int)res.size());
		print(tot,' ');
		for (int i=0;i<tot;i++) print(res[i],' ');
		puts("");
	}
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
/*
10 10 1
2 6
9 3
6 10
10 4
8 1
7 1
8 6
3 8
6 5
3 7 2 9 5 3 3 7 5 2
2 9 10
*/