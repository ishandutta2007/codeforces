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

const int nax=507*1007;
const long long mod=1000*1000*1000+7;

int f, w, h;

long long sil[nax];
long long odw[nax];

long long gd, wsz;

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

inline long long komb(long long a, long long b)
{
	if (a<0)
		return 0;
	if (b<0 || b>a)
		return 0;
	return (sil[a]*((odw[b]*odw[a-b])%mod))%mod;
}

inline long long komz(long long a, long long b)
{
	if (a<0)
		return 0;
	if (!a && !b)
		return 1;
	return komb(a+b-1, b);
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[nax-1]=dziel(1, sil[nax-1]);
	for (int i=nax-2; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	scanf("%d%d%d", &f, &w, &h);
	h++;
	for (int o=1; o<=2; o++)
	{
		swap(f, w);
		for (int i=1; i<=f+w; i++)
		{
			long long pie=(i+1)/2;
			long long dru=i/2;
			wsz+=komz(pie, f-pie)*komz(dru, w-dru);
			wsz%=mod;
		}
	}
	
	for (int i=1; i<=f+w; i++)
	{
		long long pie=(i+1)/2;
		long long dru=i/2;
		
		gd+=komz(pie, f-pie)*komz(dru, w-h*dru);
		gd%=mod;
		
		gd+=komz(pie, w-h*pie)*komz(dru, f-dru);
		gd%=mod;
		
		debug() << i << " " << komz(pie, f-pie) << " " << komz(dru, w-h*dru);
		debug() << i << " " << komz(pie, w-h*pie) << " " << komz(dru, f-dru);
		debug() << "KURWA"  << dru << " " << w-h*dru;
	}
	debug() << gd << " " << wsz;
	printf("%lld\n", dziel(gd, wsz));
	return 0;
}