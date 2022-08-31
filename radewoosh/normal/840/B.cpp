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

const int nax=300*1007;

void nope()
{
	printf("-1\n");
	exit(0);
}

int n, m;

int tab[nax];

vector < pair <int,int> > graf[nax];

int bylo[nax];

vector <int> wyn;

int dfs(int v)
{
	if (bylo[v])
		return 0;
	int ret=0;
	bylo[v]=1;
	for (auto i : graf[v])
	{
		int wez=dfs(i.first);
		if (wez)
		{
			ret^=1;
			wyn.push_back(i.second);
		}
	}
	if (tab[v]==1)
		ret^=1;
	if (tab[v]==-1)
		ret=0;
	return ret;
}

void jebnij(int v)
{
	if (dfs(v))
		nope();
	printf("%d\n", (int)wyn.size());
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back({p2, i});
		graf[p2].push_back({p1, i});
	}
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==-1)
		{
			jebnij(i);
			return 0;
		}
	}
	jebnij(1);
	return 0;
}