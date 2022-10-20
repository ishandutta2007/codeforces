#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=405;
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
inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int a[28],dp[2][N][N][3][3],sum[N][N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),t=0;
	for (int i=1;i<=26;i++) a[i]=read();
	for (int i=0;i<=2;i++)
	for (int j=0;j<=2;j++) dp[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i?1:24)*(j?1:24);
	for (int i=3;i<=n;i++,t^=1)
	{
		memset(dp[!t],0,sizeof(dp[!t]));
		for (int j=0;j<=n;j++)
		for (int k=0;j+k<=n;k++)
		for (int x=0;x<=2;x++)
		for (int y=0;y<=2;y++)
		{
			add(dp[!t][j][k][y][0],dp[t][j][k][x][y]*(24LL-!x)%p);
			if (x!=1) add(dp[!t][j+1][k][y][1],dp[t][j][k][x][y]);
			if (x!=2) add(dp[!t][j][k+1][y][2],dp[t][j][k][x][y]);
		}
	}
	for (int i=n;i>=0;i--)
	for (int j=n;j>=0;j--)
	{
		sum[i][j]=(1LL*sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+p)%p;
		for (int x=0;x<=2;x++)
		for (int y=0;y<=2;y++) add(sum[i][j],dp[t][i][j][x][y]);
	}
	int ans=sum[0][0];
	for (int i=1;i<=26;i++) add(ans,p-sum[a[i]+1][0]);
	for (int i=1;i<=25;i++)
	for (int j=i+1;j<=26;j++)
	add(ans,sum[a[i]+1][a[j]+1]);
	print(ans);
	
	return 0;
}