#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
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
struct answer
{
	int x1,y1,x2,y2;
}ans[N];
set<int>e[N];
int n,cnt;
bool vis[N];
pair<int,int>a[N];
vector<int>del[N];
void clear()
{
	cnt=0;
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<=n;i++) del[i].clear();
	n=0;
}
int find(int x,int fa)
{
	for (int i:e[x]) if (i!=fa) return find(i,x);
	return x;
}
bool dfs(int now,int father)
{
	int tot=0,tmp=0;
	for (int to:e[now])
	{
		if (to==father) continue;
		tot+=tmp=dfs(to,now);
		if (!tmp) continue;
		if (tot==2) del[father].push_back(now);
		if (tot>2) del[now].push_back(to);
	}
	return tot<=1;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].insert(v);
			e[v].insert(u);
		}
		if (n<=3)
		{
			clear();
			puts("0");
			continue;
		}
		dfs(1,0);
		for (int i=1;i<=n;i++)
		for (int j:del[i])
		{
			ans[++cnt]=(answer){i,j,0,0};
			e[i].erase(j);
			e[j].erase(i);
		}
		int m=0;
		for (int i=1;i<=n;i++)
		if (!vis[i]&&(int)e[i].size()<=1)
		{
			int x=find(i,0);
			vis[i]=vis[x]=1;
			a[++m]=mk(i,x);
		}
//		for (int i=1;i<=m;i++) print(a[i].fi,','),print(a[i].se);
		for (int i=1;i<m;i++) ans[i].x2=a[i].se,ans[i].y2=a[i+1].fi;
		print(cnt);
		for (int i=1;i<=cnt;i++)
		{
			print(ans[i].x1,' ');
			print(ans[i].y1,' ');
			print(ans[i].x2,' ');
			print(ans[i].y2);
		}
		clear();
	}
	
	return 0;
}