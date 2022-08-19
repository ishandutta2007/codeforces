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

const int nax=2007;
const long long inf=1e18;

int n, k;

long long p;

long long lud[nax];
long long klu[nax];

long long wyn=inf;

int main()
{
	scanf("%d%d%lld", &n, &k, &p);
	for (int i=1; i<=n; i++)
		scanf("%lld", &lud[i]);
	for (int i=1; i<=k; i++)
		scanf("%lld", &klu[i]);
	sort(lud+1, lud+1+n);
	sort(klu+1, klu+1+k);
	for (int i=1; i+n-1<=k; i++)
	{
		long long aktu=0;
		for (int j=1; j<=n; j++)
		{
			int g=i+j-1;
			aktu=max(aktu, abs(lud[j]-klu[g])+abs(klu[g]-p));
		}
		wyn=min(wyn, aktu);
	}
	printf("%lld\n", wyn);
	return 0;
}