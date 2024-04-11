#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;
const int V=N*4;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[V];
int cnt,pre[N],suf[N],l[N],r[N];
void add_edge(int u,int v){e[u].push_back(v);}
int low[V],dfn[V],cntdfn=0,col[V],cntcol=0,st[V],top=0;
bool vis[V];
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
		}while (x!=now);
	}
}

signed main()
{
	int p=read(),n=read(),m=read(),q=read();
	cnt=n*2;
	for (int i=1;i<=p;i++)
	{
		int u=read(),v=read();
		add_edge(u+n,v);
		add_edge(v+n,u);
	}
	for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	for (int i=1;i<=q;i++)
	{
		int u=read(),v=read();
		add_edge(u,v+n);
		add_edge(v,u+n);
	}
	for (int i=1;i<=m;i++) pre[i]=++cnt;
	for (int i=1;i<=m;i++) suf[i]=++cnt;
	for (int i=1;i<m;i++) add_edge(pre[i+1],pre[i]);
	for (int i=1;i<m;i++) add_edge(suf[i],suf[i+1]);
	for (int i=1;i<=n;i++) add_edge(suf[l[i]],i+n);
	for (int i=1;i<=n;i++) add_edge(pre[r[i]],i+n);
	for (int i=1;i<=n;i++) if (l[i]>1) add_edge(i,pre[l[i]-1]);
	for (int i=1;i<=n;i++) if (r[i]<m) add_edge(i,suf[r[i]+1]);
	for (int i=1;i<=cnt;i++) if (!dfn[i]) tarjan(i);
	int L=1,R=m;
	vector<int>ans;
	for (int i=1;i<=n;i++)
	{
		if (col[i]==col[i+n]) return puts("-1"),0;
		if (col[i]<col[i+n]) L=max(L,l[i]),R=min(R,r[i]),ans.push_back(i);
	}
	print(ans.size(),' '),print(L);
	for (int i:ans) print(i,' ');
	
	return 0;
}