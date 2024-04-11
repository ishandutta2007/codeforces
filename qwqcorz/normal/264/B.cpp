#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int MaxN=1e6;

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
bool vis[N];
int p[N],cnt=0;
vector<int>q[N];
int a[N],dp[N],Max[N];

signed main()
{
	for (int i=2;i<=MaxN;i++)
	{
		if (!vis[i])
		{
			p[++cnt]=i;
			q[i].push_back(i);
		}
		for (int j=1;j<=cnt;j++)
		{
			if (i*p[j]>MaxN) break;
			vis[i*p[j]]=1;
			q[i*p[j]]=q[i];
			if (q[i*p[j]].back()!=p[j])
			q[i*p[j]].push_back(p[j]);
			if (i%p[j]==0) break;
		}
	}
//	for (int i=2;i<=MaxN;i++)
//	{
//		print(i,':');
//		for (int j=0;j<q[i].size();j++) print(q[i][j],' ');
//		puts("");
//	}
	int n=read(),ans=1;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	if (a[i]>1)
	{
		for (int j=0;j<q[a[i]].size();j++)
		dp[i]=max(dp[i],Max[q[a[i]][j]]);
		ans=max(ans,++dp[i]);
		for (int j=0;j<q[a[i]].size();j++)
		Max[q[a[i]][j]]=max(Max[q[a[i]][j]],dp[i]);
	}
	print(ans);

	return 0;
}