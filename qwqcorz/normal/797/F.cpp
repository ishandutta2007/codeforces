#include<bits/stdc++.h>
#define x first
#define p second
#define int long long
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
pair<int,int>b[N];
int a[N],sum[N],dp[N][N],q[N],val[N],h,t;

signed main()
{
	int n=read(),m=read(),Sum=n;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		b[i].x=read();
		Sum-=b[i].p=read();
	}
	if (Sum>0) return puts("-1"),0;
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	memset(dp,0x3f,sizeof(dp));
	const int inf=dp[0][0];
	dp[0][0]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		sum[j]=sum[j-1]+labs(b[i].x-a[j]);
		dp[i][0]=val[0]=q[0]=h=t=0;
		for (int j=1;j<=n;j++)
		{
			while (h<=t&&q[h]<j-b[i].p) h++;
			dp[i][j]=min(dp[i-1][j],h<=t?val[h]+sum[j]:inf);
			while (h<=t&&val[t]>dp[i-1][j]-sum[j]) t--;
			q[++t]=j;
			val[t]=dp[i-1][j]-sum[j];
		}
	}
	print(dp[m][n]);

	return 0;
}