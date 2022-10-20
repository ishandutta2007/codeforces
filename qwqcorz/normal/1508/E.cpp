#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>son[N];
int a[N],dfn[N],cntdfn=0,Exit[N],End[N],deep[N],cntExit=0;
void dfs1(int now,int father)
{
	dfn[now]=++cntdfn;
	for (int to:son[now])
	{
		if (to==father) continue;
		deep[to]=deep[now]+1;
		dfs1(to,now);
	}
	Exit[now]=++cntExit;
}
ll ans=0;
int cnt;
void dfs2(int now,int father)
{
	if (a[now]) return;
	a[now]=++cnt;
	for (int to:son[now])
	{
		if (to==father) continue;
		dfs2(to,now);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) End[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		son[u].push_back(v);
		son[v].push_back(u);
	}
	for (int i=1;i<=n;i++) sort(son[i].begin(),son[i].end(),[&](int x,int y){return End[x]<End[y];});
	dfs1(1,0);
	for (int i=2;i<=n;i++) if (End[i]<End[1]-1) a[i]=Exit[i],ans+=deep[i];
	cnt=End[1]-2;
	dfs2(1,0);
	int now=1;
	while (a[now]!=End[now])
	{
		int tmp=now;
		for (int to:son[now])
		{
			if (deep[to]<deep[now]||a[to]<a[now]) continue;
			swap(a[now],a[to]);
			swap(now,to);
			ans++;
			break;
		}
		if (now==tmp) break;
	}
	bool flag=1;
	for (int i=1;i<=n;i++) if (a[i]!=End[i]) flag=0;
	if (flag)
	{
		puts("YES");
		print(ans);
		for (int i=1;i<=n;i++) print(dfn[i],' ');
	}
	else puts("NO");
	
	return 0;
}