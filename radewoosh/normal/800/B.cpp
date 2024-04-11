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

const int nax=100*1007;
const double inf=1e18;

int n;

double wyn;

pair <double,double> tab[nax];

double ilo_wek(int a, int b, int s)
{
	return (tab[a].first-tab[s].first)*(tab[b].second-tab[s].second)-(tab[b].first-tab[s].first)*(tab[a].second-tab[s].second);
}

double dlu(int a, int b)
{
	return (tab[a].first-tab[b].first)*(tab[a].first-tab[b].first)+(tab[a].second-tab[b].second)*(tab[a].second-tab[b].second);
}

double odl(int a, int b, int s)
{
	return abs(ilo_wek(a, b, s))/sqrt(dlu(a, b));
}

int main()
{
	scanf("%d", &n);
	wyn=inf;
	for (int i=0; i<n; i++)
	{
		scanf("%lf%lf", &tab[i].first, &tab[i].second);
		tab[i+n]=tab[i+2*n]=tab[i];
	}
	for (int i=0; i<n; i++)
	{
		for (int j=i+2; j<i+n; j++)
		{
			wyn=min(wyn, odl(i, j, i+1));
			wyn=min(wyn, odl(i, j, j-1));
		}
	}
	printf("%.9lf\n", wyn/2.0);
	return 0;
}