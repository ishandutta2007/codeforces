#include <bits/stdc++.h>
using namespace std;

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=1000*1007;

int n;
int tab[nax];
int wyn[nax];
int l;
int gdz[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		if (tab[tab[i]]!=tab[i])
		{
			printf("-1\n");
			return 0;
		}
		if (tab[i]==i)
		{
			l++;
			wyn[l]=i;
			gdz[i]=l;
		}
	}
	printf("%d\n", l);
	for (int i=1; i<=n; i++)
		printf("%d ", gdz[tab[i]]);
	printf("\n");
	for (int i=1; i<=l; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}