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
const int d=50;

void nope()
{
	printf("-1\n");
}

ll n;
int m;

ll tab[nax];

ll ile[nax];

void test()
{
	scanf("%lld%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+m);
	for (int i=0; i<d; i++)
		ile[i]=0;
	for (int i=1; i<=m; i++)
	{
		ll r=0;
		while((1LL<<r)!=tab[i])
			r++;
		ile[r]++;
	}
	ll sum=0;
	for (int i=1; i<=m; i++)
		sum+=tab[i];
	if (sum<n)
	{
		nope();
		return;
	}
	ll wyn=0;
	ll potrz=0;
	sum=0;
	for (int i=0; i<d; i++)
	{
		int x=(n>>i)&1;
		sum=sum/2+ile[i];
		if (x && sum)
		{
			x=0;
			sum--;
		}
		if (x)
		{
			potrz=1;
		}
		if (sum && potrz)
		{
			sum--;
			potrz=0;
		}
		if (potrz)
			wyn++;
		//~ debug() << i << " " << x << " " << sum << " " << potrz;
	}
	
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
		test();
	return 0;
}