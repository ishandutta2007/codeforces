#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int dp[N][N],n,D;
void dfs(int now,int father)
{
	for (int j=1;j<=n+1;j++) dp[now][j]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to,now);
		for (int j=1;j<=n+1;j++) dp[now][j]=1LL*dp[now][j]*dp[to][j]%p;
	}
	for (int j=1;j<=n+1;j++) dp[now][j]=(dp[now][j]+dp[now][j-1])%p;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),D=read();
	for (int i=2;i<=n;i++) add_edge(read(),i);
	dfs(1,0);
	int ans=0;
	for (int i=1;i<=n+1;i++)
	{
		int now=dp[1][i],ni=1;
		for (int j=1;j<=n+1;j++) if (i!=j) now=1LL*now*(D-j+p)%p,ni=1LL*ni*(i-j+p)%p;
		ans=(ans+1LL*now*power(ni,p-2))%p;
	}
	print(ans);
		
	return 0;
}