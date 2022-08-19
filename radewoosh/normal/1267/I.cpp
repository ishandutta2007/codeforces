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

void ff()
{
	fflush(stdout);
}

map <pii,int> mapa;

int pyt(int a, int b)
{
	if (mapa.count({a, b}))
		return mapa[{a, b}];
	char c;
	printf("? %d %d\n", a, b);
	ff();
	scanf(" %c", &c);
	return mapa[{a, b}]=(c=='<');
}

void ans()
{
	printf("!\n");
	ff();
}

int n;

void sortuj(vi &wek)
{
	for (int i=1; i<(int)wek.size(); i++)
	{
		for (int j=i; j; j--)
		{
			if (pyt(wek[j], wek[j-1]))
				swap(wek[j], wek[j-1]);
			else
				break;
		}
	}
}

void algo3()
{
	vi raz{1, 2};
	vi dwa{3, 4};
	vi trz{5, 6};
	sortuj(raz);
	sortuj(dwa);
	sortuj(trz);
	int g=-1;
	if (pyt(dwa[0], raz[0]) && pyt(trz[0], raz[0]))
		g=1;
	if (pyt(raz[0], dwa[0]) && pyt(trz[0], dwa[0]))
		g=2;
	if (pyt(raz[0], trz[0]) && pyt(dwa[0], trz[0]))
		g=3;
	if (g==2)
		swap(raz, dwa);
	if (g==3)
		swap(trz, raz);
	vi pom{dwa[1], trz[1]};
	sortuj(pom);
	pyt(raz[0], pom[0]);
	ans();
}

void test()
{
	mapa.clear();
	scanf("%d", &n);
	if (n==3)
	{
		algo3();
		return;
	}
	vi raz, dwa, bez;
	for (int i=1; i<n; i++)
	{
		raz.push_back(i);
		dwa.push_back(n+i);
	}
	bez={n, 2*n};
	sortuj(raz);
	sortuj(dwa);
	while((int)raz.size()+(int)dwa.size()>n)
	{
		if (pyt(raz[0], dwa[0]))
			raz.erase(raz.begin());
		else
			dwa.erase(dwa.begin());
	}
	for (int i : bez)
	{
		if ((int)raz.size()==n-1)
			dwa.push_back(i);
		else
			raz.push_back(i);
	}
	sortuj(raz);
	sortuj(dwa);
	while((int)raz.size()+(int)dwa.size()>n)
	{
		if (pyt(raz[0], dwa[0]))
			raz.erase(raz.begin());
		else
			dwa.erase(dwa.begin());
	}
	ans();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}