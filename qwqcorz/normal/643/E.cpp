#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
int fa[N],cnt=1,tmp[65];
double dp[N][65];

signed main()
{
	for (int i=0;i<=60;i++) dp[1][i]=1;
	int Q=read();
	for (int t=1;t<=Q;t++)
	{
		int opt=read(),x=read();
		if (opt==1)
		{
			int top=0;
			fa[++cnt]=x;
			for (int i=0;i<=60;i++) dp[cnt][i]=1;
			for (int i=1;i<=60&&fa[x];i++,x=fa[x]) top=i,tmp[i]=x;
			#define x tmp[i]
			for (int i=top;i>=1;i--) dp[fa[x]][i]/=0.5*(1+dp[x][i-1]);
			dp[fa[cnt]][0]/=2;
			for (int i=1;i<=top;i++) dp[fa[x]][i]*=0.5*(1+dp[x][i-1]);
			#undef x
		}
		else
		{
			double ans=0;
			for (int i=1;i<=60;i++) ans+=i*(dp[x][i]-dp[x][i-1]);
			printf("%lf\n",ans);
		}
	}
	
	return 0;
}