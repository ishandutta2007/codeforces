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

vi wek[nax];
vector<pii> wyn;

void buduj(int kol, int wys)
{
	wyn.push_back({n+1-wys, kol});
	wek[kol].push_back(wys);
}

void nope()
{
	printf("-1\n");
	exit(0);
}

vi jedy[4];

int daj(int v)
{
	if (v==2)
	{
		if (jedy[1].empty())
			nope();
		int x=jedy[1].back();
		jedy[1].pop_back();
		return x;
	}
	for (int i=3; i; i--)
	{
		if (!jedy[i].empty())
		{
			int x=jedy[i].back();
			jedy[i].pop_back();
			return x;
		}
	}
	nope();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=n; i; i--)
	{
		if (!tab[i])
			continue;
		if (tab[i]==1)
		{
			buduj(i, n+1-i);
			jedy[1].push_back(i);
			continue;
		}
		int x=daj(tab[i]);
		if (tab[i]==2)
		{
			buduj(i, n+1-x);
			jedy[2].push_back(i);
		}
		else
		{
			buduj(i, n+1-i);
			buduj(x, n+1-i);
			jedy[3].push_back(i);
		}
	}
	
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}