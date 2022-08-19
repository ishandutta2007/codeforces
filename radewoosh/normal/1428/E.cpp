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
const ll inf=1e18;

int n, k;

ll tab[nax];

ll kwa(ll v)
{
	return v*v;
}

ll koszt(int v, ll cz)
{
	if (cz>tab[v])
		return inf;
	ll dz=tab[v]/cz;
	ll resz=tab[v]%cz;
	return kwa(dz+1)*resz+kwa(dz)*(cz-resz);
}

ll tu[nax];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		tu[i]=1;
		scanf("%lld", &tab[i]);
	}
	priority_queue<pair<ll,int>>kol;
	for (int i=1; i<=n; i++)
		kol.push({koszt(i, 1)-koszt(i, 2), i});
	for (int h=n+1; h<=k; h++)
	{
		int v=kol.top().second;
		kol.pop();
		tu[v]++;
		kol.push({koszt(v, tu[v])-koszt(v, tu[v]+1), v});
	}
	ll wyn=0;
	for (int i=1; i<=n; i++)
		wyn+=koszt(i, tu[i]);
	printf("%lld\n", wyn);
	return 0;
}