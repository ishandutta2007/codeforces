#include <bits/stdc++.h>

namespace IO
{
char gc()
{
#ifdef FREAD
	static char buf[1<<21], *P1 = buf, *P2 = buf;
	if(P1 == P2)
	{
		P1 = buf;
		P2 = buf + fread(buf, 1, 1<<21, stdin);
		if(P1 == P2) return EOF;
	}
	return *(P1++);
#else
	return getchar();
#endif
}
template<typename Tp> bool get1(Tp &x)
{
	bool neg = 0;
	char c = gc();
	while( c != EOF && (c < '0' || c > '9') && c != '-' ) c = gc();
	if(c == '-') c = gc(), neg = 1;
	if(c == EOF) return false;
	x = 0;
	for(; c>='0' && c<='9'; c = gc()) x = x*10 + c - '0';
	if(neg) x = -x;
	return true;
}
template<typename Tp> void printendl(Tp x)
{
	if(x<0)putchar('-'),x=-x;
	static short a[40], sz;
	sz = 0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	puts("");
}
} // namespace IO
using IO::get1;
using IO::printendl;
#define get2(x,y) get1(x) && get1(y)
#define get3(x,y,z) get2(x,y) && get1(z)
#define get4(x,y,z,w) get3(x,y,z) && get1(w)
#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
typedef long long LL;
typedef unsigned long long uLL;
typedef std::pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const LL Linf = 1ll<<61;

namespace Tree
{
constexpr int maxn = 200111;
std::vector<int> g[maxn], l[maxn];
void addedge(int u, int v, int w=1)
{
	g[u].push_back(v); l[u].push_back(w);
	g[v].push_back(u); l[v].push_back(w);
}
int dist[maxn];
int dfn[maxn], edfn[maxn], dep[maxn], timer, fa[20][maxn], seq[maxn];
void dfs(int x, int f = 0)
{
	fa[0][x] = f;
	for(int i=1; i<20; i++) fa[i][x] = fa[i-1][fa[i-1][x]];
	dfn[x] = ++timer;
	seq[timer] = x;
	for(int i=0; i<(int)g[x].size(); i++) if(g[x][i] != f)
	{
		dep[g[x][i]] = dep[x] + 1;
		dist[g[x][i]] = dist[x] + l[x][i];
		dfs(g[x][i], x);
	}
	edfn[x] = timer;
}
void prework(int n)
{
	memset(dfn, 0, sizeof(int)*(n+10));
	timer = 0;
	for(int i=1; i<=n; i++) if(!dfn[i])
		dfs(i);
}
int getlca(int u, int v)
{
	if(dep[u] < dep[v]) std::swap(u, v);
	for(int i=19; i>=0; i--) if((dep[u]-dep[v])>>i) u = fa[i][u];
	if(u == v) return u;
	for(int i=19; i>=0; i--) if(fa[i][u] != fa[i][v]) u = fa[i][u], v=fa[i][v];
	return fa[0][u];
}
int getdist(int u, int v)
{
	if(dfn[u] > dfn[v]) std::swap(u, v);
	if(edfn[u] >= dfn[v]) return dist[v] - dist[u];
	else return dist[u] + dist[v] - 2*dist[getlca(u, v)];
}
std::vector<std::pair<std::pair<int,int>,int>> extract(std::vector<int> &vs)
{
	std::sort(vs.begin(), vs.end(), [](int x, int y){return dfn[x] < dfn[y];});
	vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
	for(int i=vs.size()-1; i>=1; i--)
	{
		int lca = getlca(vs[i], vs[i-1]);
		if(lca) vs.push_back(getlca(vs[i], vs[i-1]));
	}
	std::sort(vs.begin(), vs.end(), [](int x, int y){return dfn[x] < dfn[y];});
	vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
	
	static int stk[maxn], top;
	top = 0;
	std::vector<std::pair<std::pair<int,int>,int>> ret;
	for(auto x:vs)
	{
		while(top && edfn[stk[top]] < dfn[x]) top--;
		if(top) ret.emplace_back(std::make_pair(x, stk[top]), dist[x] - dist[stk[top]]);
		stk[++top] = x;
	}
	assert(vs.size() == ret.size() + 1);
	return ret;
}
} // namespace Tree

const int maxn = 200111;
std::vector<int> g[maxn];
int n, q, k, m, virus[maxn], speed[maxn], qs[maxn];

int infected[maxn], rounds[maxn];
void update(int u, int id)
{
	int dist = Tree::getdist(u, virus[id]);
	dist = (dist + speed[id] - 1) / speed[id];
	if(mp(dist, id) <= mp(rounds[u], infected[u]))
	{
		infected[u] = id;
		rounds[u] = dist;
	}
}

void dfs(int x, int f = 0)
{
	for(int i=0; i<(int)g[x].size(); i++) if(g[x][i] != f)
	{
		dfs(g[x][i], x);
		if(infected[g[x][i]] != inf) update(x, infected[g[x][i]]);
	}
}
void dfs2(int x, int f = 0)
{
	for(int i=0; i<(int)g[x].size(); i++) if(g[x][i] != f)
	{
		update(g[x][i], infected[x]);
		dfs2(g[x][i], x);
	}
}

void solve()
{
	get2(k, m);
	std::vector<int> V;
	for(int i=1; i<=k; i++)
	{
		get2(virus[i], speed[i]);
		V.pb(virus[i]);
	}
	for(int i=1; i<=m; i++)
	{
		get1(qs[i]);
		V.pb(qs[i]);
	}
	auto E = Tree::extract(V);
	for(auto v:V)
	{
		g[v].clear();
		infected[v] = rounds[v] = inf;
	}
	for(auto e:E)
	{
		g[e.ff.ff].pb(e.ff.ss);
		g[e.ff.ss].pb(e.ff.ff);
	}
	
	for(int i=1; i<=k; i++) update(virus[i], i);
	int rt = V.front();
	dfs(rt);
	dfs2(rt);
	// printf("m= %d\n", m);
	for(int i=1; i<=m; i++) printf("%d%c", infected[qs[i]], i==m ? '\n':' ');
}

int main()
{
	get1(n);
	for(int i=1, u, v; i<n; i++)
	{
		get2(u, v);
		Tree::addedge(u, v);
	}
	Tree::prework(n);
	get1(q);
	while(q--) solve();
	return 0;
}