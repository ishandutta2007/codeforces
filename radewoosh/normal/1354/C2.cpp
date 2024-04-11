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
using ld=double;
const ld pi=2*acosl(0);

int n;
ld kat;
ld ram;

ld licz(ld v)
{
	ld gor=0;
	ld dol=0;
	ld lew=0;
	ld pra=0;
	for (int i=0; i<2*n; i++)
	{
		ld x=sin(kat*i+v);
		ld y=cos(kat*i+v);
		gor=max(gor, x);
		dol=min(dol, x);
		pra=max(pra, y);
		lew=min(lew, y);
	}
	
	return max(gor-dol, pra-lew);
}

void test()
{
	scanf("%d", &n);
	kat=pi/n;
	ram=1/sin(kat/2)/2;
	ld tsa=0;
	ld tsb=kat;
	for (int h=0; h<100; h++)
	{
		ld ts1=(2*tsa+tsb)/3;
		ld ts2=(tsa+2*tsb)/3;
		if (licz(ts1)<licz(ts2))
			tsb=ts2;
		else
			tsa=ts1;
	}
	ld sr=(tsa+tsb)/2;
	printf("%.11lf\n", licz(sr)*ram);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}