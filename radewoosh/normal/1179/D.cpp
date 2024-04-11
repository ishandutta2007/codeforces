//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const ll inf=1e18;
using ld=long double;

//~ const ll is_query = -(1LL << 62);
//~ struct Line {
	//~ ll m, b;
	//~ mutable function<const Line *()> succ;
	//~ bool operator<(const Line &rhs) const {
		//~ if (rhs.b != is_query) return m < rhs.m;
		//~ const Line *s = succ();
		//~ if (!s) return 0;
		//~ ll x = rhs.m;
		//~ return b - s->b < (s->m - m) * (ld)x;//ld?
	//~ }
//~ };
//~ struct HullDynamic : public multiset<Line> {
	//~ bool bad(iterator y) {
		//~ auto z = next(y);
		//~ if (y == begin()) {
			//~ if (z == end()) return 0;
			//~ return y->m == z->m && y->b <= z->b;
		//~ }
		//~ auto x = prev(y);
		//~ if (z == end()) return y->m == x->m && y->b <= x->b;
		//~ return (x->b - y->b) * (ld)(z->m - y->m) >= (y->b - z->b) * (ld)(y->m - x->m);//ld?
	//~ }
	//~ void insert_line(ll m, ll b) {
		//~ auto y = insert({m, b});
		//~ y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		//~ if (bad(y)) {
			//~ erase(y);
			//~ return;
		//~ }
		//~ while (next(y) != end() && bad(next(y))) erase(next(y));
		//~ while (y != begin() && bad(prev(y))) erase(prev(y));
	//~ }
	//~ ll eval(ll x) {
		//~ auto l = *lower_bound((Line) {x, is_query});
		//~ return l.m * x + l.b;
	//~ }
//~ };

int n;

vi graf[nax];
ll wyn;

int roz[nax];

ll dp[nax];

ll po2[nax];

void dfs1(int v, int oj)
{
	roz[v]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
		roz[v]+=roz[i];
	}
}

int czas;

int kied[nax];
ll mini1[nax];
ll mini2[nax];

vi wek;

void cons(int v, ll w)
{
	if (kied[v]!=czas)
	{
		wek.push_back(v);
		kied[v]=czas;
		mini1[v]=inf;
		mini2[v]=inf;
	}
	if (w<mini1[v])
	{
		mini2[v]=mini1[v];
		mini1[v]=w;
	}
	else
	{
		if (w<mini2[v])
		{
			mini2[v]=w;
		}
	}
}

void dfs2(int v, int oj)
{
	dp[v]=po2[roz[v]];
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs2(i, v);
		dp[v]=min(dp[v], dp[i]+po2[roz[v]-roz[i]]);
	}
	wyn=min(wyn, dp[v]+po2[n-roz[v]]);
	czas++;
	wek.clear();
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		cons(roz[i], dp[i]);
	}
	for (const int &i : wek)
	{
		if (mini2[i]!=inf)
			wyn=min(wyn, mini1[i]+mini2[i]+po2[n-i-i]);
		for (const int &j : wek)
		{
			if (i==j)
				break;
			wyn=min(wyn, mini1[i]+mini1[j]+po2[n-i-j]);
		}
	}
}

int main()
{
	for (int i=0; i<nax; i++)
		po2[i]=(i*(i-1LL))/2;
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	if (n==2)
	{
		printf("2\n");
		return 0;
	}
	wyn=inf;
	int korz=0;
	for (int i=1; i<=n; i++)
		if ((int)graf[i].size()>1)
			korz=i;
	assert(korz);
	dfs1(korz, 0);
	dfs2(korz, 0);
	
	
	wyn=n*(n-1LL)-wyn;
	printf("%lld\n", wyn);
	return 0;
}