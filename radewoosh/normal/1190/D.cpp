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

int n;
pll tab[nax];

ordered_set <ll> setel;

map <ll,int> ile;
map <ll,vll> mapa;

ll wyn;

bool mniej(pll a, pll b)
{
	swap(a.first, a.second);
	swap(b.first, b.second);
	return a<b;
}

ll pod(ll v)
{
	return v*(v+1)/2;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	sort(tab+1, tab+1+n, mniej);
	vector <pll> pom;
	for (int i=1; i<=n; i++)
	{
		while(!pom.empty() && pom.back()==tab[i])
			pom.pop_back();
		pom.push_back(tab[i]);
	}
	n=pom.size();
	for (int i=0; i<n; i++)
		tab[i+1]=pom[i];
	for (int i=1; i<=n; i++)
	{
		ile[tab[i].first]++;
		mapa[tab[i].second].push_back(tab[i].first);
		setel.insert(tab[i].first);
	}
	for (auto i : mapa)
	{
		ll r=pod(setel.size());
		ll ost=0;
		for (ll j : i.second)
		{
			ll x=setel.order_of_key(j)+1;
			r-=pod(x-ost-1);
			ost=x;
		}
		r-=pod(setel.size()-ost);
		wyn+=r;
		for (ll j : i.second)
		{
			ile[j]--;
			if (!ile[j])
				setel.erase(j);
		}
	}
	printf("%lld\n", wyn);
	return 0;
}