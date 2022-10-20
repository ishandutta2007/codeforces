#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int LOG=20;
const int p=1e9+7;

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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int dp[N][LOG][2],pw2[LOG],pw3[2]={1,3};

signed main()
{
	for (int i=pw2[0]=1;i<LOG;i++) pw2[i]=pw2[i-1]*2;
	int n=read(),k=0;
	while ((1<<k)*2<=n) k++;
	dp[1][k][0]=1;
	if (k) dp[1][k-1][1]=(1<<k-1)*3<=n;
	for (int i=1;i<n;i++)
	for (int j=0;j<=k;j++)
	for (int t=0;t<=1;t++)
	if (dp[i][j][t])
	{
		int now=pw2[j]*pw3[t];
		add(dp[i+1][j][t],1LL*dp[i][j][t]*(n/now-i)%p);
		if (j) add(dp[i+1][j-1][t],1LL*dp[i][j][t]*(n/(now/2)-n/now)%p);
		if (t) add(dp[i+1][j][0],1LL*dp[i][j][t]*(n/(now/3)-n/now)%p);
	}
	print(dp[n][0][0]);
	
	return 0;
}