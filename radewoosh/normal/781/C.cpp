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

int n, m, k;
vector <int> graf[nax];

int bylo[nax];

int lim;

int num=1;
int juz;

vector <int> tra[nax];

void dfs(int v)
{
	bylo[v]=1;
	juz++;
	tra[num].push_back(v);
	if (juz==lim)
	{
		juz=0;
		num++;
	}
	for (int i=0; i<graf[v].size(); i++)
	{
		if (bylo[graf[v][i]])
			continue;
		dfs(graf[v][i]);
		
		juz++;
		tra[num].push_back(v);
		if (juz==lim)
		{
			juz=0;
			num++;
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	lim=(2*n+k-1)/k;
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	dfs(1);
	for (int i=1; i<=k; i++)
		if (tra[i].empty())
			tra[i].push_back(1);
	for (int i=1; i<=k; i++)
	{
		printf("%d", (int)tra[i].size());
		for (int j=0; j<tra[i].size(); j++)
			printf(" %d", tra[i][j]);
		printf("\n");
	}
	return 0;
}