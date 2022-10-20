#include<bits/stdc++.h>
using namespace std;
const int N=85;
const int K=15;

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
void up(int &x,int y) {x=min(x,y);}
bool is[N];
int e[N][N],dp[N][K];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	srand(time(0));
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) e[i][j]=read();
	int Times=5000,ans=1e9+7;
	while (Times--)
	{
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		for (int i=2;i<=n;i++) is[i]=rand()&1;
		for (int j=0;j<k;j++)
		for (int i=1;i<=n;i++)
		if (dp[i][j]<dp[0][0])
		for (int to=1;to<=n;to++)
		if (is[i]!=is[to])
		up(dp[to][j+1],dp[i][j]+e[i][to]);
		up(ans,dp[1][k]);
	}
	print(ans);
	
	return 0;
}