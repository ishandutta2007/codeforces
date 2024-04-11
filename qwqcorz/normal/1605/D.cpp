#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int Log[N],p[N];
vector<int>e[N],a[2];
vector<int>b[20];
void dfs(int now,int father,int col)
{
	a[col].push_back(now);
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now,!col);
	}
}
void Multi_test_no_horses()
{
	int n=read();
	a[0].clear(),a[1].clear();
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,0);
	for (int i=0;i<20;i++) b[i].clear();
	for (int i=1;i<=n;i++) b[Log[i]].push_back(i);
	int k=0;
	for (int i=0;i<20;i++) if ((int)b[i].size()==(1<<i)) k=i;
	if (a[0].size()>a[1].size()) swap(a[0],a[1]);
	static bool vis[20];
	memset(vis,0,sizeof(vis));
	for (int i=k;i>=0;i--)
	if ((1<<i)<=(int)a[0].size())
	{
		vis[i]=1;
		for (int j:b[i])
		{
			p[a[0].back()]=j;
			a[0].pop_back();
		}
	}
	for (int i=19;i>=0;i--)
	if (!vis[i])
	for (int j:b[i])
	{
		p[a[1].back()]=j;
		a[1].pop_back();
	}
	for (int i=1;i<=n;i++) print(p[i]," \n"[i==n]);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	for (int i=2;i<N;i++) Log[i]=Log[i/2]+1;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}