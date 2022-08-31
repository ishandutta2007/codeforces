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

pii tab[nax];

vi raz, dwa;

vi wyn;

void cons(vi wek)
{
	if ((int)wek.size()>(int)wyn.size())
		wyn=wek;
}

vi daj1(vi wek)
{
	//~ debug() << "1 " << wek;
	if ((int)wek.size()<=1)
		return wek;
	shandom_ruffle(wek.begin(), wek.end());
	int x=wek.back();
	wek.pop_back();
	vi raz, dwa;
	for (int i : wek)
	{
		int lew=(tab[i].second<tab[x].first);
		int pra=(tab[i].first>tab[x].second);
		if (lew && (!pra || (rand()&1)))
			raz.push_back(i);
		else
			dwa.push_back(i);
	}
	vi ret=daj1(raz);
	ret.push_back(x);
	vi wez=daj1(dwa);
	for (int i : wez)
		ret.push_back(i);
	return ret;
}

vi daj2(vi wek)
{
	debug() << "2 " << wek;
	if ((int)wek.size()<=1)
		return wek;
	shandom_ruffle(wek.begin(), wek.end());
	int x=wek.back();
	wek.pop_back();
	vi raz, dwa;
	for (int i : wek)
	{
		int lew=(tab[i].second>tab[x].first);
		int pra=(tab[i].first<tab[x].second);
		if (lew && (!pra || (rand()&1)))
			raz.push_back(i);
		else
			dwa.push_back(i);
	}
	vi ret=daj2(raz);
	ret.push_back(x);
	vi wez=daj2(dwa);
	for (int i : wez)
		ret.push_back(i);
	return ret;
}

int main()
{
	srand(time(0));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &tab[i].first, &tab[i].second);
		if (tab[i].first>tab[i].second)
			raz.push_back(i);
		if (tab[i].first<tab[i].second)
			dwa.push_back(i);
	}
	if ((int)raz.size()>(int)dwa.size())
		cons(daj1(raz));
	else
		cons(daj2(dwa));
	
	printf("%d\n", (int)wyn.size());
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}