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

const int nax=507;
const int dax=61;

int n, m;

struct mac
{
	bitset <nax> tab[nax];
	int z1()
	{
		for (int i=1; i<=n; i++)
			if (tab[1][i])
				return 1;
		return 0;
	}
	void wypisz()
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				debug() << i << " " << j << " " << (int)tab[i][j];
			}
		}
	}
};

mac operator *(mac &a, mac &b)
{
	mac ret;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (a.tab[i][j])
				ret.tab[i]|=b.tab[j];
	return ret;
}

mac pot[2][dax+2];

mac start, pom;

long long wyn;
long long jed=1;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
			pot[p3][0].tab[p1][p2]=1;
	}
	for (int i=1; i<=dax; i++)
	{
		pot[0][i]=pot[0][i-1]*pot[1][i-1];
		pot[1][i]=pot[1][i-1]*pot[0][i-1];
	}
	start.tab[1][1]=1;
	int prze=0;
	for (int i=dax; i>=0; i--)
	{
		pom=start*pot[prze][i];
		if (pom.z1())
		{
			wyn+=(jed<<i);
			start=pom;
			prze^=1;
		}
	}
	if (wyn>(long long)1000*1000*1000*1000*1000*1000)
	    wyn=-1;
	printf("%lld\n", wyn);
	return 0;
}