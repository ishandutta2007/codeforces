#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int p=1e9+7;
const int inv2=(p+1)/2;

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
int lca[N][N],deep[N],dp[N][N];
void dfs0(int now,int father)
{
	deep[now]=deep[father]+1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
	}
}
void dfs1(int st,int now,int father,int x)
{
	if (deep[x]>deep[now]) x=now;
	lca[st][now]=x;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs1(st,to,now,x);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),ans=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=n;i++) dp[i][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) dp[i][j]=1LL*inv2*(dp[i][j-1]+dp[i-1][j])%p;
	for (int i=1;i<=n;i++)
	{
		dfs0(i,0);
		for (int j=1;j<=n;j++) dfs1(j,j,0,j);
		for (int x=1;x<=n;x++)
		for (int y=x+1;y<=n;y++)
		{
			int z=lca[x][y],u=deep[x]-deep[z],v=deep[y]-deep[z];
			ans=(ans+dp[u][v])%p;
		}
	}
	print(1LL*ans*power(n,p-2)%p);
	
	return 0;
}