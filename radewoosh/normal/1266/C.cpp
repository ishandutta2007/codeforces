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
const int nax=1007;

int n, m;

int tab[nax][nax];

int per[nax];

unordered_set <int> setel;
	
void probuj()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			int a=per[i];
			int b=per[n+j];
			int w=a/__gcd(a, b)*b;
			tab[i][j]=w;
		}
	}
	setel.clear();
	for (int i=1; i<=n; i++)
	{
		int w=0;
		for (int j=1; j<=m; j++)
		{
			w=__gcd(w, tab[i][j]);
		}
		if (setel.count(w))
			return;
		setel.insert(w);
	}
	for (int i=1; i<=m; i++)
	{
		int w=0;
		for (int j=1; j<=n; j++)
		{
			w=__gcd(w, tab[j][i]);
		}
		if (setel.count(w))
			return;
		setel.insert(w);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	if (n==1 && m==1)
	{
		printf("0\n");
		return 0;
	}
	iota(per+1, per+1+n+m, 1);
	while(1)
	{
		probuj();
		shandom_ruffle(per+1, per+1+n+m);
	}
	return 0;
}