#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
pair<int,int>mn[N][N];
int dp[N][N],a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) mn[i][i]=mk(a[i],i);
	for (int i=0;i<=n+1;i++)
	for (int j=0;j<=n+1;j++) dp[i][j]=1;
	for (int i=2;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	{
		int l=j,r=j+i-1,le=0,ri=0;
		int x=(mn[l][r]=min(mn[l][r-1],mn[r][r])).se;
		for (int k=l;k<=x;k++) le=(le+1LL*dp[l][k-1]*dp[k][x-1])%p;
		for (int k=x;k<=r;k++) ri=(ri+1LL*dp[x+1][k]*dp[k+1][r])%p;
		dp[l][r]=1LL*le*ri%p;
	}
	print(dp[1][n]);
	
	return 0;
}