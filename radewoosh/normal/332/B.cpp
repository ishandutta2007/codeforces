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
const int nax=1000*1007;

int n, k;

ll tab[nax];

ll lew[nax];
ll pam[nax];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]+=tab[i-1];
	}
	for (int i=1; i<=n; i++)
	{
		if (i<k)
			lew[i]=-1e18;
		else
			lew[i]=tab[i]-tab[i-k];
	}
	ll naj=-1e18;
	pam[0]=-1e18;
	for (int i=1; i<=n; i++)
		pam[i]=max(pam[i-1], lew[i]);
	for (int i=k+1; i<=n; i++)
		naj=max(naj, lew[i]+pam[i-k]);
	for (int i=k+1; i<=n; i++)
	{
		if (lew[i]+pam[i-k]==naj)
		{
			for (int j=1; 1; j++)
			{
				if (lew[j]+lew[i]==naj)
				{
					printf("%d %d\n", j-k+1, i-k+1);
					debug() << naj;
					return 0;
				}
			}
		}
	}
	return 0;
}