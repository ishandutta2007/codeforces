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

int n;

int tab[nax];

set<int> setel;

vector<pii> wyn;
vi podz;

void obroc(int v)
{
	for (int i=0; i<v; i++)
		wyn.push_back({n-v+i, tab[n-i]});
	reverse(tab+n-v+1, tab+n+1);
	podz.push_back(2*v);
}

void test()
{
	scanf("%d", &n);
	setel.clear();
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		if (setel.count(tab[i]))
			setel.erase(tab[i]);
		else
			setel.insert(tab[i]);
	}
	if (!setel.empty())
	{
		printf("-1\n");
		return;
	}
	wyn.clear();
	podz.clear();
	
	while(n>0)
	{
		int g=n-1;
		while(tab[g]!=tab[n])
			g--;
		obroc(n-g);
		obroc(n-g+1);
		podz.push_back(2);
		n-=2;
	}
	reverse(podz.begin(), podz.end());
	
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	printf("%d\n", (int)podz.size());
	for (int i : podz)
		printf("%d ", i);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}