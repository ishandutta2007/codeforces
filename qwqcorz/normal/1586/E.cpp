#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool vis[N];
vector<int>e[N],t[N],ans[N];
int fa[N],deep[N],x[N],tot=0;
void get(int now)
{
	vis[now]=1;
	for (int to:e[now])
	{
		if (vis[to]) continue;
		t[now].push_back(to);
		deep[to]=deep[now]+1;
		fa[to]=now;
		get(to);
	}
}
int dfs(int now)
{
	int ret=0;
	for (int to:t[now]) ret+=dfs(to);
	tot+=ret/2;
	ret=ret&1;
	if (x[now]) return 1;
	tot+=ret;
	return 0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	get(1);
	int q=read();
	for (int i=1;i<=q;i++)
	{
		vector<int>tmp;
		int u=read(),v=read();
		while (u!=v)
		if (deep[u]>deep[v])
		{
			x[u]^=1;
			ans[i].push_back(u);
			u=fa[u];
		}
		else
		{
			x[v]^=1;
			tmp.push_back(v);
			v=fa[v];
		}
		ans[i].push_back(u);
		reverse(tmp.begin(),tmp.end());
		for (int j:tmp) ans[i].push_back(j);
	}
	int flag=1;
	for (int i=1;i<=n;i++) if (x[i]) flag=0;
	if (flag)
	{
		puts("YES");
		for (int i=1;i<=q;i++)
		{
			print(ans[i].size());
			for (int j:ans[i]) print(j,' ');
			puts("");
		}
	}
	else puts("NO"),dfs(1),print(tot);
	
	return 0;
}