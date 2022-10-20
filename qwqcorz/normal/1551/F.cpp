#include<bits/stdc++.h>
using namespace std;
const int N=105;
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
}e[N];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
void clear()
{
	cnte=0;
	memset(head,0,sizeof(head));
}
vector<int>a[N];
int dp[N],deep[N],tot[N];
int dfs(int now,int father)
{
	tot[deep[now]=deep[father]+1]++;
	int ret=deep[now];
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		ret=max(ret,dfs(to,now));
	}
	return ret;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),k=read(),ans=0;
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		if (k==2) {print(n*(n-1)/2),clear();continue;}
		for (int rt=1;rt<=n;rt++)
		{
			deep[rt]=0;
			for (int i=head[rt];i;i=e[i].nxt)
			{
				int to=e[i].to,maxdeep=dfs(to,rt);
				for (int j=1;j<=maxdeep;j++)
				{
					a[j].push_back(tot[j]);
					tot[j]=0;
				}
			}
			for (int i=1;i<=n;i++)
			if (!a[i].empty())
			{
				memset(dp,0,sizeof(dp));
				dp[0]=1;
				for (int x:a[i])
				for (int j=n;j>=1;j--) dp[j]=(dp[j]+1LL*dp[j-1]*x)%p;
				ans=(ans+dp[k])%p;
				a[i].clear();
			}
		}
		print(ans);
		clear();
	}
	
	return 0;
}