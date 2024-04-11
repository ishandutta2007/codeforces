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
const ll inf=3e18;

int n, m, k;

vll wek[3];

ll kwa(ll v)
{
	return v*v;
}

void test()
{
	scanf("%d%d%d", &n, &m, &k);
	wek[0].clear();
	wek[1].clear();
	wek[2].clear();
	for (int i=0; i<n; i++)
	{
		ll x;
		scanf("%lld", &x);
		wek[0].push_back(x);
	}
	for (int i=0; i<m; i++)
	{
		ll x;
		scanf("%lld", &x);
		wek[1].push_back(x);
	}
	for (int i=0; i<k; i++)
	{
		ll x;
		scanf("%lld", &x);
		wek[2].push_back(x);
	}
	for (int i=0; i<3; i++)
		sort(wek[i].begin(), wek[i].end());
	ll wyn=inf;
	for (int s=0; s<3; s++)
	{
		for (int l=0; l<3; l++)
		{
			if (l==s)
				continue;
			int p=3-s-l;
			int a=0;
			int b=0;
			for (ll i : wek[s])
			{
				while(a+1<(int)wek[l].size() && wek[l][a+1]<=i)
					a++;
				while(b+1<(int)wek[p].size() && wek[p][b]<i)
					b++;
				wyn=min(wyn, kwa(i-wek[l][a])+kwa(i-wek[p][b])+kwa(wek[l][a]-wek[p][b]));
			}
		}
	}
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}