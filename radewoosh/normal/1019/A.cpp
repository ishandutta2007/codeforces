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
const int nax=3007;

int n, m;

vector <ll> wek[nax];

ll wyn=1e18;

vector <pair<ll,pii> > dos;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a==1)
			b=0;
		wek[a].push_back(b);
	}
	for (int i=1; i<=m; i++)
	{
		sort(wek[i].begin(), wek[i].end());
		reverse(wek[i].begin(), wek[i].end());
		for (int j=0; j<(int)wek[i].size(); j++)
			dos.push_back({wek[i][j], {i, j}});
	}
	sort(dos.begin(), dos.end());
	for (int i=1; i<=n; i++)
	{
		ll ter=0;
		int mam=0;
		for (int j=1; j<=m; j++)
		{
			for (int l=i-1; l<(int)wek[j].size(); l++)
			{
				mam++;
				ter+=wek[j][l];
			}
		}
		for (auto j : dos)
		{
			if (mam<i && j.second.second<i-1)
			{
				mam++;
				ter+=j.first;
			}
		}
		wyn=min(wyn, ter);
	}
	
	printf("%lld\n", wyn);
	return 0;
}