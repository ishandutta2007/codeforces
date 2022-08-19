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
const ll inf=1e12;

int n;
pll tab[nax];

ll wyn[nax];

vector <pll> wek;

int mf, ms;

ll f(pll v)
{
	return v.first*mf+v.second*ms;
}

bool mniej(pll a, pll b)
{
	return f(a)>f(b);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	for (int i=-1; i<=1; i++)
	{
		for (int j=-1; j<=1; j++)
		{
			mf=i;
			ms=j;
			sort(tab+1, tab+1+n, mniej);
			wek.push_back(tab[1]);
		}
	}
	for (int i=1; i<(1<<((int)wek.size())); i++)
	{
		vll x;
		vll y;
		for (int j=0; j<(int)wek.size(); j++)
		{
			if (i&(1<<j))
			{
				x.push_back(wek[j].first);
				y.push_back(wek[j].second);
			}
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		wyn[__builtin_popcount(i)]=max(wyn[__builtin_popcount(i)], x.back()-x[0]+y.back()-y[0]);
	}
	
	for (int i=1; i<=n; i++)
		wyn[i]=max(wyn[i-1], wyn[i]);
	for (int i=3; i<=n; i++)
		printf("%lld ", wyn[i]*2);
	printf("\n");
	return 0;
}