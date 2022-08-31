//#ifndef LOCAL
//#define NDEBUG
//#endif

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

const int nax=100;
const int dax=50*1000;

int n;
long long c0, c1;

int roz[nax+2];
vector <int> wek[nax+2];
int gdz;

long long wyn;

int main()
{
	srand(time(0));
	scanf("%d%lld%lld", &n, &c0, &c1);
	
	n--;
	if (c0>c1)
		swap(c0, c1);
	
	for (int i=1; i<=nax; i++)
		wek[i].resize(dax, 0);
	
	wyn=n*(c0+c1);
	while(n)
	{
		int bes=0;
		long long tam=c0*gdz;
		for (int i=1; wek[i][roz[i]]; i++)
		{
			if (i*c1+roz[i]*c0<tam)
			{
				tam=i*c1+roz[i]*c0;
				bes=i;
			}
		}
		if (!bes)
		{
			if (gdz<dax)
				wek[1][gdz]++;
			gdz++;
			n--;
			wyn+=tam;
		}
		else
		{
			int x=min(n, wek[bes][roz[bes]]);
			wek[bes][roz[bes]]=0;
			wek[bes][roz[bes]+1]+=x;
			wek[bes+1][roz[bes]]+=x;
			roz[bes]++;
			n-=x;
			wyn+=tam*x;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}