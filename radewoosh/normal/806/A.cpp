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

const long long inf=1000*1000*1007;

int t;

long long x, y;
long long p, q;

long long wyn;

long long bsa, bsb, bss;

int check(long long v)
{
	long long tot=v*q;
	if (tot<y)
		return 0;
	long long gmini=x;
	long long gmaxi=x+(tot-y);
	long long chce=p*v;
	return (gmini<=chce && chce<=gmaxi);
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &x, &y);
		scanf("%lld%lld", &p, &q);
		if (q==1)
		{
			if (p==1)
			{
				if (x==y)
					printf("0\n");
				else
					printf("-1\n");
			}
			else
			{
				if (!x)
					printf("0\n");
				else
					printf("-1\n");
			}
			continue;
		}
		bsa=0;
		bsb=inf;
		while(bsa<bsb)
		{
			bss=(bsa+bsb)/2;
			if (check(bss))
				bsb=bss;
			else
				bsa=bss+1;
		}
		printf("%lld\n", bsa*q-y);
	}
	return 0;
}