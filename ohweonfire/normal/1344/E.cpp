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

struct node
{
	int ch[2], fa;
	LL tag, val;
	node() { ch[0] = ch[1] = fa = tag = val = 0; }
	void Tag(LL v) { tag = val = v; }
};
node a[maxn];
#define ls a[o].ch[0]
#define rs a[o].ch[1]

inline int gettp(int o) { int f = a[o].fa; return a[f].ch[0] == o ? 0 : (a[f].ch[1] == o ? 1 : -1); }
void pushdown(int o)
{
	if(a[o].tag)
	{
		a[ls].Tag(a[o].tag);
		a[rs].Tag(a[o].tag);
		a[o].tag = 0;
	}
}
void pushup(int o) { if(gettp(o) != -1) pushup(a[o].fa); pushdown(o); }
void rotate(int o,int d)
{
	int k1 = a[o].ch[d], k2 = a[k1].ch[d ^ 1];
	if (gettp(o) != -1) a[a[o].fa].ch[gettp(o)] = k1;
	a[o].ch[d] = k2;
	a[k1].ch[d ^ 1] = o;
	a[k1].fa = a[o].fa;
	a[o].fa = k1;
	a[k2].fa = o;
}
void splay(int o)
{
	pushup(o);
	while (gettp(o) != -1)
	{
		int f1 = a[o].fa, f2 = a[f1].fa, t1 = gettp(o), t2 = gettp(f1);
		if (t2 == -1 || f2 == 0) rotate(f1, t1);
		else if (t1 == t2)
		{
			rotate(f2, t2);
			rotate(f1, t1);
		}
		else
		{
			rotate(f1, t1);
			rotate(f2, t2);
		}
	}
}

std::vector<int> g[maxn], l[maxn];
LL dep[maxn];
int n, m, fa[maxn];

void access(int o, std::vector<std::pair<LL, LL>> &need, LL nT)
{
	splay(o);
	int O = o, lastc = rs; LL OV = a[o].val;
	int k = 0;
	while(o)
	{
		splay(o);
		if(k) need.emplace_back((a[o].val == 0 ? 1 : a[o].val + dep[o] + 1), nT + dep[o]);
		rs = k;
		k = o;
		o = a[o].fa;
	}
	a[k].Tag(nT);
	splay(O);
	a[O].val = OV;
	a[O].ch[1] = lastc;
}

void dfs(int x)
{
	for(int i=0; i<(int)g[x].size(); i++)
	{
		fa[g[x][i]] = x;
		a[g[x][i]].fa = x;
		a[x].ch[1] = g[x][i];
		dep[g[x][i]] = dep[x] + l[x][i];
		dfs(g[x][i]);
	}
}

int main()
{
	get2(n, m);
	for(int i=1, u, v, w; i<n; i++)
	{
		get3(u, v, w);
		g[u].pb(v); l[u].pb(w);
	}
	dfs(1);
	
	std::vector<std::pair<LL, LL> > need;
	for(int i=1, x, curT; i<=m; i++)
	{
		get2(x, curT);
		access(x, need, curT);
	}
	
	std::sort(need.begin(), need.end());
	std::priority_queue<LL, std::vector<LL>, std::greater<LL>> ddl;
	// for(auto v : need) printf("need %lld %lld\n", v.ff, v.ss);
	
	int pos = 0;
	LL curT = 0;
	while(pos < need.size() || !ddl.empty())
	{
		while(pos < need.size() && need[pos].ff <= curT)
		{
			ddl.push(need[pos].ss);
			pos++;
		}
		if(!ddl.empty())
		{
			LL now = ddl.top(); ddl.pop();
			// printf("curT= %lld now= %lld\n", curT, now);
			if(now >= curT)
			{
				curT++;
				continue;
			}
			else
			{
				int ans = 0;
				for(auto v : need) if(v.ss < now) ans++;
				printf("%lld %d\n", now, ans);
				return 0;
			}
		}
		else curT = need[pos].ff;
	}
	printf("-1 %d\n", need.size());
	return 0;
}