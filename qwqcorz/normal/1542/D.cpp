#include<bits/stdc++.h>
using namespace std;
const int N=505;
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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int a[N],dp[N][N];

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		char c; cin>>c;
		if (c=='+') a[i]=read();
			   else a[i]=-1;
	}
	for (int k=1;k<=n;k++)
	if (a[k]>0)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (int i=1;i<k;i++)
		for (int j=0;j<=i;j++)
		{
			if (a[i]>0) add(dp[i][j+(a[i]<=a[k])],dp[i-1][j]);
			else add(dp[i][max(j-1,0)],dp[i-1][j]);
			add(dp[i][j],dp[i-1][j]);
		}
		for (int j=0;j<=k;j++) dp[k][j]=dp[k-1][j];
		for (int i=k+1;i<=n;i++)
		for (int j=0;j<=i;j++)
		{
			if (a[i]>0) add(dp[i][j+(a[i]<a[k])],dp[i-1][j]);
			else if (j) add(dp[i][j-1],dp[i-1][j]);
			add(dp[i][j],dp[i-1][j]);
		}
		for (int i=0;i<=n;i++) add(ans,1LL*dp[n][i]*a[k]%p);
	}
	print(ans);
	
	return 0;
}