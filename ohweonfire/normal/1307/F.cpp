#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const int maxn=200111;

int head[maxn],nxt[maxn<<1],to[maxn<<1],etot=1;
void addedge(int u,int v)
{
	nxt[++etot]=head[u];head[u]=etot;to[etot]=v;
	nxt[++etot]=head[v];head[v]=etot;to[etot]=u;
}

int n,m,X,q[maxn],fa[maxn],bfn[maxn];
bool mark[maxn];
void bfs()
{
	int fr=1,rr=1;q[rr++]=1;
	for(;fr<rr;fr++)
	{
		int x=q[fr];
		bfn[x]=fr;
		for(int i=head[x];i;i=nxt[i])if(to[i]!=fa[x])
		{
			fa[to[i]]=x;
			q[rr++]=to[i];
		}
	}
}
namespace centroid
{
	bool use[maxn];int sz[maxn];
	int seq[maxn],tot;
	void dfs1(int x,int f=0)
	{
		seq[++tot]=x;sz[x]=1;
		for(int i=head[x];i;i=nxt[i])if(to[i]!=f&&!use[to[i]])
		{
			dfs1(to[i],x);
			sz[x]+=sz[to[i]];
		}
	}
	int getroot(int x)
	{
		tot=0;dfs1(x);
		x=0;for(int i=1;i<=tot;i++)if(sz[seq[i]]*2>=tot&&(x==0||sz[x]>sz[seq[i]]))x=seq[i];
		return x;
	}
	
	int dep[maxn];
	bool cmp(int x,int y){return dep[x]<dep[y];}
	void dfs(int x,int f=0,int d=0)
	{
		dep[x]=d;
		for(int i=head[x];i;i=nxt[i])if(to[i]!=f&&!use[to[i]])dfs(to[i],x,d+1);
	}
	
	int fa[20][maxn], d[20][maxn], lv[maxn];
	std::vector<pii> all[maxn];
	void solve(int rt, int lvl)
	{
		rt=getroot(rt);
		lv[rt] = lvl;
		dfs(rt);
		for(int i=1; i<=tot; i++)
		{
			fa[lvl][seq[i]] = rt;
			d[lvl][seq[i]] = dep[seq[i]];
			if(mark[seq[i]]) all[rt].pb(mp(dep[seq[i]], bfn[seq[i]]));
		}
		sort(all[rt].begin(),all[rt].end());
		for(int i=1;i<all[rt].size();i++) all[rt][i].ss = min(all[rt][i].ss, all[rt][i-1].ss);
		use[rt]=1;
		for(int i=head[rt];i;i=nxt[i])if(!use[to[i]])solve(to[i], lvl+1);
	}
	int query(int x)
	{
		int ret = inf;
		for(int i = lv[x]; i>=0; i--)
		{
			int rt = fa[i][x], dep = d[i][x];
			int pos = lower_bound(all[rt].begin(), all[rt].end(), mp(X - dep, inf)) - all[rt].begin() - 1;
			if(pos >= 0) ret=min(ret, all[rt][pos].ss);
		}
		return ret;
	}
	int query_dist(int x, int y)
	{
		for(int i=lv[x]; i>=0; i--)
		{
			if(fa[i][x] == fa[i][y]) return d[i][x] + d[i][y];
		}
	}
	void decomp()
	{
		memset(use,0,sizeof(use));
		solve(1, 0);
	}
}

int f[maxn], up[maxn];
int gf(int x) { return x == f[x] ? x : f[x] = gf(f[x]); }

int query(int a, int b)
{
	if(centroid::query_dist(a,b) <= X) return true;
	int k1 = centroid::query(a), k2 = centroid::query(b);
	if(k1 <= n && k2 <= n && gf(q[k1]) == gf(q[k2])) return true;
	if(k1 <= n && centroid::query_dist(gf(q[k1]), b) <= X) return true;
	if(k2 <= n && centroid::query_dist(gf(q[k2]), a) <= X) return true;
	return false;
}

int main()
{
	scanf("%d%d%d",&n,&X,&m);
	for(int i=1, u,v; i<n; i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	bfs();
	for(int i=1, x; i<=m; i++)
	{
		scanf("%d", &x);
		mark[x] = 1;
	}
	centroid::decomp();
	for(int i=1; i<=n; i++) f[i] = i;
	for(int i=1; i<=n; i++) if(mark[i])
	{
		int qq = centroid::query(i);
		if(qq<=n)
		{
			qq = q[qq];
			f[gf(i)] = gf(qq);
		}
	}
	int qv;
	scanf("%d", &qv);
	for(int i=1, a, b; i<=qv; i++)
	{
		scanf("%d%d",&a,&b);
		if(query(a,b)) puts("YES");
		else puts("NO");
	}
	return 0;
}