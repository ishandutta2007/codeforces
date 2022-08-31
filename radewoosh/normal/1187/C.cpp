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

int n, m;

int tab[nax];

int per[nax];

vector <pii> nope;

int czy(int a, int b)
{
	for (int i=a; i<b; i++)
		if (per[i]>per[i+1])
			return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t)
		{
			tab[a]++;
			tab[b]--;
		}
		else
		{
			nope.push_back({a, b});
		}
	}
	for (int i=1; i<=n; i++)
		tab[i]+=tab[i-1];
	int k=2*n;
	int v=1;
	while(v<=n)
	{
		int w=0;
		while(tab[v+w])
			w++;
		k--;
		for (int i=0; i<=w; i++)
			per[v+i]=k;
		v+=w+1;
	}
	debug() << range(per+1, per+1+n) << nope;
	for (pii i : nope)
	{
		if (czy(i.first, i.second))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
		printf("%d ", per[i]);
	printf("\n");
	return 0;
}