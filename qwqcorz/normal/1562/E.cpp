#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int p=998244353;

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
inline void up(int &x,int y){x=max(x,y);}
char a[N];
int dp[N][N],lcp[N][N],n;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		n=read();
		scanf("%s",a+1);
		for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j--)
		lcp[i][j]=a[i]==a[j]?lcp[i+1][j+1]+1:0;
		for (int i=1;i<=n;i++)
		for (int j=0;i+j<=n;j++) dp[i][j]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<i;j++)
			if (i+lcp[i][j]<=n&&a[i+lcp[i][j]]>a[j+lcp[i][j]])
			up(dp[i][lcp[i][j]],dp[j][n-j]+1);
			for (int j=1;i+j<=n;j++) up(dp[i][j],dp[i][j-1]+1);
//			for (int j=0;i+j<=n;j++) print(dp[i][j],' ');
//			puts("");
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		for (int j=0;i+j<=n;j++)
		up(ans,dp[i][j]);
		print(ans);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) lcp[i][j]=0;
	}
	
	return 0;
}