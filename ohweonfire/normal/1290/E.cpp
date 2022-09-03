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

const int maxn = 150111;

struct BIT
{
	int bit[maxn];
	void add(int x, int v) { for(; x<maxn; x += x & -x) bit[x] += v; }
	int query(int x) { int ret = 0; for(; x; x -= x & -x) ret += bit[x]; return ret; }
	void clear() { memset(bit, 0, sizeof(bit)); }
};
BIT pre;
LL sum, ans[maxn];
namespace SGT
{

#define ls (t*2)
#define rs (t*2+1)
struct node
{
	int mx, smx, mxcnt, tag;
	node() { mx = smx = mxcnt = tag = 0; }
	void Tag(int v)
	{
		mx += v;
		tag += v;
	}
};
node seg[(1 << 19) + 100];
void push(int t)
{
	if(seg[t].tag)
	{
		if(seg[ls].mx + seg[t].tag == seg[t].mx) seg[ls].Tag(seg[t].tag);
		if(seg[rs].mx + seg[t].tag == seg[t].mx) seg[rs].Tag(seg[t].tag);
		seg[t].tag = 0;
	}
}
void pull(int t)
{
	if(seg[ls].mx > seg[rs].mx)
	{
		seg[t].mx = seg[ls].mx;
		seg[t].mxcnt = seg[ls].mxcnt;
		seg[t].smx = std::max(seg[ls].smx, seg[rs].mx);
	}
	else if(seg[rs].mx > seg[ls].mx)
	{
		seg[t].mx = seg[rs].mx;
		seg[t].mxcnt = seg[rs].mxcnt;
		seg[t].smx = std::max(seg[rs].smx, seg[ls].mx);
	}
	else
	{
		seg[t].mx = seg[ls].mx;
		seg[t].mxcnt = seg[ls].mxcnt + seg[rs].mxcnt;
		seg[t].smx = std::max(seg[ls].smx, seg[rs].smx);
	}
}
void modify(int l, int r, int v, int tl, int tr, int t)
{
	if(seg[t].mx <= v) return;
	if(seg[t].smx < v && l <= tl && tr <= r)
	{
		sum -= 1ll * pre.query(seg[t].mx) * seg[t].mxcnt;
		seg[t].Tag(v - seg[t].mx);
		sum += 1ll * pre.query(seg[t].mx) * seg[t].mxcnt;
		return;
	}
	push(t);
	int mid = (tl + tr) / 2;
	if(l <= mid) modify(l, r, v, tl, mid, ls);
	if(r > mid) modify(l, r, v, mid+1, tr, rs);
	pull(t);
}
void activate(int p, int v, int tl, int tr, int t)
{
	if(tl == tr)
	{
		seg[t].mx = v;
		seg[t].mxcnt = 1;
		seg[t].smx = 0;
		sum += pre.query(v);
		return;
	}
	push(t);
	int mid = (tl + tr) / 2;
	if(p <= mid) activate(p, v, tl, mid, ls);
	else activate(p, v, mid+1, tr, rs);
	pull(t);
}
void debug(int tl, int tr, int t)
{
	if(tl == tr)
	{
		printf("l= %d r= %d mx= %d mxcnt= %d smx= %d\n", tl, tr, seg[t].mx, seg[t].mxcnt, seg[t].smx);
		return;
	}
	push(t);
	int mid = (tl + tr) / 2;
	debug(tl, mid, ls);
	debug(mid+1, tr, rs);
}

} // namespace SGT

int n, a[maxn], pos[maxn];
void ins(int p)
{
	if(p > 1) SGT::modify(1, p-1, p-1, 1, n, 1);
	pre.add(p, 1);
	sum -= pre.query(p);
	SGT::activate(p, n, 1, n, 1);
}

void solve()
{
	pre.clear();
	memset(SGT::seg, 0, sizeof(SGT::seg));
	for(int i=0; i<(1<<19)+10; i++) SGT::seg[i] = SGT::node();
	for(int i=1; i<=n; i++) pos[a[i]] = i;
	sum = 0;
	for(int i=1; i<=n; i++)
	{
		ins(pos[i]);
		ans[i] += sum;
	}
}

int main()
{
	get1(n);
	for(int i=1; i<=n; i++) get1(a[i]);
	
	solve();
	std::reverse(a+1, a+n+1);
	solve();
	for(int i=1; i<=n; i++)
	{
		ans[i] += i;
		printendl(ans[i]);
	}
	return 0;
}