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
ll mod;

int n;
pii tab[nax][2];

ll los[nax];
ll wyn[nax];

void licz(int v)
{
	for (int h=0; h<2; h++)
	{
		map <int,vector<pii>> mapa;
		for (int i=1; i<=n; i++)
			mapa[tab[i][v].first].push_back({i, 0});
		for (int i=1; i<=n; i++)
			mapa[tab[i][v].second].push_back({i, 1});
		ll trz=0;
		for (auto i : mapa)
		{
			for (pii j : i.second)
			{
				if (!j.second)
				{
					wyn[j.first]^=trz;
				}
				else
				{
					trz^=los[j.first];
				}
			}
		}
		
		for (int i=1; i<=n; i++)
		{
			swap(tab[i][v].first, tab[i][v].second);
			tab[i][v].first*=-1;
			tab[i][v].second*=-1;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			scanf("%d%d", &tab[i][j].first, &tab[i][j].second);
	for (int i=1; i<=n; i++)
		for (int j=0; j<18; j++)
			los[i]=los[i]*10+(rand()%10);
	for (int h=0; h<2; h++)
		licz(h);
	for (int i=1; i<=n; i++)
	{
		if (wyn[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}