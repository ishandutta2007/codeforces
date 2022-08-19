//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=4007;
const int d=2002;
const ll mod=1000*1000*1000+7;

int n;

char sta[nax];
char kon[nax];

pll dp[nax][nax];

pll dod(pll a, pll b, ll x)
{
	return {(a.first+b.first+b.second*x)%mod, (a.second+b.second)%mod};
}

void test()
{
	scanf("%d", &n);
	scanf("%s", sta+1);
	scanf("%s", kon+1);
	for (int i=0; i<=n; i++)
		for (int j=-n; j<=n; j++)
			dp[i][d+j]={0LL, 0LL};
	dp[0][d].second=1;
	for (int i=0; i<n; i++)
	{
		for (int j=-i; j<=i; j++)
		{
			for (int a=0; a<2; a++)
			{
				if (sta[i+1]==('0'^a))
					continue;
				for (int b=0; b<2; b++)
				{
					if (kon[i+1]==('0'^b))
						continue;
					int now=j;
					if (a)
					{
						if (i&1)
							now++;
						else
							now--;
					}
					if (b)
					{
						if (i&1)
							now--;
						else
							now++;
					}
					dp[i+1][d+now]=dod(dp[i+1][d+now], dp[i][d+j], abs(now));
				}
			}
		}
	}
	
	
	printf("%lld\n", dp[n][d].first);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}