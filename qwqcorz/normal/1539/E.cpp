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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int al[N][20],ar[N][20],bl[N][20],br[N][20],k[N],na[N],nb[N];
int dp[N][2],from[N][2];
void output(int x,int y)
{
	if (!x) return;
	output(x-1,from[x][y]);
	print(y,' ');
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		k[i]=read();
		al[i][0]=read();
		ar[i][0]=read();
		bl[i][0]=read();
		br[i][0]=read();
	}
	for (int i=n;i>=0;i--)
	{
		int up=0;
		for (int j=1;i+(1<<j)-1<=n;j++)
		{
			up=j;
			al[i][j]=max(al[i][j-1],al[i+(1<<(j-1))][j-1]);
			bl[i][j]=max(bl[i][j-1],bl[i+(1<<(j-1))][j-1]);
			ar[i][j]=min(ar[i][j-1],ar[i+(1<<(j-1))][j-1]);
			br[i][j]=min(br[i][j-1],br[i+(1<<(j-1))][j-1]);
		}
		na[i]=i;
		for (int j=up;j>=0;j--)
		if (na[i]+(1<<j)-1<=n&&al[na[i]][j]<=k[i]&&k[i]<=ar[na[i]][j]) na[i]+=1<<j;
		nb[i]=i;
		for (int j=up;j>=0;j--)
		if (nb[i]+(1<<j)-1<=n&&bl[nb[i]][j]<=k[i]&&k[i]<=br[nb[i]][j]) nb[i]+=1<<j;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=nb[0];
	dp[0][1]=na[0];
//	for (int i=0;i<=n;i++) print(na[i],','),print(nb[i]);
	for (int i=1;i<=n;i++)
	{
		if (na[i]>i) if (~dp[i-1][0]&&na[i-1]>=i) dp[i][0]=dp[i-1][0],from[i][0]=0;
		if (nb[i]>i) if (~dp[i-1][1]&&nb[i-1]>=i) dp[i][1]=dp[i-1][1],from[i][1]=1;
		if (na[i]>i) if (dp[i-1][1]>=i&&nb[i-1]>dp[i][0]) dp[i][0]=nb[i-1],from[i][0]=1;
		if (nb[i]>i) if (dp[i-1][0]>=i&&na[i-1]>dp[i][1]) dp[i][1]=na[i-1],from[i][1]=0;
//		print(dp[i][0],' '),print(dp[i][1]);
	}
	int ans=-1;
	if (dp[n][0]>n) ans=0;
	if (dp[n][1]>n) ans=1;
	if (~ans) puts("Yes"),output(n,ans);
		 else puts("No");
	
	return 0;
}