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

int n;

pii tab[nax];

int main()
{
	scanf("%d", &n);
	n=4*n+1;
	for (int i=1; i<=n; i++)
		scanf("%d%d", &tab[i].first, &tab[i].second);
	for (int i=1; i<=n; i++)
	{
		int xa=nax;
		int xb=-nax;
		int ya=nax;
		int yb=-nax;
		for (int j=1; j<=n; j++)
		{
			if (j==i)
				continue;
			xa=min(xa, tab[j].first);
			xb=max(xb, tab[j].first);
			ya=min(ya, tab[j].second);
			yb=max(yb, tab[j].second);
		}
		if (xb-xa!=yb-ya)
			continue;
		int czy=1;
		for (int j=1; j<=n; j++)
		{
			if (j==i)
				continue;
			if (tab[j].first!=xa && tab[j].first!=xb && tab[j].second!=ya && tab[j].second!=yb)
				czy=0;
		}
		if (czy)
		{
			printf("%d %d\n", tab[i].first, tab[i].second);
			break;
		}
	}
	return 0;
}