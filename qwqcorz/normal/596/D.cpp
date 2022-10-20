#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int inf=1e9+7;

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
int a[N],n,h;
double p[2],dp[N][N][2][2];
int cost(int l,int r,int x,int y,int pos,int f)
{
	int L=a[l-1]+x*h,R=a[r+1]-!y*h;
	int le=max(a[pos]-!f*h,L),ri=min(a[pos]+f*h,R);
	return le<=ri?ri-le:0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),h=read();
	scanf("%lf",&p[0]),p[1]=1-p[0];
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	a[0]=-inf,a[n+1]=inf;
	for (int i=1;i<=n;i++)
	for (int j=1;j+i-1<=n;j++)
	for (int x=0;x<=1;x++)
	for (int y=0;y<=1;y++)
	{
		int l=j,r=j+i-1;
		if (a[l-1]+x*h>a[l]) {dp[l][r][x][y]=dp[l+1][r][x][y]+cost(l,r,x,y,l,x); continue;}
		if (a[r+1]-!y*h<a[r]) {dp[l][r][x][y]=dp[l][r-1][x][y]+cost(l,r,x,y,r,y); continue;}
		for (int k=0;k<=1;k++)
			dp[l][r][x][y]+=(dp[l+1][r][k][y]+cost(l,r,x,y,l,k))*0.5*p[k],
			dp[l][r][x][y]+=(dp[l][r-1][x][k]+cost(l,r,x,y,r,k))*0.5*p[k];
	}
	printf("%.10lf\n",dp[1][n][0][1]);
	
	return 0;
}