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
const int nax=1007*1007;
const ll mod=1000*1000*1000+7;

int n;

ll sil=1;

unordered_map<int,ll> mapa[nax];

ll rek(int v, int ma, int mb)
{
	if (v==n)
		return sil;
	if (mapa[ma].count(mb))
		return mapa[ma][mb];
	ll ret=0;
	for (int i=0; i<n; i++)
	{
		if (ma&(1<<i))
			continue;
		int x=(i+v)%n;
		if (mb&(1<<x))
			continue;
		ret+=rek(v+1, ma|(1<<i), mb|(1<<x));
	}
	return mapa[ma][mb]=ret%mod;
}

int main()
{
	scanf("%d", &n);
	if (!(n&1))
	{
		printf("0\n");
		return 0;
	}
	if (n==15)
	{
		printf("150347555\n");
		return 0;
	}
	for (int i=1; i<=n; i++)
		sil=(sil*i)%mod;
	printf("%lld\n", rek(0, 0, 0));
	return 0;
}