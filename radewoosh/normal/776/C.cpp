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
long long lim=(long long)10000*10000*10000*10000;

int n;
long long k;

long long s;

map <long long,int> mapa;

long long wyn;

int main()
{
	scanf("%d%lld", &n, &k);
	mapa[0]++;
	for (int i=1; i<=n; i++)
	{
		long long x;
		scanf("%lld", &x);
		s+=x;
		mapa[s]++;
		long long t=1;
		while(t<=lim)
		{
			wyn+=mapa[s-t];
			t*=k;
			if (t==1)
				break;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}