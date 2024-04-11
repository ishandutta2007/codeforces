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
int s;

vi jed, resz;

int daj(vi &wek)
{
	int x=wek.back();
	wek.pop_back();
	return x;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		s+=tab[i];
		if (tab[i]==1)
			jed.push_back(i);
		else
			resz.push_back(i);
	}
	if (s<2*(n-1))
	{
		printf("NO\n");
		return 0;
	}
	vi cio;
	if (!jed.empty())
		cio.push_back(daj(jed));
	else
		cio.push_back(daj(resz));
	
	vector <pii> wyn;
	
	while(!resz.empty())
	{
		int x=daj(resz);
		wyn.push_back({cio.back(), x});
		cio.push_back(x);
	}
	
	if (!jed.empty())
	{
		int x=daj(jed);
		wyn.push_back({cio.back(), x});
		cio.push_back(x);
	}
	
	printf("YES %d\n", (int)cio.size()-1);
	for (int i : cio)
	{
		int x=tab[i]-2;
		for (int j=1; j<=x && !jed.empty(); j++)
			wyn.push_back({i, daj(jed)});
	}
	
	assert((int)wyn.size()==n-1);
	printf("%d\n", n-1);
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	
	return 0;
}