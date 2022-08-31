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

int n, k;

long long wyn=1;

int drzewo[1000007];

int x=1;
int nx;

int dodaj(int v)
{
	for (int i=v; i<=n; i+=(i&-i))
		drzewo[i]++;
}

int czytaj(int v, int u)
{
	int ret=0;
	for (int i=v-1; i; i-=(i&-i))
		ret-=drzewo[i];
	for (int i=u; i; i-=(i&-i))
		ret+=drzewo[i];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	if (k>n-k)
		k=n-k;
	for (int i=1; i<=n; i++)
	{
		nx=x+k;
		if (nx>n)
		{
			nx-=n;
			wyn+=1+2*(czytaj(x+1, n)+czytaj(1, nx))+(i!=n);
		}
		else
		{
			wyn+=1+2*czytaj(x+1, nx);
		}
		x=nx;
		dodaj(nx);
		printf("%lld ", wyn);
	}
	printf("\n");
	return 0;
}