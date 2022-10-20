#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
const int inf=998244353;

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
int dp[N][N];
vector<int>p[N];
int a[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) p[a[i]=read()].push_back(i);
		for (int i=0;i<=n+1;i++)
		for (int j=0;j<=n+1;j++) dp[i][j]=inf;
		for (int i=1;i<=n;i++) dp[i][i]=0;
		for (int i=n;i>=1;i--)
		for (int j=i+1;j<=n;j++)
		{
			dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			for (int k:p[a[j]]) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
		print(dp[1][n]);
		for (int i=1;i<=n;i++) p[i].clear();
	}
	
	return 0;
}