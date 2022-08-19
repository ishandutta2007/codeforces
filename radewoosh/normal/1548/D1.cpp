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

int n;
pll tab[nax];

ll wyn;

ll tu[2][2];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	}
	for (int i=1; i<=n; i++)
	{
		ll a=tab[i].first/2;
		ll b=tab[i].second/2;
		a%=2;
		b%=2;
		//~ debug() << a << " " << b;
		vector<pii> kom;
		for (int x=0; x<2; x++)
		{
			for (int y=0; y<2; y++)
			{
				kom.push_back({x, y});
			}
		}
		for (pii x : kom)
		{
			for (pii y : kom)
			{
				if (x==y)
					break;
				ll moz=tu[x.first][x.second]*tu[y.first][y.second];
				pii z={a, b};
				int ile=0;
				ile+=(x!=z)+(z!=y)+(x!=y);
				if (!(ile&1))
					wyn+=moz;
			}
			pii y=x;
			ll moz=tu[x.first][x.second]*(tu[y.first][y.second]-1)/2;
			pii z={a, b};
			int ile=0;
			ile+=(x!=z)+(z!=y)+(x!=y);
			//~ debug() << x << " " << moz << " " << ile;
			if (!(ile&1))
				wyn+=moz;
		}
		tu[a][b]++;
	}
	printf("%lld\n", wyn);
	return 0;
}