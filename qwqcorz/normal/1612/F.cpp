#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int LOG=40;

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
void up(int &x,int y){if (x<y) x=y;}
int dp[LOG+1][N],a[N*2],b[N*2];
unordered_set<int>e[N*2];
void GreenDay()
{
	int n=read(),m=read(),k=read(),ans=1145141;
	for (int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		e[x].insert(y);
	}
	for (int i=n-1;i>=1;i--) a[i]=a[i+m+e[i].count(m)]+1;
	for (int i=m-1;i>=1;i--) b[i]=b[n+i+e[n].count(i)]+1;
	dp[0][1]=1;
	for (int j=0;j<LOG;j++)
	{
		if (j>=ans) break;
		for (int i=1;i<=n;i++)
		if (dp[j][i])
		{
			if (i==n)
			{
				ans=min(ans,j+b[dp[j][i]]);
				continue;
			}
			if (dp[j][i]==m)
			{
				ans=min(ans,j+a[i]);
				continue;
			}
			int nxt=i+dp[j][i]+e[i].count(dp[j][i]);
			int A=min(nxt,n),B=min(nxt,m);
			up(dp[j+1][A],dp[j][i]);
			up(dp[j+1][i],B);
		}
	}
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