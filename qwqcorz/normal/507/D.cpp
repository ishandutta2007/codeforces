#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=105;

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
int n,m,p;
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int dp[N][M][2][2],ans=0;
void GreenDay()
{
	n=read(),m=read(),p=read();
	dp[0][0][0][0]=1;
	for (int i=0,pw=1;i<n;i++,pw=pw*10LL%m)
	for (int j=0;j<m;j++)
	for (int x=0;x<=1;x++)
	for (int y=0;y<=1;y++)
	for (int t=i+1==n;t<=9;t++)
	add(dp[i+1][(j+t*pw)%m][x||((j+t*pw)%m==0&&(y||t))][y||t],dp[i][j][x][y]);
	for (int j=0;j<m;j++) add(ans,dp[n][j][1][1]);
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}