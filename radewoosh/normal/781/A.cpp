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
vector <int> graf[nax];

int kol[nax];
int il;

set <int> setel;
int w;

void dfs(int v, int oj)
{
	setel.clear();
	setel.insert(kol[v]);
	for (int i=0; i<graf[v].size(); i++)
		setel.insert(kol[graf[v][i]]);
	w=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		while(setel.find(w)!=setel.end())
			w++;
		kol[graf[v][i]]=w;
		il=max(il, w);
		w++;
	}
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs(graf[v][i], v);
	}
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
	kol[1]=1;
	il=1;
	dfs(1, 0);
	printf("%d\n", il);
	for (int i=1; i<=n; i++)
		printf("%d ", kol[i]);
	printf("\n");
	return 0;
}