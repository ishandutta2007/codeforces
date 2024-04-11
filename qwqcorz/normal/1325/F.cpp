#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
vector<int>e[N],a;
int siz[N],id[N],cnt=0,k;
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dfs(int now)
{
	vis[now]=1;
	id[now]=++cnt;
	a.push_back(now);
	for (int to:e[now])
	if (!vis[to]) return dfs(to);
	else if (id[to]&&cnt-id[to]+1>=k) return;
}
void solve(int n)
{
	for (int i=1;i<=n;i++) if (!vis[i]){dfs(i);break;}
	int mn=n,flag=0;
	for (int to:e[a.back()]) if (id[to]) mn=min(mn,id[to]);
	vector<int>ans;
	for (int i:a)
	{
		if (id[i]==mn) flag=1;
		if (flag) ans.push_back(i);
	}
	puts("2");
	print(ans.size());
	for (int i:ans) print(i,' ');
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read(); k=ceil(sqrt(n));
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		siz[u]++,siz[v]++;
	}
	vector<int>ans;
	for (int i=1;i<=n;i++) q.push(make_pair(siz[i],i));
	while ((int)ans.size()<k)
	{
		int now=q.top().second; q.pop();
		if (vis[now]) continue;
		if (siz[now]>=k-1) return solve(n),0;
		vis[now]=1;
		ans.push_back(now);
		for (int to:e[now])
		if (!vis[to])
		{
			vis[to]=1;
			for (int i:e[to]) if (!vis[i]) q.push(make_pair(--siz[i],i));
		}
	}
	puts("1");
	for (int i:ans) print(i,' ');
	
	return 0;
}