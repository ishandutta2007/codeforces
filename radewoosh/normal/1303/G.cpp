//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

const ll is_query = -(1LL << 62);
struct Line {
	ll m, b;
	mutable function<const Line *()> succ;
	bool operator<(const Line &rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line *s = succ();
		if (!s) return 0;
		ll x = rhs.m;
		return b - s->b < (s->m - m) * x;//ld?
	}
};
struct HullDynamic : public multiset<Line> {
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);//ld?
	}
	void insert_line(ll m, ll b) {
		auto y = insert({m, b});
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) {
			erase(y);
			return;
		}
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	ll eval(ll x) {
		auto l = *lower_bound((Line) {x, is_query});
		return l.m * x + l.b;
	}
};


int n;
vi graf[nax];

ll tab[nax];

ll wyn;

int bylcen[nax];
int roz[nax];
int maxr[nax];
vi spo;

void dfs1(int v, int oj)
{
	roz[v]=1;
	maxr[v]=0;
	spo.push_back(v);
	for (int i : graf[v])
	{
		if (bylcen[i] || i==oj)
			continue;
		dfs1(i, v);
		roz[v]+=roz[i];
		maxr[v]=max(maxr[v], roz[i]);
	}
}

HullDynamic janusz;

void dfs15(int v, int oj, ll sum, ll susum, ll gle)
{
	gle++;
	susum+=gle*tab[v];
	sum+=tab[v];
	wyn=max(wyn, susum+janusz.eval(sum));
	for (int i : graf[v])
		if (!bylcen[i] && i!=oj)
			dfs15(i, v, sum, susum, gle);
}

void dfs2(int v, int oj, ll sum, ll susum, ll dlu)
{
	sum+=tab[v];
	susum+=sum;
	dlu++;
	janusz.insert_line(dlu, susum);
	for (int i : graf[v])
		if (!bylcen[i] && i!=oj)
			dfs2(i, v, sum, susum, dlu);
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs1(v, 0);
	int c=-1;
	int ss=spo.size();
	for (int i : spo)
		if (maxr[i]*2<=ss && (ss-roz[i])*2<=ss)
			c=i;
	debug() << imie(c);
	assert(c!=-1);
	
	wyn=max(wyn, tab[c]);
	
	for (int h=0; h<2; h++)
	{
		reverse(graf[c].begin(), graf[c].end());
		janusz.clear();
		janusz.insert_line(1, tab[c]);
		for (int i : graf[c])
		{
			if (bylcen[i])
				continue;
			
			dfs15(i, c, 0, 0, 0);
			dfs2(i, c, tab[c], tab[c], 1);
		}
		
	}
	
	
	bylcen[c]=1;
	for (int i : graf[c])
		szuk(i);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	szuk(1);
	printf("%lld\n", wyn);
	return 0;
}