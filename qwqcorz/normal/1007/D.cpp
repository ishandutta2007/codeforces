#include<bits/stdc++.h>
#define ll long long
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=1e5+5;
const int M=1e4+5;
const int V=M*100;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>t[N],e[V];
struct inter{int l,r;piir x;};
struct prefix{int l;piir x;};
vector<inter>a[N];
vector<prefix>b[N];
namespace sptree
{
	int siz[N],son[N],deep[N],fa[N],top[N],len[N];
	void dfs0(int now,int father)
	{
		siz[now]=1,son[now]=0;
		deep[now]=deep[fa[now]=father]+1;
		for (int to:t[now])
		{
			if (to==father) continue;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
		len[now]=len[son[now]]+1;
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (int to:t[now])
		{
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	void insert(int x,int y,int u,int v)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			b[top[x]].push_back((prefix){deep[x]-deep[top[x]],mk(u,v)});
			x=fa[top[x]];
		}
		if (deep[x]>deep[y]) swap(x,y);
		if (x!=y) a[top[x]].push_back((inter){deep[x]-deep[top[x]]+1,deep[y]-deep[top[x]],mk(u,v)});
	}
}
using namespace sptree;
inline void add_edge(int u,int v){e[u].push_back(v);}
int cnt,id[M][2];
vector<inter>k;
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
int in[N*4],out[N*4];
void build(int w,int l,int r)
{
	if (l==r)
	{
		in[w]=id[k[l].x.fi][!k[l].x.se];
		out[w]=id[k[l].x.fi][k[l].x.se];
		return;
	}
	in[w]=++cnt,out[w]=++cnt;
	build(ls,l,mid);
	build(rs,mid+1,r);
	add_edge(in[w],in[ls]);
	add_edge(in[w],in[rs]);
	add_edge(out[ls],out[w]);
	add_edge(out[rs],out[w]);
}
void add(int w,int l,int r,int ql,int qr,int x)
{
	if (ql<=l&&r<=qr)
	{
		add_edge(id[k[x].x.fi][k[x].x.se],in[w]);
		add_edge(out[w],id[k[x].x.fi][!k[x].x.se]);
		return;
	}
	if (ql<=mid) add(ls,l,mid,ql,qr,x);
	if (qr>mid) add(rs,mid+1,r,ql,qr,x);
}
#undef mid
#undef rs
#undef ls
void mySort(vector<prefix>&a,int n)
{
	static int cnt[N];
	for (int i=0;i<n;i++) cnt[i]=0;
	for (auto i:a) cnt[i.l]++;
	static vector<prefix>b[N];
	for (int i=0;i<n;i++) b[i].resize(cnt[i]);
	for (int i=0;i<n;i++) cnt[i]=0;
	for (auto i:a) b[i.l][cnt[i.l]++]=i;
	int t=0;
	for (int i=0;i<n;i++)
	for (auto j:b[i])
	a[t++]=j;
}
void solve(int n,vector<inter>&a,vector<prefix>&b)
{
//	puts("X");
//	for (auto i:a) print(i.l,','),print(i.r);
//	for (auto i:b) print(i.l,':'),print(i.x.fi,','),print(i.x.se);
//	puts("Y");
	int n1=a.size(),n2=b.size();
	sort(a.begin(),a.end(),[&](inter a,inter b){
		return a.r<b.r;
	});
	mySort(b,n);
	k=a;
	if (n1)
	{
		build(1,0,n1-1);
		for (int i=0;i<n1;i++)
		{
			int pos=lower_bound(a.begin(),a.end(),a[i].l,[&](inter a,int b){
				return a.r<b;
			})-a.begin();
			if (pos<i) add(1,0,n1-1,pos,i-1,i);
		}
	}
	static int pre[N][2],suf[N][2];
	for (int i=0;i<n2;i++)
	for (int j=0;j<=1;j++) pre[i][j]=++cnt;
	for (int i=0;i<n2;i++)
	for (int j=1;j<=1;j++) suf[i][j]=++cnt;
	for (int i=1;i<n2;i++)
	for (int j=0;j<=1;j++) add_edge(pre[i][j],pre[i-1][j]);
	for (int i=1;i<n2;i++)
	for (int j=1;j<=1;j++) add_edge(suf[i-1][j],suf[i][j]);
	for (int i=0;i<n2;i++)
		add_edge(id[b[i].x.fi][b[i].x.se],pre[i][0]),
//		add_edge(id[b[i].x.fi][b[i].x.se],suf[i][0]),
		add_edge(pre[i][1],id[b[i].x.fi][!b[i].x.se]),
		add_edge(suf[i][1],id[b[i].x.fi][!b[i].x.se]);
	sort(a.begin(),a.end(),[&](inter a,inter b){
		return a.l<b.l;
	});
	for (int i=n1-1,j=n2-1;i>=0;i--)
	{
		while (j>=0&&b[j].l>=a[i].l) j--;
		if (j+1<n2)
			add_edge(id[a[i].x.fi][a[i].x.se],suf[j+1][1]),
			add_edge(pre[j+1][0],id[a[i].x.fi][!a[i].x.se]);
	}
	for (int i=0;i<n2;i++)
	{
		if (i) add_edge(id[b[i].x.fi][b[i].x.se],pre[i-1][1]);
		if (i+1<n2) add_edge(id[b[i].x.fi][b[i].x.se],suf[i+1][1]);
	}
}
namespace scc
{
	int dfn[V],low[V],cntdfn=0,st[V],top=0,col[V],cntcol=0,vis[V];
	void tarjan(int now)
	{
		low[now]=dfn[now]=++cntdfn;
		st[++top]=now,vis[now]=1;
		for (int to:e[now])
		if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
		if (low[now]==dfn[now])
		{
			int c=++cntcol,x;
			do
			{
				x=st[top--];
				vis[x]=0;
				col[x]=c;
			}while (x!=now);
		}
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		t[u].push_back(v);
		t[v].push_back(u);
	}
	dfs0(1,0);
	dfs1(1,0,1);
	int m=read();
	cnt=m*2;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),u=read(),v=read();
		id[i][0]=i,id[i][1]=i+m;
		insert(x,y,i,0);
		insert(u,v,i,1);
	}
	for (int i=1;i<=n;i++) if (top[i]==i) solve(len[i],a[i],b[i]);
	for (int i=1;i<=cnt;i++) if (!scc::dfn[i]) scc::tarjan(i);
	for (int i=1;i<=m;i++) if (scc::col[i]==scc::col[i+m]) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=m;i++) putchar("21"[scc::col[i]<scc::col[i+m]]),putchar('\n');
	
	return 0;
}