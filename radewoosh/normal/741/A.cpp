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

int n;
int tab[107];
int pom[107];

int juz[107];

long long wyn=1;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		pom[i]=tab[i];
	}
	sort(pom+1, pom+1+n);
	for (int i=1; i<=n; i++)
	{
		if (pom[i]!=i)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (juz[i])
			continue;
		long long licz=0;
		int u=i;
		while(!juz[u])
		{
			juz[u]=1;
			u=tab[u];
			licz++;
		}
		if (!(licz&1))
			licz>>=1;
		long long naj=__gcd(wyn, licz);
		wyn/=naj;
		wyn*=licz;
	}
	printf("%lld\n", wyn);
	return 0;
}