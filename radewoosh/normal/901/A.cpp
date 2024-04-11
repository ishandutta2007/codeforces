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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

#define shandom_ruffle random_shuffle

const int nax=1000*1007;

int n;

int tab[nax];

int per=1;

int l;
vector <int> wek[nax];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		if (i>1 && tab[i]>1 && tab[i-1]>1)
			per=0;
	}
	if (per)
	{
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=tab[i]; j++)
		{
			l++;
			wek[i].push_back(l);
		}
	}
	for (int h=0; h<2; h++)
	{
		printf("0");
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<tab[i]; j++)
			{
				if (tab[i-1]==1)
					printf(" %d", wek[i-1][0]);
				else
					printf(" %d", wek[i-1][min(j, h)]);
			}
		}
		printf("\n");
	}
	return 0;
}