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
bool dp[N][6];
int pre[N][6],a[N];
void Print(int n,int m)
{
	if (!n) return;
	Print(n-1,pre[n][m]);
	print(m,' ');
}

signed main()
{
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=5;i++) dp[1][i]=1;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++)
	for (int j=1;j<=5;j++)
	if (a[i]==a[i-1])
	{
		for (int k=1;k<=5;k++)
		if (j!=k)
		if (dp[i-1][k])
		{
			dp[i][j]=1;
			pre[i][j]=k;
		}
	}
	else if (a[i]<a[i-1])
	{
		for (int k=1;k<=5;k++)
		if (j<k)
		if (dp[i-1][k])
		{
			dp[i][j]=1;
			pre[i][j]=k;
		}
	}
	else if (a[i]>a[i-1])
	{
		for (int k=1;k<=5;k++)
		if (j>k)
		if (dp[i-1][k])
		{
			dp[i][j]=1;
			pre[i][j]=k;
		}
	}
	for (int i=1;i<=5;i++)
	if (dp[n][i])
	return Print(n,i),0;
	puts("-1");

	return 0;
}