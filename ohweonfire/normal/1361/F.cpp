#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


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

int n, q, p[maxn], w[maxn], ls[maxn << 1], rs[maxn << 1], fa[maxn << 1], pos[maxn], tot;
LL ans, val[maxn << 1];
ordered_set st[maxn << 1];

int build(int l, int r)
{
	if(l == r)
	{
		pos[l] = ++tot;
		st[tot].insert(p[l]);
		return tot;
	}
	int mid = std::min_element(w + l, w + r) - w;
	
	int now = ++tot;
	ls[now] = build(l, mid);
	rs[now] = build(mid+1, r);
	fa[ls[now]] = fa[rs[now]] = now;
	
	for(int i=l; i<=r; i++) st[now].insert(p[i]);
	for(auto v : st[rs[now]]) val[now] += st[ls[now]].order_of_key(v);
	ans += std::min(val[now], 1ll * (int)st[ls[now]].size() * (int)st[rs[now]].size() - val[now]);
	return now;
}

void remove(int id, int now)
{
	int cur = pos[id];
	
	while(fa[cur])
	{
		int f = fa[cur];
		ans -= std::min(val[f], 1ll * (int)st[ls[f]].size() * (int)st[rs[f]].size() - val[f]);
		cur = f;
	}
	
	cur = pos[id];
	while(cur)
	{
		int f = fa[cur];
		st[cur].erase(now);
		if(ls[f] == cur) val[f] -= (int)st[rs[f]].size() - st[rs[f]].order_of_key(now);
		else if(rs[f] == cur) val[f] -= st[ls[f]].order_of_key(now);
		if(f) ans += std::min(val[f], 1ll * (int)st[ls[f]].size() * (int)st[rs[f]].size() - val[f]);
		cur = f;
	}
}

void insert(int id, int now)
{
	int cur = pos[id];
	
	while(fa[cur])
	{
		int f = fa[cur];
		ans -= std::min(val[f], 1ll * (int)st[ls[f]].size() * (int)st[rs[f]].size() - val[f]);
		cur = f;
	}
	
	cur = pos[id];
	while(cur)
	{
		int f = fa[cur];
		st[cur].insert(now);
		if(ls[f] == cur) val[f] += (int)st[rs[f]].size() - st[rs[f]].order_of_key(now);
		else if(rs[f] == cur) val[f] += st[ls[f]].order_of_key(now);
		if(f) ans += std::min(val[f], 1ll * (int)st[ls[f]].size() * (int)st[rs[f]].size() - val[f]);
		cur = f;
	}
}

int main()
{
	get1(n);
	for(int i=1; i<=n; i++) get1(p[i]);
	for(int i=1; i<n; i++) get1(w[i]);
	
	build(1, n);
	
	get1(q);
	while(q--)
	{
		int x, y;
		get2(x, y);
		
		if(x != y)
		{
			remove(x, p[x]);
			remove(y, p[y]);
			insert(x, p[y]);
			insert(y, p[x]);
			std::swap(p[x], p[y]);
		}
		printendl(ans);
	}
	
	return 0;
}