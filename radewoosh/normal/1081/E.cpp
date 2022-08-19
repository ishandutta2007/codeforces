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
const int nax=200*1007;

int n;
ll tab[nax];

vector <pll> dz[nax];

bool mniej(pll a, pll b)
{
	return a.second<b.second;
}

int main()
{
	scanf("%d", &n);
	for (int i=2; i<=n; i+=2)
		scanf("%lld", &tab[i]);
	for (int i=1; i<nax; i++)
	{
		for (int j=i; j<nax; j+=i)
		{
			int l=j/i;
			if ((l&1)!=(i&1) || i>=l)
				continue;
			ll a=(i+l)/2;
			ll b=(l-i)/2;
			dz[j].push_back({b*b, a*a});
		}
		sort(dz[i].begin(), dz[i].end(), mniej);
	}
	ll s=0;
	for (int i=1; i<=n; i+=2)
	{
		int czy=0;
		for (pll j : dz[tab[i+1]])
		{
			if (s<j.first)
			{
				tab[i]=j.first-s;
				s=j.second;
				czy=1;
				break;
			}
		}
		if (!czy)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i=1; i<=n; i++)
		printf("%lld \n", tab[i]);
	printf("\n");
	return 0;
}