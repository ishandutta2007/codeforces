#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int K=205;
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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int n,k,dp[N][K],f[K],S[K][K],siz[N],ans[K];
void dfs(int now,int father)
{
	dp[now][0]=2;
	siz[now]=1;
	for (int t=head[now];t;t=e[t].nxt)
	{
		int to=e[t].to;
		if (to==father) continue;
		dfs(to,now);
		memset(f,0,sizeof(f));
		for (int i=min(siz[now],k);i>=0;i--)
		for (int j=min(siz[to],k-i);j>=0;j--)
		add(f[i+j],1LL*dp[now][i]*dp[to][j]%p);
		for (int i=0;i<=k;i++) add(ans[i],p-dp[to][i]);
		memcpy(dp[now],f,sizeof(f));
		siz[now]+=siz[to];
	}
	for (int i=0;i<=k;i++) add(ans[i],dp[now][i]);
	for (int i=k;i>=1;i--) add(dp[now][i],dp[now][i-1]);
	add(dp[now][1],p-1);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=S[0][0]=1;i<=k;i++)
	for (int j=1;j<=i;j++) S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%p;
	dfs(1,0);
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=0;j<=k;j++)
//	print(dp[i][j],' ');
	int res=0;
	for (int i=0,fact=1;i<=k;fact=1LL*fact*(++i)%p) add(res,1LL*S[k][i]*fact%p*ans[i]%p);
	print(res);
	
	return 0;
}