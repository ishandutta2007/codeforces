#include<bits/stdc++.h>
using namespace std;
const int N=55;

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
int dp[N][N];
char a[N];

signed main()
{
	memset(dp,0x3f,sizeof(dp));
	int n=read(),m=read(),ans=dp[0][0];
	scanf("%s",a+1);
	sort(a+1,a+1+n);
	a[0]=dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		for (int k=0;k<i;k++)
		if (a[i]-a[k]>=2)
		dp[i][j]=min(dp[i][j],dp[k][j-1]+a[i]-'a'+1);
		ans=min(ans,dp[i][m]);
	}
	if (ans==dp[0][1]) puts("-1");
				  else print(ans);

	return 0;
}