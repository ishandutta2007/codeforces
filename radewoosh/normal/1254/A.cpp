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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=107;

int n, m, k;

char wcz[nax][nax];
int tab[nax][nax];

int faj;

char pyt(int v)
{
	if (v<26)
		return 'a'+v;
	if (v<52)
		return 'A'+(v-26);
	return '0'+(v-52);
}

void test()
{
	scanf("%d%d%d", &n, &m, &k);
	faj=0;
	vector <pii> pola;
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz[i]+1);
		if (i&1)
		{
			for (int j=1; j<=m; j++)
			{
				tab[i][j]=(wcz[i][j]=='R');
				faj+=tab[i][j];
				pola.push_back({i, j});
			}
		}
		else
		{
			for (int j=m; j; j--)
			{
				tab[i][j]=(wcz[i][j]=='R');
				faj+=tab[i][j];
				pola.push_back({i, j});
			}
		}
	}
	int bylo=0;
	int kt=0;
	for (pii i : pola)
	{
		bylo+=tab[i.first][i.second];
		if (bylo>faj*(kt+1)/k)
			kt++;
		kt=min(kt, k-1);
		wcz[i.first][i.second]=pyt(kt);
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%c", wcz[i][j]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}