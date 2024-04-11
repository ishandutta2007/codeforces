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

int najd, gdz;
int s1, s2;

int odl1[nax];
int odl2[nax];

int k;

void dfs1(int v, int oj, int odl)
{
	if (odl>gdz)
	{
		gdz=odl;
		najd=v;
	}
	odl1[v]=odl;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs1(graf[v][i], v, odl+1);
	}
}

void dfs2(int v, int oj, int odl)
{
	odl2[v]=odl;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		dfs2(graf[v][i], v, odl+1);
	}
}

void nope()
{
	printf("-1\n");
	exit(0);
}

void tak(int v)
{
	while(!(v&1))
		v>>=1;
	printf("%d\n", v);
	exit(0);
}

int dfs3(int v, int oj)
{
	vector <int> wek;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			continue;
		wek.push_back(dfs3(graf[v][i], v)+1);
	}
	sort(wek.begin(), wek.end());
	if (v==k)
	{
		vector <int> roz;
		for (int i=0; i<wek.size(); i++)
			if (roz.empty() || wek[i]!=roz.back())
				roz.push_back(wek[i]);
		if ((int)roz.size()==1)
			return roz[0];
		if ((int)roz.size()==2)
			return roz[0]+roz[1];
		nope();
	}
	else
	{
		if (wek.empty())
			return 0;
		if (wek[0]!=wek.back())
			nope();
		return wek[0];
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
	dfs1(1, 0, 1);
	s1=najd;
	najd=gdz=0;
	dfs1(s1, 0, 1);
	s2=najd;
	dfs2(s2, 0, 1);
	debug() << range(odl1+1, odl1+1+n);
	debug() << range(odl2+1, odl2+1+n);
	for (int i=1; i<=n; i++)
		if (odl1[i]+odl2[i]==odl1[s2]+1 && odl1[i]==((odl1[s2]+1)/2))
			k=i;
	tak(dfs3(k, 0));
	return 0;
}