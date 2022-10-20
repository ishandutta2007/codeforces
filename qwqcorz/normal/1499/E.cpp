#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
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
char a[2][N];
int dp[N][N][2][2][2],ans=0;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	scanf("%s%s",a[0]+1,a[1]+1);
	int n=strlen(a[0]+1),m=strlen(a[1]+1);
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	{
		for (int x=0;x<=1;x++)
		for (int y=0;y<=1;y++)
		for (int k=0;k<=1;k++)
		{
			if (i<n&&a[0][i+1]!=a[k][k?j:i]) add(dp[i+1][j][1][y][0],dp[i][j][x][y][k]);
			if (j<m&&a[1][j+1]!=a[k][k?j:i]) add(dp[i][j+1][x][1][1],dp[i][j][x][y][k]);
			if (x&&y) add(ans,dp[i][j][1][1][k]);
			if (!dp[i][j][x][y][k]) continue;
		}
		if (i<n) add(dp[i+1][j][1][0][0],1);
		if (j<m) add(dp[i][j+1][0][1][1],1);
	}
	print(ans);
	
	return 0;
}