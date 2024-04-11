#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;

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
namespace sat
{
	const int N=4e5+5;
	struct edge
	{
		int to,nxt;
	}e[N*2];
	int head[N],cnte;
	void add_edge(int u,int v)
	{
		e[++cnte].to=v;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	bool vis[N],is[N],c[N];
	int dfn[N],low[N],cntdfn,st[N],top,col[N],cntcol,cnt,n;
	void tarjan(int now)
	{
		low[now]=dfn[now]=++cntdfn;
		st[++top]=now;
		vis[now]=1;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
			else if (vis[to]) low[now]=min(low[now],dfn[to]);
		}
		if (low[now]==dfn[now])
		{
			int tmp=++cntcol,x;
			do
			{
				x=st[top--];
				vis[x]=0;
				col[x]=tmp;
			}while (x!=now);
		}
	}
	int get(int now)
	{
		if (is[now%n]) return 0;
		is[now%n]=1;
		cnt++;
		st[++top]=now;
		c[now%n]=now<=n;
		int ret=c[now%n];
		for (int i=head[now];i;i=e[i].nxt) ret+=get(e[i].to);
		return ret;
	}
	void clear()
	{
		cntdfn=cntcol=top=cnte=0;
		for (int i=0;i<=n*2;i++)
		dfn[i]=low[i]=st[i]=col[i]=head[i]=vis[i]=is[i]=c[i]=0;
	}
	int solve(int x)
	{
		cnt=top=0;
		int tmp=get(x);
		if (tmp>cnt-tmp)
		{
			tmp=cnt-tmp;
			while (top) c[st[top--]%n]^=1;
		}
		return tmp;
	}
}
int a[2][N];
vector<pair<int,int> >t[N];
bool solve()
{
	int n=sat::n=read();
	sat::clear();
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=0;i<=1;i++)
	for (int j=1;j<=n;j++) t[a[i][j]=read()].push_back(mk(i,j));
	for (int i=1;i<=n;i++) if ((int)t[i].size()!=2) return 0;
	for (int i=1;i<=n;i++)
	{
		int x=t[i][0].se,y=t[i][1].se;
		if (x==y) continue;
		if (t[i][0].fi==t[i][1].fi)
			sat::add_edge(x,y+n),
			sat::add_edge(y+n,x),
			sat::add_edge(y,x+n),
			sat::add_edge(x+n,y);
		else
			sat::add_edge(x,y),
			sat::add_edge(y,x),
			sat::add_edge(y+n,x+n),
			sat::add_edge(x+n,y+n);
	}
	for (int i=1;i<=n+n;i++) if (!sat::dfn[i]) sat::tarjan(i);
	for (int i=1;i<=n;i++) if (sat::col[i]==sat::col[i+n]) return 0;
	int ans=0;
	for (int i=1;i<=n;i++) if (!sat::is[i%n]) ans+=sat::solve(i);
	print(ans);
	for (int i=1;i<=n;i++) if (sat::c[i%n]) print(i,' ');
	putchar('\n');
	return 1;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--) if (!solve()) puts("-1");
	
	return 0;
}