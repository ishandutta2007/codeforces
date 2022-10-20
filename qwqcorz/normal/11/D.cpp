#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
const int S=(1<<19)+5;

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
bool e[N][N];
int dp[S][N],lowbit[S];

signed main()
{
	memset(e,0,sizeof(e));
	memset(dp,0,sizeof(dp));
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u][v]=e[v][u]=1;
	}
	for (int i=1;i<=n;i++) dp[1<<(i-1)][i]=1;
	for (int i=0;i<(1<<n);i++)
	for (int j=1;j<=n;j++)
	if (i&(1<<(j-1)))
	{
		lowbit[i]=j;
		break;
	}
	for (int i=1;i<(1<<n);i++)
	for (int j=1;j<=n;j++)
	if ((i&(1<<(j-1)))&&dp[i][j])
	for (int k=1;k<=n;k++)
	if (e[j][k])
	{
		if (k==lowbit[i]) ans+=dp[i][j];
		if (lowbit[i]<k&&!(i&(1<<(k-1)))) dp[i|(1<<(k-1))][k]+=dp[i][j];
	}
	print((ans-m)/2);

	return 0;
}