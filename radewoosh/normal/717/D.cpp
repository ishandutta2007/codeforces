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

const int nax=128;

int n, x;

struct mac
{
	double tab[nax][nax];
	mac()
	{
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				tab[i][j]=0.0;
	}
	mac(int v)
	{
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				tab[i][j]=0.0;
		for (int i=0; i<nax; i++)
			tab[i][i]=1.0;
	}
};

mac operator * (mac a, mac b)
{
	mac ret=mac();
	for (int i=0; i<nax; i++)
		for (int j=0; j<nax; j++)
			for (int l=0; l<nax; l++)
				ret.tab[i][l]+=a.tab[i][j]*b.tab[j][l];
	return ret;
}

mac raz;

mac trz;

int main()
{
	scanf("%d%d", &n, &x);
	for (int i=0; i<=x; i++)
	{
		double p1;
		scanf("%lf", &p1);
		for (int j=0; j<nax; j++)
			raz.tab[j][j^i]+=p1;
	}
	trz=mac(1);
	while(n)
	{
		if (n&1)
			trz=trz*raz;
		raz=raz*raz;
		n>>=1;
	}
	printf("%.9lf\n", 1.0-trz.tab[0][0]);
	return 0;
}