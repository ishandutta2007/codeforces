#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;

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
inline void up(int &x,int y){x=max(x,y);}
int a[N],b[N],c[N],d[N],dp[N][N];
vector<int>v[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read(),d[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		d[v]=max(d[v],u);
	}
	for (int i=1;i<=n;i++) v[d[i]].push_back(c[i]);
	memset(dp,0xc0,sizeof(dp));
	dp[0][k]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=a[i];j+b[i]<=5000;j++) dp[i][j+b[i]]=dp[i-1][j];
		for (int k:v[i])
		for (int j=1;j<=5000;j++)
		up(dp[i][j-1],dp[i][j]+k);
	}
	int ans=-1;
	for (int j=0;j<=5000;j++) up(ans,dp[n][j]);
	print(ans);
	
	return 0;
}