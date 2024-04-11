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
const int nax=10*1007;
const int vax=100*1007;
const int n1=(1<<14);
using bn=bitset<nax>;

int n, q;

bn wyn;

vector <int> dos[vax];

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		dos[v].push_back(w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void dfs(int v, int a, int b, bn trz)
{
	for (int i : dos[v])
		trz=(trz|(trz<<i));
	if (a==b)
	{
		wyn|=trz;
		return;
	}
	dfs((v<<1), a, (a+b)>>1, trz);
	dfs((v<<1)^1, (a+b+2)>>1, b, trz);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=q; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pisz(1, 1, n1, a, b, c);
	}
	bn pus;
	pus[0]=1;
	dfs(1, 1, n1, pus);
	
	vector <int> wyp;
	for (int i=1; i<=n; i++)
		if (wyn[i])
			wyp.push_back(i);
	printf("%d\n", (int)wyp.size());
	for (int i : wyp)
		printf("%d ", i);
	printf("\n");
	return 0;
}