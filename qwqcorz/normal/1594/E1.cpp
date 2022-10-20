#include<bits/stdc++.h>
using namespace std;
const int N=65;
const int p=1e9+7;

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
int dp[N][6];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	for (int i=0;i<6;i++) dp[1][i]=1;
	for (int i=2;i<=n;i++)
	for (int j=0;j<6;j++)
	for (int k=0;k<6;k++)
	for (int t=0;t<6;t++)
	if ((j&~1)!=(k&~1)&&(j&~1)!=(t&~1))
	dp[i][j]=(dp[i][j]+1LL*dp[i-1][k]*dp[i-1][t])%p;
	for (int i=0;i<6;i++) ans=(ans+dp[n][i])%p;
	print(ans);
	
	return 0;
}