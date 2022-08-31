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

int n, m;

int sito[nax];
int czys[nax];

map<int,int> mapa;

void test()
{
	scanf("%d", &n);
	mapa.clear();
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		mapa[czys[x]]++;
	}
	debug() << imie(mapa);
	int naj=0;
	int naj2=0;
	for (auto i : mapa)
	{
		naj=max(naj, i.second);
		if (!(i.second&1) || i.first==1)
			naj2+=i.second;
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		ll w;
		scanf("%lld", &w);
		int wyn=naj;
		if (w)
			wyn=max(wyn, naj2);
		printf("%d\n", wyn);
	}
}

int main()
{
	czys[1]=1;
	for (int i=2; i<nax; i++)
	{
		if (sito[i])
			continue;
		for (int j=i; j<nax; j+=i)
			sito[j]=i;
		//~ if (i<=10)
			//~ debug() << i << " " << sito[i] << " " << czys[i];
	}
	for (int i=2; i<nax; i++)
	{
		if (!((i/sito[i])%sito[i]))
			czys[i]=czys[i/sito[i]/sito[i]];
		else
			czys[i]=czys[i/sito[i]]*sito[i];
	}
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}