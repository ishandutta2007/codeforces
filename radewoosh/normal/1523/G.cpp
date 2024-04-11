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
const int n1=(1<<16);
const int inf=1e9;

int n, m;

pii tab[nax];
vi szer[nax];

int wyn[nax];

set<pii> drz[nax];

void wloz(set<pii> &setel, pii w)
{
	setel.insert(w);
	auto it=setel.find(w);
	if (it!=setel.begin())
	{
		it--;
		if ((it->second)<(w.second))
		{
			setel.erase(w);
			return;
		}
		it++;
	}
	while(1)
	{
		it=setel.find(w);
		it++;
		if (it==setel.end())
			break;
		if ((w.second)<(it->second))
			setel.erase(it);
		else
			break;
	}
}

void wstaw(int v, pii w)
{
	v+=n1-1;
	while(v)
	{
		wloz(drz[v], w);
		v>>=1;
	}
}

int szmin(int v, int a, int b, int graa, int grab, int lim)
{
	if (a>=graa && b<=grab)
	{
		auto it=drz[v].lower_bound({lim, inf});
		if (it==drz[v].begin())
			return inf;
		it--;
		return it->second;
	}
	if (a>grab || b<graa)
	{
		return inf;
	}
	return min(
		szmin((v<<1), a, (a+b)>>1, graa, grab, lim),
		szmin((v<<1)^1, (a+b+2)>>1, b, graa, grab, lim)
	);
}

int rek(int a, int b)
{
	if (a>b)
		return 0;
	int wez=szmin(1, 1, n1, a, n1, b);
	if (wez>m)
		return 0;
	return tab[wez].second-tab[wez].first+1+rek(a, tab[wez].first-1)+rek(tab[wez].second+1, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &tab[i].first, &tab[i].second);
		szer[tab[i].second-tab[i].first+1].push_back(i);
	}
	
	for (int h=n; h; h--)
	{
		for (int i : szer[h])
			wstaw(tab[i].first, {tab[i].second, i});
		wyn[h]=rek(1, n);
	}
	
	for (int i=1; i<=n; i++)
		printf("%d\n", wyn[i]);
	return 0;
}