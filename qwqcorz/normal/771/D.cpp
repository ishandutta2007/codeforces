#include<bits/stdc++.h>
using namespace std;
const int N=80;

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
inline void up(int &x,int y){if (x>y) x=y;}
char s[N];
int a[N],dp[N][N][N],V[N],K[N],sum[N][N];
int pv[N],pk[N],p[N],n1=0,n2=0,n3=0;

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	scanf("%s",s+1);
	s[++n]='A';
	for (int i=1;i<=n;i++)
	if (s[i]=='V') a[i]=1,pv[++n1]=i;
	else if (s[i]=='K') a[i]=2,pk[++n2]=i;
	else a[i]=0,p[++n3]=i;
	for (int i=1;i<=n2;i++)
	for (int k=0;k<=n1;k++)
	for (int j=1;j<=n1;j++)
	if (j<=k?pk[i]<pv[j]:pk[i]>pv[j]) sum[i][k]++;
	for (int i=1;i<=n2;i++)
	for (int j=0;j<=n1;j++) sum[i][j]+=sum[i-1][j];
	for (int i=1;i<=n3;i++)
	for (int j=1;j<p[i];j++)
	{
		if (a[j]==1) V[i]++;
		if (a[j]==2) K[i]++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=0;i<=n1;i++)
	for (int j=0;j<=n2;j++)
	for (int k=1;k<=n3;k++)
	for (int x=0;x<=i;x++)
	for (int y=0;y<=j;y++)
	up(dp[i][j][k],dp[x][y][k-1]+abs(V[k]-i)+abs(K[k]-j)+sum[j][x]-sum[y][x]);
	print(dp[n1][n2][n3]);
	
	return 0;
}