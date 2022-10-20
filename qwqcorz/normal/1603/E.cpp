#include<bits/stdc++.h>
using namespace std;
const int N=205;

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
int dp[N][N][N],n,p,C[N][N];
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
void TheBeatles()
{
	int ans=0;
	n=read(),p=read();
	for (int i=C[0][0]=1;i<N;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	for (int a1=max(n-(int)sqrt(n)*2-2,1);a1<=n+1;a1++)
	{
		memset(dp,0,sizeof(dp));
		dp[1][0][0]=1;
		for (int i=1;i<=n;i++)
		for (int j=0;j<=n+1-a1;j++)
		for (int k=0;k<=a1;k++)
		if (dp[i][j][k])
		for (int t=0;i+t<=min(n,j<=n-a1?max(j,1)+a1-1:N)&&k+t*j<=a1;t++)
		add(dp[i+t][j+1][k+t*j],1LL*dp[i][j][k]*C[i+t][t+(j==0)]%p);
		for (int k=0;k<=a1;k++) add(ans,dp[n][n+2-a1][k]);
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) TheBeatles();
	
	return 0;
}