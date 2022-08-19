//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

const int nax=200*1007;
const long long mod=1000*1000*1000+7;

int n;

long long tab[nax];

long long sil[nax];
long long osil[nax];

long long wyn;

long long dziel(long long a, long long b)
{
	a%=mod;
	b%=mod;
	long long wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
		{
			a*=b;
			a%=mod;
		}
		b*=b;
		b%=mod;
		wyk>>=1;
	}
	return a;
}

long long kom(long long a, long long b)
{
	return (sil[a]*((osil[b]*osil[a-b])%mod))%mod;
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	osil[nax-1]=dziel(1, sil[nax-1]);
	for (int i=nax-2; i>=0; i--)
		osil[i]=(osil[i+1]*(i+1))%mod;
	
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	while(1)
	{
		if (n==1)
		{
			printf("%lld\n", tab[1]);
			break;
		}
		if (n&1)
		{
			for (int i=1; i<n; i++)
			{
				if (i&1)
					tab[i]=(tab[i]+tab[i+1])%mod;
				else
					tab[i]=(tab[i]-tab[i+1]+mod)%mod;
			}
			n--;
			continue;
		}
		if ((n%4)==2)
		{
			for (int i=1; i<=n; i++)
			{
				wyn+=tab[i]*kom(n/2-1, (i-1)/2);
				wyn%=mod;
			}
			wyn%=mod;
			wyn+=mod;
			wyn%=mod;
			printf("%lld\n", wyn);
			return 0;
		}
		else
		{
			for (int i=1; i<=n; i++)
			{
				if (i&1)
					wyn+=tab[i]*kom(n/2-1, (i-1)/2);
				else
					wyn-=tab[i]*kom(n/2-1, (i-1)/2);
				wyn%=mod;
			}
			wyn%=mod;
			wyn+=mod;
			wyn%=mod;
			printf("%lld\n", wyn);
			return 0;
		}
	}
	return 0;
}