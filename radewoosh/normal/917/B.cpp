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

const int nax=107;
const int d=30;

int n, m;

vector < pair <int,int> > graf[nax];

int juz[nax][nax][d];
int dp[nax][nax][d];

int licz(int v, int u, int lit)
{
	if (juz[v][u][lit])
		return dp[v][u][lit];
	for (auto i : graf[v])
		if (i.second>=lit && !licz(u, i.first, i.second))
			dp[v][u][lit]=1;
	juz[v][u][lit]=1;
	return dp[v][u][lit];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		graf[a].push_back({b, c-'a'});
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (licz(i, j, 0))
				printf("A");
			else
				printf("B");
		}
		printf("\n");
	}
	return 0;
}