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

int l, r;

const int n=23;

vector<pair<pii,int>>kra;

pll prz[nax];

const int lim=1e6;

int main()
{
	scanf("%d%d", &l, &r);
	for (int i=n-1; i>1; i--)
	{
		ll a=l;
		ll b=l-1;
		for (int j=n; j>i; j--)
		{
			ll dlu=prz[j].second-prz[j].first+1;
			kra.push_back({{i, j}, b+1-prz[j].first});
			b+=dlu;
		}
		prz[i]={a, b};
	}
	//~ debug() << kra;
	ll gor=r+1;
	for (int i=2; i<=n; i++)
	{
		ll dlu=prz[i].second-prz[i].first+1;
		if (gor-dlu>=l && prz[i].first<gor-dlu)
		{
			gor-=dlu;
			kra.push_back({{1, i}, gor-prz[i].first});
		}
	}
	printf("YES\n");
	printf("%d %d\n", n, (int)kra.size());
	for (auto i : kra)
		printf("%d %d %d\n", i.first.first, i.first.second, i.second);
	return 0;
}