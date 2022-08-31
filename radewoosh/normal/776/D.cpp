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

const int nax=1000*1007;

int n, m;

int tab[nax];
vector < pair <int,int> > graf[nax];

vector <int> zaw[nax];

int kol[nax];

int czy=1;

void dfs(int v, int u)
{
	if (kol[v])
	{
		if (kol[v]!=u)
			czy=0;
		return;
	}
	kol[v]=u;
	for (int i=0; i<graf[v].size(); i++)
		dfs(graf[v][i].first, u^graf[v][i].second);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d", &p1);
		while(p1--)
		{
			scanf("%d", &p2);
			zaw[p2].push_back(i);
		}
	}
	for (int i=1; i<=n; i++)
	{
		graf[zaw[i][1]].push_back({zaw[i][0], tab[i]^1});
		graf[zaw[i][0]].push_back({zaw[i][1], tab[i]^1});
	}
	for (int i=1; i<=m; i++)
	{
		if (kol[i])
			continue;
		dfs(i, 2);
	}
	if (czy)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}