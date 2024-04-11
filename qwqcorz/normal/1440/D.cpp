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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>e[N];
int siz[N],q[N],k;
int vis[N],p[N],cnt;
bool check(int now)
{
	int cnt=0;
	for (int i=0;i<e[now].size();i++)
	{
		int to=e[now][i];
		if (vis[to]==2) continue;
		if (siz[to]<k-1) return 0;
		p[++cnt]=to;
	}
	for (int i=1;i<cnt;i++)
	for (int j=i+1;j<=cnt;j++)
	if (!binary_search(e[p[i]].begin(),e[p[i]].end(),p[j]))
	return 0;
	print(2);
	print(now,' ');
	for (int i=1;i<=cnt;i++) print(p[i],' ');
	puts("");
	return 1;
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),h=1,t=0;
		k=read();
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<=n;i++) siz[i]=0;
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
			siz[u]++;
			siz[v]++;
		}
		if (k*(k-1)>2*m)
		{
			puts("-1");
			continue;
		}
		for (int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
		bool flag=0;
		for (int i=1;i<=n;i++)
		if (siz[i]<k)
		{
			q[++t]=i;
			vis[i]=1;
		}
		if (flag) continue;
		while (h<=t)
		{
			int now=q[h++];
			vis[now]=2;
			if (siz[now]==k-1)
			if (check(now))
			{
				flag=1;
				break;
			}
			for (int i=0;i<e[now].size();i++)
			{
				int to=e[now][i];
				siz[now]--;
				siz[to]--;
				if (siz[to]<k&&!vis[to])
				{
					vis[to]=1;
					q[++t]=to;
				}
			}
		}
		if (flag) continue;
		int cnt=0;
		for (int i=1;i<=n;i++)
		if (!vis[i])
		cnt++;
		if (cnt)
		{
			print(1,' ');
			print(cnt);
			for (int i=1;i<=n;i++)
			if (!vis[i])
			print(i,' ');
			puts("");
		}
		else puts("-1");
	}

	return 0;
}