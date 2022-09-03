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

const int maxn = 200111;

std::vector<int> g[maxn];
int n, dep[maxn];

void dfs(int x, int f, int d)
{
	dep[x] = d;
	for(auto v : g[x]) if(v != f) dfs(v, x, d^1);
}

int main()
{
	get1(n);
	for(int i=1, u, v; i<n; i++)
	{
		get2(u, v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	std::vector<int> leaf;
	std::set<int> bad;
	for(int i=1; i<=n; i++) if((int)g[i].size() == 1)
	{
		leaf.pb(i);
		bad.insert(g[i][0]);
	}
	dfs(1, 0, 0);
	
	int ans1 = 1, ans2 = n - 1 - leaf.size() + bad.size();
	for(int i=1; i<leaf.size(); i++) if(dep[leaf[0]] != dep[leaf[i]]) ans1 = 3;
	
	printf("%d %d\n", ans1, ans2);
	return 0;
}