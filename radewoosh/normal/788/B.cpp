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
const long long inf=(long long)1000*1000*1000*1000*1000*1000;

int n, m;

vector <int> graf[nax];
int pe[nax];

int bylo[nax];

long long wyn;

int ilep;

void dfs(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
		dfs(graf[v][i]);
}

void dodaj(long long v)
{
	wyn+=(v*(v-1))/2;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		if (p1==p2)
		{
			pe[p1]++;
			continue;
		}
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	int z=-1;
	for (int i=1; i<=n; i++)
		if (pe[i] || !graf[i].empty())
			z=i;
	dfs(z);
	for (int i=1; i<=n; i++)
	{
		if ((pe[i] || !graf[i].empty()) && !bylo[i])
		{
			printf("0\n");
			return 0;
		}
	}
	for (int i=1; i<=n; i++)
		ilep+=pe[i];
	while(ilep)
	{
		wyn+=m-1;
		ilep--;
		m--;
	}
	for (int i=1; i<=n; i++)
	{
		dodaj((int)graf[i].size());
	}
	printf("%lld\n", wyn);
	return 0;
}