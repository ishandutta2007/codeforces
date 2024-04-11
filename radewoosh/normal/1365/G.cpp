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

void ff()
{
	fflush(stdout);
}

ll pyt(vi wek)
{
	if (wek.empty())
		return 0;
	printf("? %d", (int)wek.size());
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	ll x;
	scanf("%lld", &x);
	return x;
}

void ans(vll wek)
{
	printf("!");
	for (ll i : wek)
		printf(" %lld", i);
	printf("\n");
	ff();
	exit(0);
}

int jego[nax];

const int d=13;
ll ory[d];

const int k=63;
ll pot[k];

int gdz[k];

vi pie;

int main()
{
	int kt=0;
	for (int i=0; i<(1<<d); i++)
	{
		if (__builtin_popcount(i)==d/2)
		{
			kt++;
			jego[kt]=i;
		}
	}
	scanf("%d", &n);
	for (int i=0; i<d; i++)
	{
		vi wek;
		for (int j=1; j<=n; j++)
			if (jego[j]&(1<<i))
				wek.push_back(j);
		ory[i]=pyt(wek);
	}
	pot[0]=1;
	for (int i=1; i<k; i++)
		pot[i]=pot[i-1]*2;
	for (int i=0; i<k; i++)
	{
		for (int j=0; j<d; j++)
			if (ory[j]&pot[i])
				gdz[i]|=(1<<j);
	}
	vll wek;
	for (int i=1; i<=n; i++)
	{
		ll x=0;
		for (int j=0; j<k; j++)
		{
			if (!gdz[j])
				continue;
			if (gdz[j]!=jego[i])
				x^=pot[j];
		}
		wek.push_back(x);
	}
	ans(wek);
	return 0;
}