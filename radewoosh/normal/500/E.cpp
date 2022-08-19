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
const int nax=1000*1007;

int n;
ll poz[nax];
ll wys[nax];

ll drz[nax];

ll wyn[nax];
int q;
vector < pair <int,int> > zap[nax];

void pisz(int v, ll w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		drz[i]+=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i>0; i-=(i&(-i)))
		ret+=drz[i];
	return ret;
}

ll brak[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &poz[i], &wys[i]);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		zap[a].push_back({b, i});
	}
	vector <int> stos{n};
	for (int i=n-1; i; i--)
	{
		while(!stos.empty() && poz[i]+wys[i]>=poz[stos.back()]+wys[stos.back()])
		{
			int x=stos.back();
			stos.pop_back();
			if (!stos.empty())
				pisz(stos.back(), -brak[x]);
		}
		if (stos.empty())
		{
			brak[i]=0;
		}
		else
		{
			brak[i]=max(0LL, poz[stos.back()]-(poz[i]+wys[i]));
			pisz(stos.back(), brak[i]);
		}
		stos.push_back(i);
		for (auto j : zap[i])
			wyn[j.second]=czyt(j.first);
	}
	
	for (int i=1; i<=q; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}