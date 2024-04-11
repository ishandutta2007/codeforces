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

using namespace std;

const int maxn = 1111;
int n, eu[maxn], ev[maxn];
int ask(int u, int v)
{
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int ret;
	get1(ret);
	return ret;
}

vector<int> g[maxn];
bool use[maxn];
int fa[maxn], dep[maxn], mxv;
void dfs(int x, int f=0, int d=1)
{
	fa[x] = f;
	dep[x] = d;
	if(dep[mxv] < dep[x]) mxv = x;
	for(auto v:g[x]) if(v!=f&&!use[v])
	{
		dfs(v,x,d+1);
	}
}

vector<int> vs;
void get_diameter(int cur)
{
	mxv = 0;
	dfs(cur);
	cur = mxv;
	mxv = 0;
	dfs(cur);
	vs.clear();
	while(mxv)
	{
		vs.pb(mxv);
		mxv = fa[mxv];
	}
}

int main()
{
	get1(n);
	for(int i=1; i<n; i++)
	{
		int u, v;
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	int cur = 1;
	while(true)
	{
		get_diameter(cur);
		if(vs.size() == 1) break;
		cur = ask(vs.front(), vs.back());
		for(int i=0; i<vs.size(); i++) if(vs[i] != cur) use[vs[i]] = 1;
	}
	printf("! %d\n", cur);
	return 0;
}