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

int n, q;
int tab[nax];

map <int,vector<pii>> mapa;

pii wyn[nax];

void przepisz(vector <pii> &a, vector <pii> &b)
{
	if ((int)a.size()>(int)b.size())
		a.swap(b);
	for (pii i : a)
		b.push_back(i);
	a.clear();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		mapa[tab[i]].push_back({0, i});
	}
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			mapa[b].push_back({i, a});
		}
		else
		{
			int a;
			scanf("%d", &a);
			while(1)
			{
				auto it=mapa.begin();
				if ((*it).first>=a)
					break;
				przepisz((*it).second, mapa[a]);
				mapa.erase(it);
			}
		}
	}
	for (auto i : mapa)
		for (pii j : i.second)
			wyn[j.second]=max(wyn[j.second], {j.first, i.first});
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i].second);
	printf("\n");
	return 0;
}