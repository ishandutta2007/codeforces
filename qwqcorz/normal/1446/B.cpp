#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;

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
char a[N],b[N];
int dp[N][N];

signed main()
{
	memset(dp,0,sizeof(dp));
	int n=read(),m=read(),ans=0;
	scanf("%s%s",a+1,b+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		dp[i][j]=max(max(dp[i-1][j],dp[i][j-1])-1,0);
		if (a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
		ans=max(ans,dp[i][j]);
	}
	print(ans);

	return 0;
}