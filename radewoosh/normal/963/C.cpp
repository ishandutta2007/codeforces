//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
const int nax=1000*1007;

int n;

ll w[nax];
ll h[nax];
ll ile[nax];

ll nwdw, nwdh;

ll wyn;

void ans(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

int check(ll a, ll b, ll x, ll y)
{
	vector <ll> jed{a, b};
	vector <ll> dwa{x, y};
	
	for (ll &i : jed)
	{
		for (ll &j : dwa)
		{
			ll g=__gcd(i, j);
			i/=g;
			j/=g;
		}
	}
	
	return (jed==vector<ll>{1, 1} && dwa==vector<ll>{1, 1});
}

void cons(ll v)
{
	debug() << v << "  " << ile[1]/v;
	if (!(nwdw%v) && !(nwdh%(ile[1]/v)))
		wyn++;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld%lld", &w[i], &h[i], &ile[i]);
	for (int i=1; i<=n; i++)
	{
		if (w[i]==w[1])
			nwdw=__gcd(nwdw, ile[i]);
		if (h[i]==h[1])
			nwdh=__gcd(nwdh, ile[i]);
	}
	map <ll,ll> mapw, maph;
	for (int i=1; i<=n; i++)
	{
		if (w[i]==w[1])
			maph[h[i]]=ile[i];
		if (h[i]==h[1])
			mapw[w[i]]=ile[i];
	}
	if (n!=(ll)mapw.size()*(ll)maph.size())
		ans(0);
	for (int i=1; i<=n; i++)
		if (!check(ile[i], ile[1], maph[h[i]], mapw[w[i]]))
			ans(0);
	
	for (ll i=1; i*i<=ile[1]; i++)
	{
		if (!(ile[1]%i))
		{
			cons(i);
			if (i*i!=ile[1])
				cons(ile[1]/i);
		}
	}
	
	debug() << "ok";
	ans(wyn);
	return 0;
}