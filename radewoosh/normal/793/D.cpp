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

const int nax=83;
const int wax=2007;
const int inf=1000*1000*10+7;

int n, k;
int m;

int tab[nax][nax];

int dp[nax][nax][nax][nax];

int wyn=inf;

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			tab[i][j]=inf;
	for (int i=1; i<=m; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
		tab[p1][p2]=min(tab[p1][p2], p3);
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int l=0; l<=n; l++)
				for (int o=1; o<=n; o++)
					dp[i][j][l][o]=inf;
	for (int j=1; j<=n; j++)
	{
		for (int i=j; i; i--)
		{
			for (int l=i; l<=j; l++)
			{
				dp[i][j][l][1]=0;
				for (int o=2; o<=j-i+1; o++)
				{
					for (int p=i; p<l; p++)
						dp[i][j][l][o]=min(dp[i][j][l][o], dp[i][l-1][p][o-1]+tab[l][p]);
					for (int p=l+1; p<=j; p++)
						dp[i][j][l][o]=min(dp[i][j][l][o], dp[l+1][j][p][o-1]+tab[l][p]);
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
		wyn=min(wyn, dp[1][n][i][k]);
	if (wyn>=(inf/2))
		wyn=-1;
	printf("%d\n", wyn);
	return 0;
}