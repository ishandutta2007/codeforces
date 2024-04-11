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

int n, m, c;

void ff()
{
	fflush(stdout);
}

int tab[nax];

void check()
{
	for (int i=1; i<=n; i++)
		if (tab[i]<tab[i-1])
			return;
	exit(0);
}

int main()
{
	scanf("%d%d%d", &n, &m, &c);
	tab[0]=1;
	tab[n+1]=c;
	while(m--)
	{
		int x;
		scanf("%d", &x);
		if (x*2<=c)
		{
			for (int i=1; i<=n; i++)
			{
				if (!tab[i] || tab[i]>x)
				{
					tab[i]=x;
					printf("%d\n", i);
					ff();
					break;
				}
			}
		}
		else
		{
			for (int i=n; i; i--)
			{
				if (tab[i]<x)
				{
					tab[i]=x;
					printf("%d\n", i);
					ff();
					break;
				}
			}
		}
		
		check();
	}
	return 0;
}