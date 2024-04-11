#include<bits/stdc++.h>
using namespace std;
const int S=1<<22;

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
void up(int &x,int y){x=max(x,y);}
int dp[2][S];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),x=read(),y=read(),m=x+y,S=1<<max(x,y);
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=m;i++)
	{
		int t=i&1;
		memset(dp[t],0xc0,sizeof(dp[t]));
		for (int j=0;j<S;j++)
		{
			up(dp[t][(j<<1)&(S-1)],dp[!t][j]);
			if (j>>(x-1)&1) continue;
			if (j>>(y-1)&1) continue;
			up(dp[t][(j<<1|1)&(S-1)],dp[!t][j]+n/m+(n%m>=i));
		}
	}
	int ans=0;
	for (int j=0;j<S;j++) up(ans,dp[m&1][j]);
	print(ans);
	
	return 0;
}