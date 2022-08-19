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
const int nax=2007;

int n, k;
vi sub[nax];

void ff()
{
	fflush(stdout);
}

int pyt(vi wek)
{
	printf("? %d", (int)wek.size());
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

vi daj(int a, int b)
{
	vi ret;
	for (int i=a; i<=b; i++)
		ret.push_back(i);
	return ret;
}

int ter[nax];

char wcz[nax];

void test()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		int r;
		scanf("%d", &r);
		sub[i].clear();
		while(r--)
		{
			int x;
			scanf("%d", &x);
			sub[i].push_back(x);
		}
	}
	int naj=pyt(daj(1, n));
	int bsa=1;
	int bsb=n;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		if (pyt(daj(1, bss))==naj)
			bsb=bss;
		else
			bsa=bss+1;
	}
	int g=bsa;
	vi wyn;
	for (int i=1; i<=k; i++)
	{
		for (int i=1; i<=n; i++)
			ter[i]=0;
		for (int j : sub[i])
			ter[j]=1;
		if (!ter[g])
		{
			wyn.push_back(naj);
			continue;
		}
		vi wek;
		for (int i=1; i<=n; i++)
			if (!ter[i])
				wek.push_back(i);
		wyn.push_back(pyt(wek));
	}
	
	printf("!");
	for (int i : wyn)
		printf(" %d", i);
	printf("\n");
	ff();
	scanf("%s", wcz);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}