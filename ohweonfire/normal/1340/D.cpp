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
std::vector<int> g[maxn];
std::vector<pii> cmd;
int n, mx;

void dfs(int x, int f, int st, int fi)
{
	cmd.emplace_back(x, st);
	int length = g[x].size() + 1, vl, vr;
	if(fi + length - 1 <= mx) vl = fi, vr = fi + length - 1;
	else vl = mx - length + 1, vr = mx;
	for(auto v : g[x]) if(v != f)
	{
		if(x > 1 && st == vr) cmd.emplace_back(x, st = vl);
		dfs(v, x, st + 1, st);
		cmd.emplace_back(x, ++st);
		if(x > 1 && st == vr) cmd.emplace_back(x, st = vl);
	}
	if(x > 1 && st == vr) cmd.emplace_back(x, st = vl);
	if(x > 1) assert(st == fi);
}

int main()
{
	get1(n);
	if(n == 1)
	{
		puts("1");
		puts("1 0");
		return 0;
	}
	
	for(int i=1, u, v; i<n; i++)
	{
		get2(u, v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1; i<=n; i++) mx = std::max(mx, (int)g[i].size());
	dfs(1, 0, 0, mx);
	printf("%d\n", cmd.size());
	for(auto v : cmd) printf("%d %d\n", v.ff, v.ss);
	return 0;
}