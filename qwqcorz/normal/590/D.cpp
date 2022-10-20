#include<bits/stdc++.h>
using namespace std;
const int N=155;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int dp[2][N][N*N],a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read(),s=read(),p=0;
	for (int i=1;i<=n;i++) a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][0]=0;
	for (int i=1;i<=n;i++,p^=1)
	{
		memset(dp[p],0x3f,sizeof(dp[p]));
		for (int j=0;j<=i;j++)
		for (int k=0;k<=i*i;k++)
		{
			dp[p][j][k]=dp[!p][j][k];
			if (k>=i-j&&j) dp[p][j][k]=min(dp[p][j][k],dp[!p][j-1][k-(i-j)]+a[i]);
		}
	}
	int ans=dp[0][N-1][0];
	for (int i=0;i<=min(s,n*(n-1)/2);i++) ans=min(ans,dp[!p][k][i]);
	print(ans);
	
	return 0;
}