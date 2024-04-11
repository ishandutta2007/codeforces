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

const long long jed=1;

long long wyn;

vector <long long> wek;

long long spyt(long long v)
{
	for (int i=0; i<wek.size(); i++)
	{
		long long jesz=(int)wek.size()-i-1;
		long long x=(jed<<jesz)-1;
		if (v==x+1)
			return wek[i];
		if (v>x+1)
			v-=x+1;
	}
	assert(0);
}

int main()
{
	long long n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	while(n)
	{
		wek.push_back(n%2);
		n/=2;
	}
	for (long long i=l; i<=r; i++)
		wyn+=spyt(i);
	printf("%lld\n", wyn);
	return 0;
}