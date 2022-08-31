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

void fre() {
#ifndef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;

long long tab[1000007];
long long dp[1000007];

long long inf=(long long)1000*000*1000*000*1000*000;

long long ma;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]+=tab[i-1];
	}
	ma=tab[n];
	for (int i=n-1; i; i--)
	{
		dp[i]=ma;
		ma=max(ma, tab[i]-dp[i]);
	}
	printf("%lld\n", dp[1]);
	return 0;
}