#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m;
char a[N];
vector<int>e[N],id[N];
void add_edge(int u,int v)
{
	if (u<0) u=n-u;
	if (v<0) v=n-v;
	e[u].push_back(v);
}
int low[N],dfn[N],cntdfn=0,st[N],top=0,col[N],cntcol=0;
bool vis[N];
void tarjan(int now)
{
	low[now]=dfn[now]=++cntdfn;
	st[++top]=now;
	vis[now]=1;
	for (int to:e[now])
	if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
	else if (vis[to]) low[now]=min(low[now],dfn[to]);
	if (low[now]==dfn[now])
	{
		int c=++cntcol,x;
		do
		{
			x=st[top--];
			col[x]=c;
			vis[x]=0;
			id[c].push_back(x);
		}while (x!=now);
	}
}
bool dp[N];
void clear(int n)
{
	for (int i=1;i<=n;i++)
	{
		e[i].clear();
		id[i].clear();
		low[i]=dfn[i]=st[i]=col[i]=vis[i]=dp[i]=0;
	}
	cntdfn=top=cntcol=0;
}
bool MyGeneration()
{
	n=read(),m=read();
	clear(n*2);
	scanf("%s",a+1);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(-u,v);
		add_edge(-v,u);
	}
	for (int i=1;i<=n+n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++) if (col[i]==col[i+n]) return 0;
	for (int i=1;i<=cntcol;i++)
	{
		int tot=0;
		for (int j:id[i]) if (a[j>n?j-n:j]=='A') tot++;
		if (tot>1) return 0;
		if (tot)
		{
			int mn=n*2;
			for (int j:id[i]) mn=min(mn,j>n?j-n:j);
			if (a[mn]!='A') return 0;
		}
		for (int j:id[i])
		for (int to:e[j]) if (col[to]<i) dp[i]|=dp[col[to]];
		if (dp[i]&&tot) return 0;
		dp[i]|=tot;
	}
	return 1;
}

signed main()
{
	int T=read();
	while (T--) puts(MyGeneration()?"TRUE":"FALSE");
	
	return 0;
}