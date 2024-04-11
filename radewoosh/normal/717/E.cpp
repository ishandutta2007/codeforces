#ifndef LOCAL
#define NDEBUG
#endif

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

int n;

int tab[nax];
vector <int> graf[nax];

int ile;

int start;

void wypisz(int v)
{
	printf("%d ", v);
	ile-=tab[v];
	if (start)
		tab[v]^=1;
	start=1;
	ile+=tab[v];
	if (ile==n)
	{
		printf("\n");
		exit(0);
	}
}

void dfs(int v, int oj)
{
	wypisz(v);
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs(graf[v][i], v);
		wypisz(v);
		if (!tab[graf[v][i]])
		{
			wypisz(graf[v][i]);
			wypisz(v);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]++;
		tab[i]/=2;
		ile+=tab[i];
	}
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	dfs(1, 0);
	return 0;
}