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
sim dor(c) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

int n, m, wl;

int wag[1007];
int pie[1007];
vector <int> graf[1007];

int bylo[1007];

vector < pair < int,int> > wek;
int sw, sp;

int l=0;
int dp[1007][1007];

void dfs(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	sw+=wag[v];
	sp+=pie[v];
	wek.push_back({wag[v], pie[v]});
	for (int i=0; i<graf[v].size(); i++)
		dfs(graf[v][i]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &wl);
	for (int i=1; i<=n; i++)
		scanf("%d", &wag[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &pie[i]);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		wek.clear();
		sw=sp=0;
		dfs(i);
		wek.push_back({sw, sp});
		l++;
		for (int j=0; j<=wl; j++)
			dp[l][j]=dp[l-1][j];
		for (int j=0; j<=wl; j++)
		{
			for (int o=0; o<wek.size(); o++)
			{
				if (j+wek[o].first<=wl)
				{
					dp[l][j+wek[o].first]=max(dp[l][j+wek[o].first], dp[l-1][j]+wek[o].second);
				}
			}
		}
	}
	int wyn=0;
	for (int i=0; i<=wl; i++)
		wyn=max(wyn, dp[l][i]);
	printf("%d\n", wyn);
	return 0;
}