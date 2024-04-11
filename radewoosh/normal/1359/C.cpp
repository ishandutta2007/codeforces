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

ll gor, zim, chce;

pll ula(ll v)
{
	ll mi=2*v+1;
	ll li=v*(gor+zim)+gor;
	return {li, mi};
}

void test()
{
	scanf("%lld%lld%lld", &gor, &zim, &chce);
	gor<<=1;
	zim<<=1;
	chce<<=1;
	if (chce<=(gor+zim)/2)
	{
		printf("2\n");
		return;
	}
	ll bsa=0;
	ll bsb=1e6;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb+2)>>1;
		pll wez=ula(bss);
		if (wez.first>=chce*wez.second)
			bsa=bss;
		else
			bsb=bss-1;
	}
	ll lew=bsa;
	ll pra=bsa+1;
	pll wl=ula(lew);
	pll wp=ula(pra);
	pll sr={wl.first*wp.second+wp.first*wl.second, wl.second*wp.second*2};
	if (sr.first<=chce*sr.second)
		printf("%lld\n", 2*lew+1);
	else
		printf("%lld\n", 2*pra+1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}