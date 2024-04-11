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

const int nax=1007;

int n;
long long tab[nax][5];

long long odl[nax][nax];

vector <int> moz;

vector <int> wyn;

int check(int v)
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		{
			if (i==j || i==v || v==j)
				continue;
			if (odl[v][i]+odl[v][j]>odl[i][j])
				return 0;
		}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=0; j<5; j++)
			scanf("%lld", &tab[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int l=0; l<5; l++)
				odl[i][j]+=(tab[i][l]-tab[j][l])*(tab[i][l]-tab[j][l]);
	for (int i=1; i<=n; i++)
		moz.push_back(i);
	while((int)moz.size()>3)
	{
		int x=moz.back();
		moz.pop_back();
		int y=moz.back();
		moz.pop_back();
		int z=moz.back();
		if (odl[x][y]+odl[x][z]<=odl[y][z])
			moz.push_back(x);
		else
			moz.push_back(y);
	}
	sort(moz.begin(), moz.end());
	for (int i : moz)
		if (check(i))
			wyn.push_back(i);
	printf("%d\n", (int)wyn.size());
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}