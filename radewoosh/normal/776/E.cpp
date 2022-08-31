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
const long long mod=1000*1000*1000+7;

long long n, k;

long long f(long long v)
{
	vector <long long> wek;
	for (long long i=2; i*i<=v; i++)
	{
		if (!(v%i))
		{
			wek.push_back(i);
			v/=i;
			i--;
		}
	}
	if (v)
		wek.push_back(v);
	sort(wek.begin(), wek.end());
	long long ret=1;
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (!i || wek[i]!=wek[i-1])
			ret*=(wek[i]-1);
		else
			ret*=wek[i];
	}
	return ret;
}

int main()
{
	scanf("%lld%lld", &n, &k);
	k=(k+1)/2;
	for (long long i=1; i<=k && n>1; i++)
		n=f(n);
	printf("%lld\n", n%mod);
	return 0;
}