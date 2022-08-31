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

const int nax=1007;
const int lax=10007;

int k, q;

double dp[lax][nax];

int main()
{
	scanf("%d%d", &k, &q);
	dp[0][0]=1.0;
	for (int i=0; i<lax-1; i++)
	{
		for (int j=0; j<=i && j<=k; j++)
		{
			dp[i+1][j]+=dp[i][j]*(j)/k;
			dp[i+1][j+1]+=dp[i][j]*(k-j)/k;
		}
	}
	while(q--)
	{
		int p;
		scanf("%d", &p);
		for (int i=1; 1; i++)
		{
			if (dp[i][k]>=(p-0.0000001)/2000.0)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}