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
const int nax=10*1007;

ll a, b, c;

pll x, y;

double wyn=1e20;

void kon()
{
	printf("%.9lf\n", wyn);
	exit(0);
}

double odl(pair <double,double> a, pair <double,double> b)
{
	double x=a.first-b.first;
	double y=a.second-b.second;
	debug() << "ter " << sqrt(x*x+y*y) << " " << a << " " << b;
	return sqrt(x*x+y*y);
}

int main()
{
	scanf("%lld%lld%lld", &a, &b, &c);
	scanf("%lld%lld", &x.first, &x.second);
	scanf("%lld%lld", &y.first, &y.second);
	wyn=abs(x.first-y.first)+abs(x.second-y.second);
	if (!a || !b)
		kon();
	for (int h=0; h<2; h++)
	{
		double f=((double)-c-b*x.second)/a;
		double s=((double)-c-a*y.first)/b;
		wyn=min(wyn, odl({x.first, x.second}, {f, x.second})+odl({f, x.second}, {y.first, s})+odl({y.first, s}, {y.first, y.second}));
		swap(x, y);
	}
	for (int h=0; h<2; h++)
	{
		double f=((double)-c-b*x.second)/a;
		double s=((double)-c-b*y.second)/a;
		wyn=min(wyn, odl({x.first, x.second}, {f, x.second})+odl({f, x.second}, {s, y.second})+odl({s, y.second}, {y.first, y.second}));
		swap(x.first, x.second);
		swap(y.first, y.second);
		swap(a, b);
	}
	
	kon();
	return 0;
}