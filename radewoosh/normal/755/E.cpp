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

int main()
{
	scanf("%d%d", &n, &k);
	if (n<=3)
	{
		printf("-1\n");
		return 0;
	}
	if (n==4)
	{
		if (k!=3)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			printf("3\n1 2\n2 3\n3 4\n");
			return 0;
		}
	}
	if (k==2)
	{
		printf("%d\n", n-1);
		for (int i=1; i<n; i++)
			printf("%d %d\n", i, i+1);
		return 0;
	}
	if (k==3)
	{
		printf("%d\n", n-1);
		printf("1 2\n");
		for (int i=3; i<=n; i++)
				printf("%d %d\n", i, (i&1)+1);
		return 0;
	}
	printf("-1\n");
	return 0;
}