// cwt random_shuffle OI  
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
int fa[N],dp[N],tot[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
// 	freopen("c.in","r",stdin);
// 	freopen("c.out","w",stdout);
	
	dp[1]=0;
	int n=read()+1,now;
	for (int i=2;i<=n;i++)
	{
		dp[i]=1;
		fa[i]=read();
		for (now=i;fa[now]>1;)
		if (dp[now]>dp[fa[now]])
		{
			now=fa[now];
			dp[now]++;
			tot[now]=1;
		}
		else if (dp[now]==dp[fa[now]]&&++tot[fa[now]]>=2)
		{
			now=fa[now];
			dp[now]++;
			tot[now]=0;
		}
		else break;
		if (fa[now]==1) dp[1]=max(dp[1],dp[now]);
//		for (int i=1;i<=n;i++) print(dp[i]," \n"[i==n]);
		print(dp[1],' ');
	}
	
	return 0;
}