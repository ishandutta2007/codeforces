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

using ll=long long;
const int nax=1007;
const ll mod=1000*1000*1000+7;

int n;
char wcz[nax];

int k;

ll dp[nax][nax][2];

inline void dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

ll ile[nax];

ll dp2[nax];

ll wyn;

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	scanf("%d", &k);
	if (!k)
	{
		printf("1\n");
		return 0;
	}
	
	dp[0][0][0]=1;
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='0')
		{
			for (int j=0; j<i; j++)
			{
				dod(dp[i][j][0], dp[i-1][j][0]);
				dod(dp[i][j+1][1], dp[i-1][j][1]);
				dod(dp[i][j][1], dp[i-1][j][1]);
			}
		}
		else
		{
			for (int j=0; j<i; j++)
			{
				dod(dp[i][j][1], dp[i-1][j][0]);
				dod(dp[i][j+1][0], dp[i-1][j][0]);
				dod(dp[i][j+1][1], dp[i-1][j][1]);
				dod(dp[i][j][1], dp[i-1][j][1]);
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		dod(ile[i], dp[n][i][0]);
		dod(ile[i], dp[n][i][1]);
	}
	dod(ile[1], mod-1);
	for (int i=2; i<=n; i++)
		dp2[i]=dp2[__builtin_popcount(i)]+1;
	for (int i=1; i<=n; i++)
		if (dp2[i]==k-1)
			dod(wyn, ile[i]);
	printf("%lld\n", wyn);
	return 0;
}