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

int n, k;

int tab[nax];

int pie[nax];
int ost[nax];

int pokr[nax];

int wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		pie[i]=n+1;
		ost[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		pie[tab[i]]=min(pie[tab[i]], i);
		ost[tab[i]]=max(ost[tab[i]], i);
	}
	vector<pii> wek, pom;
	for (int i=1; i<=n; i++)
		if (pie[i]<ost[i])
			wek.push_back({pie[i], ost[i]});
	sort(wek.begin(), wek.end());
	for (pii i : wek)
	{
		if (!pom.empty() && pom.back().second>i.second)
			continue;
		pom.push_back(i);
	}
	//~ debug() << wek;
	pom.swap(wek);
	//~ debug() << wek;
	for (pii i : wek)
	{
		pokr[i.first+1]++;
		pokr[i.second]--;
	}
	for (int i=1; i<=n; i++)
	{
		pokr[i]+=pokr[i-1];
		if (pokr[i])
			wyn++;
	}
	int v=0;
	while(v+1<(int)wek.size())
	{
		if (wek[v+1].first>wek[v].second)
		{
			v++;
			continue;
		}
		int w=v;
		while(w+1<(int)wek.size() && wek[w+1].first<wek[v].second)
			w++;
		//~ debug() << v << " " << w;
		v=w;
		wyn--;
	}
	
	printf("%d\n", wyn);
	return 0;
}