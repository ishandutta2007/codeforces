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
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;

int m;
pll tab[nax];

vector <int> gru[nax];
vector <pii> dzie[nax];

ll dlu(pll v)
{
	return v.first*v.first+v.second*v.second;
}

pll dod(pll a, pll b)
{
	return {a.first+b.first, a.second+b.second};
}

pll obr(pll v)
{
	return {-v.first, -v.second};
}

int lacz(int v, int u)
{
	pll nor=dod(tab[v], tab[u]);
	pll prz=dod(tab[v], obr(tab[u]));
	if (dlu(nor)<dlu(prz))
	{
		m++;
		dzie[m].push_back({v, 1});
		dzie[m].push_back({u, 1});
		tab[m]=nor;
	}
	else
	{
		m++;
		dzie[m].push_back({v, 1});
		dzie[m].push_back({u, -1});
		tab[m]=prz;
	}
	return m;
}

int typ(pll v)
{
	int a=(v.first>=0);
	int b=(v.second>=0);
	return (a==b);
}

int odp[nax];

int main()
{
	scanf("%d", &n);
	m=n;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
		gru[typ(tab[i])].push_back(i);
	}
	while((int)gru[0].size()>1 || (int)gru[1].size()>1)
	{
		for (int i=0; i<2; i++)
		{
			if ((int)gru[i].size()>1)
			{
				int a=gru[i].back();
				gru[i].pop_back();
				int b=gru[i].back();
				gru[i].pop_back();
				int w=lacz(a, b);
				gru[typ(tab[w])].push_back(w);
			}
		}
	}
	if (!gru[0].empty() && !gru[1].empty())
		lacz(gru[0][0], gru[1][0]);
	odp[m]=1;
	for (int i=m; i; i--)
		for (pii j : dzie[i])
			odp[j.first]=odp[i]*j.second;
	for (int i=1; i<=n; i++)
		printf("%d ", odp[i]);
	printf("\n");
	debug() << tab[m];
	return 0;
}