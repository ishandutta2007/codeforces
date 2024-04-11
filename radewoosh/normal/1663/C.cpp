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

long double getWinProbability(long double ra, long double rb) {
    return 1.0 / (1.0 + pow((long double) 10.0, (rb - ra) / 400.0));
}

long double aggregateRatings(vector<long double> teamRatings)
{
    long double left = 0;
    long double right = 1E5;

    for (int tt = 0; tt < 100; tt++) {
        long double r = (left + right) / 2.0;

        long double rWinsProbability = 1.0;
        for(int i=0; i<(int)teamRatings.size(); i++)
            rWinsProbability *= getWinProbability(r, teamRatings[i]);

        long double rating = log10(1 / (rWinsProbability) - 1) * 400 + r;

        if (rating > r)
            left = r;
        else
            right = r;
    }

    return (left + right) / 2.0;
}

int n;
int tab[nax];

int main()
{
	vector<long double> wek;
	scanf("%d", &n);
	ll s=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		//~ tab[i]=3979;
		//~ tab[i]=0;
		//~ wek.push_back(tab[i]);
		s+=tab[i];
	}
	printf("%lld\n", s);
	//~ sort(wek.begin(), wek.end());
	//~ wek.push_back(0);
	//~ printf("%lld\n", llround(wek.back()));
	//~ printf("%lld\n", llround(aggregateRatings(wek)));
	return 0;
}