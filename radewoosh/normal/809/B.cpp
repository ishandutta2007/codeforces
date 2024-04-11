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

int n, k;

set <int> setel;

char wcz[100];

int znajdz(int a, int b, int lew=1)
{
	if (a==b)
		return a;
	int s=(a+b)>>1;
	if (lew)
	{
		printf("1 %d %d\n", s, s+1);
		fflush(stdout);
		scanf("%s", wcz);
		if (wcz[0]=='T')
			return znajdz(a, s, lew);
		else
			znajdz(s+1, b, lew);
	}
	else
	{
		printf("1 %d %d\n", s+1, s);
		fflush(stdout);
		scanf("%s", wcz);
		if (wcz[0]=='T')
			return znajdz(s+1, b, lew);
		else
			znajdz(a, s, lew);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	setel.insert(znajdz(1, n));
	int x=*setel.begin();
	if (x!=1)
		setel.insert(znajdz(1, x-1));
	if (x!=n)
		setel.insert(znajdz(x+1, n, 0));
	debug() << imie(x);
	int juz=0;
	vector <int> wek;
	for (auto i : setel)
	{
		printf("1 %d %d\n", i, x);
		fflush(stdout);
		scanf("%s", wcz);
		if (wcz[0]=='T')
		{
			wek.push_back(i);
			juz++;
			if (juz==2)
				break;
		}
	}
	printf("2");
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	fflush(stdout);
	return 0;
}