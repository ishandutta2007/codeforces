//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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

using ll=long long;
const int nax=1007;
using pii=pair<int,int>;

int n, k;

int tab[nax][nax];
int kto[nax][nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

vector <pair <int,pii > >wyn;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &kto[2][i]);
	for (int i=2; i<=3; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &tab[i][j]);
	for (int i=1; i<=n; i++)
		scanf("%d", &kto[3][i]);
	
	vector <pii> kol;
	for (int i=1; i<=n; i++)
		kol.push_back({2, i});
	for (int i=n; i; i--)
		kol.push_back({3, i});
	for (int h=0; h<10000; h++)
	{
		for (int i=0; i<2*n; i++)
		{
			pii x=kol[i];
			pii y=kol[(i-1+2*n)%(2*n)];
			if (!tab[x.first][x.second])
				continue;
			if (tab[x.first][x.second]==kto[x.first][x.second])
			{
				wyn.push_back({tab[x.first][x.second], x});
				tab[x.first][x.second]=0;
				//~ debug() << tab[x.first][x.second] << " " << x;
				if (x.first==2)
					wyn.back().second.first=1;
				else
					wyn.back().second.first=4;
				continue;
			}
			if (!tab[y.first][y.second])
			{
				wyn.push_back({tab[x.first][x.second], y});
				tab[y.first][y.second]=tab[x.first][x.second];
				tab[x.first][x.second]=0;
			}
		}
	}
	for (pii i : kol)
		if (tab[i.first][i.second])
			nope();
	
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
		printf("%d %d %d\n", i.first, i.second.first, i.second.second);
	return 0;
}