#include<bits/stdc++.h>
using namespace std;
const int N=85;
const int inf=1919810;

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
void up(int &x,int y){if (x>y) x=y;}
int a[N],sum[N],b[N],dp[N][N][N*N/2],p[N],ans[N*N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=1;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x) m++;
		  else a[m]++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=1;i<=m;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=m;i++)
	for (int j=0;j<=n;j++)
	for (int k=0;k<=n*(n-1)/2;k++)
	if (dp[i-1][j][k]<inf)
	{
//		print(i-1,' '),print(j,' '),print(k);
		memcpy(b,a,sizeof(b));
		int x=j-sum[i-1];
		if (x<0) b[i]-=x;
		else
		for (int t=i;t<=m;t++)
		{
			int mn=min(b[t],x);
			b[t]-=mn;
			if (!(x-=mn)) break;
		}
		int cnt=0;
		for (int t=i;t<=m;t++)
		for (int l=1;l<=b[t];l++)
		p[++cnt]=t-i;
		int tot=0;
		for (int t=0;t<=cnt;t++)
		{
			tot+=p[t];
			int now=tot+max(b[i]-t,0);
			up(dp[i][j+t][k+now],dp[i-1][j][k]+t*t);
		}
	}
	for (int i=0;i<=n*(n-1)/2;i++) ans[i]=dp[m][n-m+1][i];
	for (int i=1;i<=n*(n-1)/2;i++) up(ans[i],ans[i-1]);
	for (int i=0;i<=n*(n-1)/2;i++) print(((n-m+1)*(n-m+1)-ans[i])/2,' ');
	
	return 0;
}