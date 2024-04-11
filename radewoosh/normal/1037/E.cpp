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

int n, m, k;

pii kra[nax];

int wyn[nax];

set <pii> akty;

int sto[nax];

vi graf[nax];

set <pii> kolej;

void czysc();

void rwij(pii v)
{
	if (!akty.count(v))
		return;
	int czy=kolej.count({sto[v.first], v.first});
	if (czy)
		kolej.erase({sto[v.first], v.first});
	sto[v.first]--;
	if (czy)
		kolej.insert({sto[v.first], v.first});
	akty.erase(v);
}


void rwijall(int v)
{
	for (int i : graf[v])
		rwij({v, i});
	for (int i : graf[v])
		rwij({i, v});
	czysc();
}

void czysc()
{
	debug() << "Wywo " << kolej;
	while(!kolej.empty() && (*kolej.begin()).first<k)
	{
		pii v=*kolej.begin();
		kolej.erase(v);
		rwijall(v.second);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &kra[i].first, &kra[i].second);
		graf[kra[i].first].push_back(kra[i].second);
		graf[kra[i].second].push_back(kra[i].first);
		akty.insert(kra[i]);
		swap(kra[i].first, kra[i].second);
		akty.insert(kra[i]);
	}
	for (int i=1; i<=n; i++)
	{
		sto[i]=graf[i].size();
		kolej.insert(pii{sto[i], i});
	}
	for (int i=m; i; i--)
	{
		czysc();
		wyn[i]=kolej.size();
		debug() << "ter " << i << " " << kolej;
		rwij(kra[i]);
		swap(kra[i].first, kra[i].second);
		rwij(kra[i]);
	}
	
	
	
	for (int i=1; i<=m; i++)
		printf("%d\n", wyn[i]);
	return 0;
}