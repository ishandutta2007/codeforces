#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=35;

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
inline int get(int x,int y) {return (x>>y)&1;}
int dp[N][2][2];
int solve(int n,int m)
{
	if (n<0||m<0) return 0;
	memset(dp,0,sizeof(dp));
	dp[31][1][1]=1;
	for (int i=30;i>=0;i--)
	for (int j=0;j<=1;j++)
	for (int k=0;k<=1;k++)
	for (int x=0;x<=(j?get(n,i):1);x++)
	for (int y=0;y<=(k?get(m,i):1);y++)
	if (x<1||y<1)
	dp[i][j&&x==get(n,i)][k&&y==get(m,i)]+=dp[i+1][j][k];
	int ret=0;
	for (int j=0;j<=1;j++)
	for (int k=0;k<=1;k++) ret+=dp[0][j][k];
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int l=read(),r=read();
		print(solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1));
	}
	
	return 0;
}