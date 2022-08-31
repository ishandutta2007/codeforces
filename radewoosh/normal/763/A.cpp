#include <bits/stdc++.h>
using namespace std;

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

int n;

int g1, g2;
vector <int> graf[1000007];
int tab[1000007];

vector <int> jak;

void dfs(int v, int oj)
{
	jak.push_back(tab[v]);
	for (int i=0; i<graf[v].size(); i++)
		if (graf[v][i]!=oj)
			dfs(graf[v][i], v);
}

void check(int v)
{
	for (int i=0; i<graf[v].size(); i++)
	{
		jak.clear();
		dfs(graf[v][i], v);
		sort(jak.begin(), jak.end());
		if (jak[0]!=jak.back())
			return;
	}
	printf("YES\n%d\n", v);
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<graf[i].size(); j++)
		{
			if (tab[i]!=tab[graf[i][j]])
			{
				g1=i;
				g2=graf[i][j];
			}
		}
	}
	if (g1)
	{
		check(g1);
		check(g2);
	}
	else
	{
		check(1);
	}
	printf("NO\n");
	return 0;
}