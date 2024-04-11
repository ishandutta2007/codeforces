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
const int nax=100*1007;

void ff()
{
	fflush(stdout);
}

int n;

int pyt(int v)
{
	v%=n;
	printf("? %d\n", (v+1));
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

void ans(int v)
{
	if (v==-1)
	{
		printf("! -1\n");
	}
	else
	{
		v%=n;
		printf("! %d\n", (v+1));
	}
	ff();
	exit(0);
}

int main()
{
	scanf("%d", &n);
	if (n&2)
		ans(-1);
	int a=pyt(0);
	int b=pyt(n/2);
	int bsa, bsb, bss;
	if (a==b)
		ans(0);
	if (a<b)
	{
		bsa=0;
		bsb=n/2;
	}
	else
	{
		bsa=n/2;
		bsb=n;
	}
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		int a=pyt(bss);
		int b=pyt(bss+n/2);
		if (a==b)
			ans(bss);
		if (a<b)
			bsa=bss;
		else
			bsb=bss;
	}
	return 0;
}