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

int n;
int tab[nax];

vector <pii> wyn;

void zam(int a, int b)
{
	debug() << a << " " << b;
	swap(tab[a], tab[b]);
	wyn.push_back({a, b});
	assert(abs(a-b)*2>=n);
}

void zam2(int i, int x)
{
	if (i==x)
		return;
	if (i*2<=n && x*2<=n)
	{
		zam(i, n);
		zam(x, n);
		zam(i, n);
		return;
	}
	if (i*2>n && x*2>n)
	{
		zam(i, 1);
		zam(x, 1);
		zam(i, 1);
		return;
	}
	if (i*2<=n && x*2>n)
	{
		zam(i, n);
		zam(1, n);
		zam(1, x);
		zam(1, n);
		zam(i, n);
		return;
	}
	if (i*2>n && x*2<=n)
	{
		zam(i, 1);
		zam(n, 1);
		zam(n, x);
		zam(n, 1);
		zam(i, 1);
		return;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	debug() << range(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==i)
			continue;
		vi wek;
		int v=i;
		while(1)
		{
			wek.push_back(v);
			v=tab[v];
			if (v==i)
				break;
		}
		for (int j=1; j<(int)wek.size(); j++)
			zam2(wek[0], wek[j]);
	}
	debug() << range(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
		assert(tab[i]==i);
	
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}