#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int p=998244353;

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
inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int siz[N],dp[N][N],tmp[N],n,k,ans=0;
void dfs(int now,int father)
{
	siz[now]=dp[now][0]=1;
	for (int t=head[now];t;t=e[t].nxt)
	{
		int to=e[t].to;
		if (to==father) continue;
		dfs(to,now);
		memset(tmp,0,sizeof(tmp));
		for (int i=min(siz[now]-1,k);i>=0;i--)
		for (int j=min(siz[to]-1,k);j>=0;j--)
		{
			if (i+j+1<=k) add(tmp[max(i,j+1)],1LL*dp[now][i]*dp[to][j]%p);
			add(tmp[i],1LL*dp[now][i]*dp[to][j]%p);
		}
		memcpy(dp[now],tmp,sizeof(tmp));
		siz[now]+=siz[to];
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	for (int i=0;i<=k;i++) add(ans,dp[1][i]);
	print(ans);
//	for (int i=1;i<=n;i++,puts(""))
//	for (int j=0;j<=k;j++) print(dp[i][j],' ');
	
	return 0;
}