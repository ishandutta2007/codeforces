#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int M=4e4+5;

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
void up(int &x,int y) {x=max(x,y);}
int a[N][M],sum[M],dp[N][M],val[M],q[M];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	memset(val,0xc0,sizeof(val));
	int n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=read();
	for (int i=m;i>=1;i--) sum[i]=sum[i+1]+a[1][i];
	for (int i=1;i<=m;i++) dp[1][i]=sum[i]-sum[i+k];
	for (int i=2;i<=n;i++)
	{
		for (int j=m;j>=1;j--) sum[j]=sum[j+1]+a[i][j];
		///////////////////////////////////////////////////////////////////////case1
		for (int j=1;j<=m;j++) val[j]=max(val[j-1],dp[i-1][j]+sum[j]-sum[j+k]);
		for (int j=k;j<=m;j++) up(dp[i][j],val[j-k]);
		///////////////////////////////////////////////////////////////////////case2
		for (int j=m;j>=1;j--) val[j]=max(val[j+1],dp[i-1][j]+sum[j]-sum[j+k]);
		for (int j=1;j<=m;j++) up(dp[i][j],val[j+k+1]);
		///////////////////////////////////////////////////////////////////////case3
		for (int j=1;j<=m;j++) val[j]=dp[i-1][j]+sum[j];
		for (int j=1,h=1,t=0;j<=m;j++)
		{
			while (h<=t&&val[q[t]]<val[j]) t--;
			q[++t]=j;
			while (h<=t&&q[h]<=j-k) h++;
			up(dp[i][j],val[q[h]]-sum[j]);
		}
		///////////////////////////////////////////////////////////////////////case4
		for (int j=1;j<=m;j++) val[j]=dp[i-1][j]-sum[j+k];
		for (int j=1,h=1,t=0,jj=1;j<=m;j++)
		{
			while (jj<=j+k&&jj<=m)
			{
				while (h<=t&&val[q[t]]<val[jj]) t--;
				q[++t]=jj++;
			}
			while (h<=t&&q[h]<=j) h++;
			up(dp[i][j],val[q[h]]+sum[j+k]);
		}
		///////////////////////////////////////////////////////////////////////add
		for (int j=1;j<=m;j++) dp[i][j]+=sum[j]-sum[j+k];
	}
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=1;j<=m;j++) print(dp[i][j],',');
	int ans=0;
	for (int i=1;i<=m;i++) up(ans,dp[n][i]);
	print(ans);
	
	return 0;
}
/*
    j<=i-k      dp[j]+sum[j]-sum[j+k]
i-k<j<=i        dp[j]+sum[j]-sum[i]
i  <j<=i+k      dp[j]+sum[i+k]-sum[j+k]
i+k<j           dp[j]+sum[j]-sum[j+k]
*/