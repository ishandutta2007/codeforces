#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int p=1e9+7;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

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
char get()
{
	char c=getchar();
	while (c<'a'||'z'<c) c=getchar();
	return c;
}
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
char a[N][N];
int dp[2][N][N];

signed main()
{
	int n=read(),m=read(),p=0,ans=0;
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=get();
	for (int k=0;k<(n+m)/2;k++,p^=1)
	for (int i=0;i<=min(k,n-1);i++)
	for (int j=0;j<=min(k,n-1);j++)
	{
		int x1=1+i,y1=1+k-i,x2=n-j,y2=m-(k-j);
		if (a[x1][y1]!=a[x2][y2]) dp[p][i][j]=0;
//		print(x1,',');
//		print(y1,' ');
//		print(x2,',');
//		print(y2,':');
//		print(dp[p][i][j]);
		for (int f1=0;f1<=1;f1++)
		for (int f2=2;f2<=3;f2++)
		{
			int nx1=x1+dx[f1],nx2=x2+dx[f2],ny1=y1+dy[f1],ny2=y2+dy[f2];
			if (nx1<=n&&ny1<=m&&nx2>=1&&ny2>=1)
			add(dp[p^1][i+(f1&1)][j+(f2&1)],dp[p][i][j]);
		}
		if (k==(n+m)/2-1)
		{
			if (x1==x2&&y1==y2) add(ans,dp[p][i][j]),dp[p][i][j]=0;
			if (x1+1==x2&&y1==y2) add(ans,dp[p][i][j]),dp[p][i][j]=0;
			if (x1==x2&&y1+1==y2) add(ans,dp[p][i][j]),dp[p][i][j]=0;
		}
		dp[p][i][j]=0;
	}
	print(ans);

	return 0;
}