//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=1000*1007;

int n;
long long p;

pair <long long,long long> tab[nax];

long long sum;

int check(double v)
{
	double potrz=0.0;
	for (int i=1; i<=n; i++)
	{
		double tu=v*tab[i].first-tab[i].second;
		potrz+=max(0.0, tu);
	}
	if (potrz<=v*p)
		return 1;
	return 0;
}

int main()
{
	scanf("%d%lld", &n, &p);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
		sum+=tab[i].first;
	}
	if (p>=sum)
	{
		printf("-1\n");
		return 0;
	}
	double bsa=0.0;
	double bsb=1e18;
	double bss;
	for (int h=1; h<=150 && bsa<bsb; h++)
	{
		bss=(bsa+bsb)/2.0;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss;
	}
	printf("%.9lf\n", bsa);
	return 0;
}