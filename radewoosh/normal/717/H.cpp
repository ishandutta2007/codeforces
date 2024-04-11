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

int n, m, t;

pair <int,int> kra[nax];

int g[nax];
int kt[nax];
vector <int> faj[nax];

int main()
{
	srand(69);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d%d", &kra[i].first, &kra[i].second);
	for (int i=1; i<=n; i++)
	{
		int p1, p2;
		scanf("%d", &p1);
		while(p1--)
		{
			scanf("%d", &p2);
			faj[i].push_back(p2);
			t=max(t, p2);
		}
	}
	while(1)
	{
		for (int i=1; i<=t; i++)
			kt[i]=(rand()&1)+1;
		for (int i=1; i<=n; i++)
			g[i]=faj[i][rand()%faj[i].size()];
		int w=0;
		for (int i=1; i<=m; i++)
			w+=(kt[g[kra[i].first]]!=kt[g[kra[i].second]]);
		if (w*2<m)
			continue;
		for (int i=1; i<=n; i++)
			printf("%d ", g[i]);
		printf("\n");
		for (int i=1; i<=t; i++)
			printf("%d ", kt[i]);
		printf("\n");
		break;
	}
	return 0;
}