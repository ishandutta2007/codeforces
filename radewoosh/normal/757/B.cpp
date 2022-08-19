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
int m=100000;

int ile[1000007];

int aktu;
int wyn=1;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int p1;
		scanf("%d", &p1);
		ile[p1]++;
	}
	for (int i=2; i<=m; i++)
	{
		aktu=0;
		for (int j=i; j<=m; j+=i)
			aktu+=ile[j];
		wyn=max(wyn, aktu);
	}
	printf("%d\n", wyn);
	return 0;
}