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

int n, m;

vll raz, dwa;

void out(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		raz.push_back(x);
	}
	for (int i=1; i<=m; i++)
	{
		ll x;
		scanf("%lld", &x);
		dwa.push_back(x);
	}
	sort(raz.begin(), raz.end());
	sort(dwa.begin(), dwa.end());
	if (raz.back()>dwa[0])
		out(-1);
	if (raz.back()==dwa[0])
	{
		ll wyn=0;
		for (int i=0; i<n-1; i++)
			wyn+=m*raz[i];
		for (int i=0; i<m; i++)
			wyn+=dwa[i];
		out(wyn);
	}
	else
	{
		if (n==1 || m==1)
			out(-1);
		ll wyn=0;
		for (int i=0; i<n-2; i++)
			wyn+=m*raz[i];
		for (int i=0; i<m; i++)
			wyn+=dwa[i];
		wyn+=raz[n-1]+raz[n-2]*(m-1);
		out(wyn);
	}
	return 0;
}