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
using ld=long double;
const ld pi=2*acosl(0);

int n, d;
ll tab[nax];

int q;

ld kont(int a)
{
	return atan(1.0/a);
}

ld kont(int a, int b)
{
	assert(abs(a-b)<=1);
	return 2*kont(max(a, b));
}

void out(ld v)
{
	printf("%.11lf\n", (double)v);
}

void query()
{
	ll x;
	scanf("%lld", &x);
	if (x==tab[0] || x==tab[n]+1)
	{
		out(pi/2);
		return;
	}
	int bsa=1;
	int bsb=n-1;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (x>tab[bss])
			bsa=bss;
		else
			bsb=bss-1;
	}
	int g=bsa;
	assert(x>tab[g] && x<=tab[g+1]);
	if (x==tab[g]+1 && x==tab[g+1])
	{
		out(pi);
		return;
	}
	if (x==tab[g]+1 || x==tab[g+1])
	{
		out(pi/2);
		return;
	}
	ld wyn=kont(min(tab[g+1]-x, x-tab[g]-1));
	int a=g;
	int b=g+1;
	const ll lim=min(tab[g+1]-x, x-tab[g]-1)*2+7;
	while(a>0 && b<=n && tab[b]-x<=lim)
	{
		if (abs( (x-tab[a]-1)-(tab[b]-x) )<=1)
			break;
		if (x-tab[a]-1<tab[b]-x)
			a--;
		else
			b++;
	}
	if (a>=1 && b<=n && abs( (x-tab[a]-1)-(tab[b]-x) )<=1)
		wyn=max(wyn, kont(x-tab[a]-1, tab[b]-x));
	out(wyn);
}

int main()
{
	scanf("%d%d", &n, &d);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}