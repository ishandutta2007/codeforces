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
const int nax=250*1007;
const int inf=2e9;

int n;

pii lew[nax];
pii pra[nax];

int dos[nax];

pii mini(pii a, pii b)
{
	return {min(a.first, b.first), min(a.second, b.second)};
}

pii maxi(pii a, pii b)
{
	return {max(a.first, b.first), max(a.second, b.second)};
}

int zaw(int a, int b, int c)
{
	return (a<=b && b<=c);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &lew[i].first, &lew[i].second);
		scanf("%d%d", &pra[i].first, &pra[i].second);
		dos[i]=i;
	}
	while(1)
	{
		shandom_ruffle(dos+1, dos+1+n);
		pii gor={inf, inf};
		for (int i=1; i*2<=n+1; i++)
		{
			int w=dos[i];
			gor=mini(gor, pra[w]);
		}
		int ile=0;
		for (int i=1; i<=n; i++)
		{
			if (zaw(lew[i].first, gor.first, pra[i].first) && zaw(lew[i].second, gor.second, pra[i].second))
				ile++;
		}
		if (ile<n-1)
			continue;
		printf("%d %d\n", gor.first, gor.second);
		break;
		
	}
	return 0;
}