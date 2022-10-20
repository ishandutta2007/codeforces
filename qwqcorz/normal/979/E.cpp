#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=55;
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
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int dp[N][N][N][N],Pow[N],a[N];

signed main()
{
	memset(dp,0,sizeof(dp));
	int n=read(),pp=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	dp[0][0][0][0]=Pow[0]=1;
	for (int i=1;i<=n;i++) Pow[i]=Pow[i-1]*2ll%p;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++)
	for (int k=0;k<=i;k++)
	for (int l=0;l<=i;l++)
	{
		int L,R;
		if (a[i]==-1) L=0,R=1;
				 else L=R=a[i];
		for (int t=L;t<=R;t++)
		if (t==0)
		{
			if (i-l-k>0)
			{
				if (l&&j) add(dp[i][j][k][l],dp[i-1][j-1][k][l-1]*Pow[max(i-2,0ll)]%p);
				if (l   ) add(dp[i][j][k][l],dp[i-1][j  ][k][l-1]*Pow[max(i-2,0ll)]%p);
			}
			else
			if (i-l-k==0)
			{
				if (l) add(dp[i][j][k][l],dp[i-1][j][k][l-1]*Pow[max(i-1,0ll)]%p);
			}
		}
		else
		{
			if (l-j>0)
			{
				if (k  ) add(dp[i][j][k][l],dp[i-1][j][k-1][l]*Pow[max(i-2,0ll)]%p);
				if (j<l) add(dp[i][j][k][l],dp[i-1][j][k  ][l]*Pow[max(i-2,0ll)]%p);
			}
			else
			if (l-j==0)
			{
				add(dp[i][j][k][l],dp[i-1][j][k][l]*Pow[max(i-1,0ll)]%p);
			}
		}
	}
	for (int j=0;j<=n;j++)
	for (int k=0;k<=n;k++)
	for (int l=0;l<=n;l++)
	if (l-j>=0&&n-l-k>=0)
	if ((l-j+n-l-k)%2==pp)
	add(ans,dp[n][j][k][l]);
	print(ans);

	return 0;
}