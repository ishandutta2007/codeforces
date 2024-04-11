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

const int maxn = 100111;
const int magic = 150;

std::mt19937 rng;
std::vector<int> g[maxn];
int n, m;

bool inst[maxn], use[maxn];
bool dfs(int x)
{
	inst[x] = use[x] = 1;
	for(int i=0; i<(int)g[x].size(); i++)
	{
		if(!use[g[x][i]])
		{
			if(!dfs(g[x][i]))
				return false;
		}
		else if(!inst[g[x][i]]) return false;
	}
	inst[x] = 0;
	return true;
}
bool check(int x)
{
	memset(use, 0, sizeof(bool) * (n + 1));
	memset(inst, 0, sizeof(bool) * (n + 1));
	return dfs(x);
}

int dfn[maxn], low1[maxn], low2[maxn], seq[maxn], timer;
void update(int x, int v)
{
	if(low1[x] > v)
	{
		low2[x] = low1[x];
		low1[x] = v;
	}
	else if(low2[x] > v) low2[x] = v;
}
bool good[maxn];
void dfs2(int x)
{
	dfn[x] = low1[x] = low2[x] = ++timer;
	seq[timer] = x;
	for(int i=0; i<(int)g[x].size(); i++)
	{
		if(!dfn[g[x][i]])
		{
			dfs2(g[x][i]);
			update(x, low1[g[x][i]]);
			update(x, low2[g[x][i]]);
		}
		else update(x, dfn[g[x][i]]);
	}
}

void solve()
{
	static int ord[maxn];
	get2(n, m);
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1, u, v; i<=m; i++)
	{
		get2(u, v);
		g[u].pb(v);
	}
	
	for(int i=1; i<=n; i++) ord[i] = i;
	std::shuffle(ord + 1, ord + n + 1, rng);
	
	int piv = 0;
	for(int i=1; i<=n && i<=magic; i++)
	{
		if(check(ord[i]))
		{
			piv = ord[i];
			break;
		}
	}
	if(piv == 0)
	{
		puts("-1");
		return;
	}
	memset(dfn, 0, sizeof(int) * (n + 1));
	timer = 0;
	dfs2(piv);
	
	for(int t=1; t<=n; t++)
	{
		int x = seq[t];
		if(x == piv) good[x] = 1;
		else if(low2[x] < dfn[x]) good[x] = 0;
		else good[x] = good[seq[low1[x]]];
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++) cnt += good[i];
	if(cnt * 5 < n) puts("-1");
	else
	{
		// printf("%d\n", cnt);
		for(int i=1; i<=n; i++) if(good[i]) printf("%d ", i);
		puts("");
	}
}

int main()
{
	rng = std::mt19937(std::chrono::steady_clock().now().time_since_epoch().count());
	int tc; get1(tc);
	while(tc--) solve();
	return 0;
}