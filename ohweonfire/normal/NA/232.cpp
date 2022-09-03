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
#define get2(x, y) get1(x) && get1(y)
#define get3(x, y, z) get2(x, y) && get1(z)
#define get4(x, y, z, w) get3(x, y, z) && get1(w)
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

template<typename T,const int MAXN>
struct bit_t
{
	int timer, mark[MAXN];
	T bit[MAXN];
	bit_t(){timer = 0; memset(mark,0,sizeof(mark));}
	void add(int x,T v)
	{
		for(;x<MAXN;x+=x&-x)
		{
			if(mark[x]!=timer)
			{
				mark[x]=timer;
				bit[x]=0;
			}
			bit[x]+=v;
		}
	}
	T query(int x)
	{
		T ret=0;
		for(;x;x-=x&-x)if(mark[x]==timer)ret+=bit[x];
		return ret;
	}
};

int cov[maxn], tot;
pii seg[maxn];
int n, pre_id[maxn];
LL a[maxn], pre[maxn], k;

namespace M1
{

bit_t<int, maxn> bit1;
bit_t<LL, maxn> bit2;
std::vector<LL> vs;
std::map<LL,LL> mem;

void prework()
{
	vs.pb(-Linf);
	for(int i=0; i<=n; i++) vs.pb(pre[i]);
	sort(vs.begin(), vs.end()); vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
	for(int i=0; i<=n; i++) pre_id[i] = lower_bound(vs.begin(), vs.end(), pre[i]) - vs.begin();
}

LL check(LL x)
{
	if(mem.find(x)!=mem.end()) return mem[x];
	bit1.timer++;
	LL ans = 0;
	for(int i=1; i<=n; i++)
	{
		bit1.add(pre_id[i-1], 1);
		int idv = upper_bound(vs.begin(), vs.end(), pre[i] - x) - vs.begin();
		ans += bit1.query(idv - 1);
	}
	return mem[x] = ans;
}

int mnbit[maxn];
void modify(int x, int v)
{
	for(; x<maxn; x += x & -x) mnbit[x] = std::min(mnbit[x], v);
}
int query(int x)
{
	int ret = inf;
	for(; x; x -= x & -x) ret = std::min(ret, mnbit[x]);
	return ret;
}

LL cover_all(LL x)
{
	bit1.timer++; bit2.timer++;
	LL ans = 0;
	memset(mnbit, inf, sizeof(mnbit));
	for(int i=1; i<=n; i++)
	{
		bit1.add(pre_id[i-1], 1);
		bit2.add(pre_id[i-1], pre[i-1]);
		modify(pre_id[i-1], i-1);
		int idv = upper_bound(vs.begin(), vs.end(), pre[i] - x) - vs.begin();
		ans += bit1.query(idv - 1) * pre[i] - bit2.query(idv - 1);
		int lv = query(idv - 1);
		if(lv != inf)
		{
			cov[lv+1]++;
			cov[i+1]--;
		}
	}
	return ans;
}
std::vector<int> have[maxn];
LL cover(LL sum, int tmp)
{
	for(int i=0; i<maxn; i++) have[i].clear();
	LL ans = 0;
	for(int i=1; i<=n; i++)
	{
		have[pre_id[i-1]].pb(i-1);
		int idv = lower_bound(vs.begin(), vs.end(), pre[i] - sum) - vs.begin();
		if(idv < vs.size() && vs[idv] == pre[i] - sum)
		{
			for(int j=0; j<have[idv].size() && tmp; j++)
			{
				cov[have[idv][j]+1]++;
				cov[i+1]--;
				tmp--;
				ans += sum;
			}
		}
	}
	return ans;
}
void mark(LL sum, LL tl, LL tr)
{
	for(int i=0; i<maxn; i++) have[i].clear();
	tl--;
	tr -= tl;
	for(int i=1; i<=n; i++)
	{
		have[pre_id[i-1]].pb(i-1);
		int idv = lower_bound(vs.begin(), vs.end(), pre[i] - sum) - vs.begin();
		if(idv < vs.size() && vs[idv] == pre[i] - sum)
		{
			for(int j=tl; j<have[idv].size() && tr; j++)
			{
				seg[++tot] = mp(have[idv][j]+1, i);
				tr--;
			}
			tl = std::max(tl - (int)have[idv].size(), 0ll);
		}
	}
}
void mark_all(LL vl, LL vr)
{
	std::set<std::pair<LL,int> > st;
	for(int i=1; i<=n; i++)
	{
		st.insert(mp(pre[i-1], i));
		for(auto v = st.lower_bound(mp(pre[i]-vr,0)); v!=st.end() && (pre[i]-(v->ff)) >= vl; v++)
			seg[++tot] = mp(v->ss, i);
	}
}

}; // namespace M1

LL getrank(LL k)
{
	if(k < 1) k = 1;
	LL lb = -1e12, rb = 1e12, mid;
	while(lb < rb - 1)
	{
		mid = lb + (rb - lb) / 2;
		if(M1::check(mid) < k) rb = mid;
		else lb = mid;
	}
	return lb;
}

LL ans;
void gen(LL tl, LL tr)
{
	LL vl = getrank(tl), vr = getrank(tr);
	LL need1 = tl - M1::check(vl+1) - 1, need2 = tr - M1::check(vr+1);
	ans = M1::cover_all(vl+1) + M1::cover(vl, need1);
	if(vl == vr) M1::mark(vl, need1+1, need2);
	else
	{
		M1::mark(vl, need1+1, Linf);
		M1::mark_all(vr+1, vl-1);
		M1::mark(vr, 1, need2);
	}
	for(int i=1; i<=n; i++) cov[i] += cov[i-1];
//	printf("ans= %lld\n", ans);
//	for(int i=1; i<=tot; i++) printf("%d %d\n", seg[i].ff, seg[i].ss);
}

struct sparse_table
{
	int lg[maxn],n;
	LL min[20][maxn], max[20][maxn];
	void construct(int n,LL *a)
	{
		this->n=n;
		for(int i=2;i<=n+1;i++)lg[i]=lg[i>>1]+1;
		for(int i=0;i<=n;i++)min[0][i] = max[0][i] = a[i];
		for(int i=1;i<20;i++)for(int j=0;j<=n;j++)
		{
			int nxt=j+(1<<i-1);
			if(nxt<=n)
			{
				min[i][j] = std::min(min[i-1][j], min[i-1][nxt]);
				max[i][j] = std::max(max[i-1][j], max[i-1][nxt]);
			}
		}
	}
	LL qmin(int l,int r)
	{
		int len=lg[r-l+1];
		return std::min(min[len][l],min[len][r-(1<<len)+1]);
	}
	LL qmax(int l,int r)
	{
		int len=lg[r-l+1];
		return std::max(max[len][l],max[len][r-(1<<len)+1]);
	}
};
sparse_table tab;

typedef std::pair<LL,pii> val_t;
std::set<val_t> st1, st2, st3, st4;
LL sum = 0;
void add_val(val_t x)
{
	if(x.ss.ff == 0)
	{
		st3.insert(x);
		return;
	}
	else if(x.ss.ss == n+1)
	{
		st4.insert(x);
		return;
	}
	if(st1.size() && *st1.begin() < x)
	{
		sum += x.ff;
		st1.insert(x);
	}
	else st2.insert(x);
}
void del_val(val_t x)
{
	if(x.ss.ff == 0)
	{
		st3.erase(x);
		return;
	}
	else if(x.ss.ss == n+1)
	{
		st4.erase(x);
		return;
	}
	if(st1.find(x) != st1.end())
	{
		sum -= x.ff;
		st1.erase(x);
	}
	else st2.erase(x);
}
void adjust(int sz)
{
	while(st1.size() < sz)
	{
		sum += st2.rbegin() -> ff;
		st1.insert(*st2.rbegin());
		st2.erase(*st2.rbegin());
	}
	while(st1.size() > sz)
	{
		sum -= st1.begin() -> ff;
		st2.insert(*st1.begin());
		st1.erase(*st1.begin());
	}
}
val_t getval(int l, int r)
{
	LL v;
	if(l==0) v = -tab.qmin(0, r-1);
	else if(r==n+1) v = tab.qmax(l,n);
	else v = tab.qmax(l, r-1) - tab.qmin(l, r-1);
	return mp(v, mp(l, r));
}
std::set<int> st;
void ins(int x)
{
	st.insert(x);
	auto it = st.find(x);
	int pre, nxt;
	it--; pre = *it;
	it++; it++; nxt = *it;
	del_val(getval(pre,nxt));
	add_val(getval(pre,x));
	add_val(getval(x,nxt));
}
void del(int x)
{
	auto it = st.find(x);
	int pre, nxt;
	it--; pre = *it;
	it++; it++; nxt = *it;
	add_val(getval(pre,nxt));
	del_val(getval(pre,x));
	del_val(getval(x,nxt));
	st.erase(x);
}

void work()
{
	std::sort(seg+1, seg+tot+1,[](const pii&a, const pii&b){return pre[a.ss] - pre[a.ff-1] > pre[b.ss] - pre[b.ff-1];});
	tab.construct(n, pre);
	
	st.insert(0);
	st.insert(n+1);
	add_val(getval(0, n+1));
	for(int i=1; i<=n; i++) if(!cov[i]) ins(i);
	
	LL opt = -Linf, cur = 0;
	for(int i=1; i<=tot; i++)
	{
		if(st.size() - 2 >= tot - i + 1)
		{
			adjust(tot - i);
			LL now = cur + sum + st3.rbegin()->ff + st4.rbegin()->ff;
			opt = std::max(opt, now);
		}
		int lv = seg[i].ff, rv = seg[i].ss;
		while(true)
		{
			auto it = st.lower_bound(lv);
			if(*it > rv) break;
			del(*it);
		}
		cur += pre[rv] - pre[lv-1];
	}
	if(st.size() == 2) opt = std::max(opt, cur);
	printf("%lld\n", opt + ans);
}

int main()
{
	get2(n, k);
	for(int i=1; i<=n; i++) get1(a[i]);
	for(int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
	
	M1::prework();
	gen(std::max(1ll, k-n+1), k);
	work();
	return 0;
}