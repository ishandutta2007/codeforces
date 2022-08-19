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

const int nax=1007;

int n, r;

int tab[nax];

double wyn[nax];

int main()
{
	scanf("%d%d", &n, &r);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		wyn[i]=r;
		for (int j=1; j<i; j++)
		{
			int odl=abs(tab[i]-tab[j]);
			if (odl>2*r)
				continue;
			if (odl==2*r)
			{
				wyn[i]=max(wyn[i], wyn[j]);
			}
			else
			{
				wyn[i]=max(wyn[i], wyn[j]+sqrt((double)(4*r*r-odl*odl)));
			}
		}
	}
	for (int i=1; i<=n; i++)
		printf("%.9lf ", wyn[i]);
	printf("\n");
	return 0;
}