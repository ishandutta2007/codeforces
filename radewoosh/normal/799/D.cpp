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

int n;
long long a, b, h, w;

long long tab[nax];

long long dp[nax];

int czy(pair <long long,long long> czym, pair <long long,long long> co)
{
	if (czym.first>czym.second)
		swap(czym.first, czym.second);
	if (co.first>co.second)
		swap(co.first, co.second);
	if (czym.first>=co.first && czym.second>=co.second)
		return 1;
	return 0;
}

int main()
{
	scanf("%lld%lld%lld%lld%d", &a, &b, &h, &w, &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	reverse(tab+1, tab+1+n);
	if (czy({h, w}, {a, b}))
	{
		printf("0\n");
		return 0;
	}
	dp[1]=1;
	for (int i=1; i<=min(n, 50); i++)
	{
		for (int j=nax-1; j; j--)
		{
			int cel=min(j*tab[i], (long long)nax-1);
			dp[cel]=max(dp[cel], dp[j]);
			dp[j]*=tab[i];
			dp[j]=min(dp[j], max(a, b));
		}
		for (int j=1; j<nax; j++)
		{
			if (czy({w*j, h*dp[j]}, {a, b}) || czy({w*dp[j], h*j}, {a, b}))
			{
				printf("%d\n", i);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}