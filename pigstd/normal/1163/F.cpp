#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}
int min(int a,int b,int c){return min(min(a,b),c);}

const int inf=1e18;
const int M=2e5+10;
int n,m,q,dis[2][M],pre[2][M],vis[M],u[M],v[M],w[M],c[M],ans[M],l[M],r[M],t[M];
vector<int>e[M],e2[M];

void dij(int s,int tt)
{
	memset(dis[tt],0x3f,sizeof(dis[tt]));
	memset(vis,0,sizeof(vis));
	priority_queue<pii>q;
	dis[tt][s]=0;q.push(mp(0,s));
	while(!q.empty())
	{
		pii t=q.top();q.pop();
		if (vis[t.y])continue;vis[t.y]=1; 
		for (int x:e[t.y])
		{
			int V=(v[x]==t.y?u[x]:v[x]);
			if (dis[tt][V]>-t.x+w[x])
				pre[tt][V]=x,dis[tt][V]=-t.x+w[x],q.push(mp(-dis[tt][V],V));
		}
	}
}

struct segment_tree
{
	int val[M<<2],ed[M];
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		val[k]=inf;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int k,int L,int R,int l,int r,int z)
	{
		if (L>=l&&R<=r)return ckmin(val[k],z),void();
		if (L>r||R<l)return;
		int Mid=(L+R)>>1;
		upd(lson,L,Mid,l,r,z),upd(rson,Mid+1,R,l,r,z);
	}
	int query(int k)
	{
		k=ed[k];int res=inf;
		while(k!=0)ckmin(res,val[k]),k>>=1;
		return res;
	}
}T;

void dfs(int x)
{
	if (r[x])return;
	int V=(u[pre[1][x]]==x?v[pre[1][x]]:u[pre[1][x]]);
	if (pre[1][x]==0)return;
	dfs(V),r[x]=r[V];
}

int work(int t)
{
	if (!c[t])return dis[0][n];
	else return T.query(c[t]);
}

void dfs2(int u,int x,int fa=0)
{
	l[u]=x;
	for (auto v:e2[u])
		if (v!=fa)
			dfs2(v,t[v]?x+1:x,u);
}

signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		e[u[i]].pb(i),e[v[i]].pb(i);
	}
	dij(1,0),dij(n,1);
	int now=1,tot=0;r[1]=t[1]=1;
	while(now!=n)
		c[pre[1][now]]=++tot,now=(u[pre[1][now]]==now?v[pre[1][now]]:u[pre[1][now]]),r[now]=tot+1,t[now]=1;
	T.build(1,1,tot);
	for (int i=1;i<=n;i++)
		if (!r[i])dfs(i);
	for (int i=1;i<n;i++)
	{
		int V=(u[pre[1][i]]==i?v[pre[1][i]]:u[pre[1][i]]);
		e2[V].pb(i),e2[i].pb(V);
//		cout<<i<<' '<<V<<'\n';
	}
	dfs2(1,1);
	for (int i=1;i<=m;i++)
		if (!c[i])
		{
			int L=l[u[i]],R=r[v[i]]-1,W=w[i]+dis[0][u[i]]+dis[1][v[i]];
//			if (L<=R)cout<<i<<' '<<W<<' '<<L<<' '<<R<<'\n';
			if (L<=R)T.upd(1,1,tot,L,R,W);
			swap(u[i],v[i]),L=l[u[i]],R=r[v[i]]-1,W=w[i]+dis[0][u[i]]+dis[1][v[i]];
//			if (L<=R)cout<<i<<' '<<W<<' '<<L<<' '<<R<<'\n';
			if (L<=R)T.upd(1,1,tot,L,R,W);
		} 
//	for (int i=1;i<=n;i++)
//		if (!t[i])cout<<i<<' '<<l[i]<<' '<<r[i]-1<<'\n'; 
	while(q--)
	{
		int t=read(),x=read();
		if (x<w[t])cout<<min(dis[0][n],x+dis[0][u[t]]+dis[1][v[t]],x+dis[1][u[t]]+dis[0][v[t]])<<'\n';
		else cout<<min(dis[0][n]+x-w[t],work(t))<<'\n';
	}
	return 0;
}