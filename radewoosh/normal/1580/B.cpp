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
const int nax=107;
ll mod;

int n, m, k;

ll kom[nax][nax];

ll dp[nax][nax][nax];//gl, n, ile

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%d%d%lld", &n, &m, &k, &mod);
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	dp[0][0][0]=1;
	for (int i=1; i<=n; i++)
		dp[0][i][0]=(dp[0][i-1][0]*i)%mod;
	dp[1][0][1]=1;
	for (int i=1; i<=n; i++)
		dp[1][i][1]=(dp[1][i-1][1]*i)%mod;
	dp[1][0][0]=1;
	dp[1][0][1]=0;
	for (int h=2; h<=m; h++)
	{
		dp[h][0][0]=1;
		for (int i=0; i<=n; i++)
		{
			for (int j=0; i+j+1<=n; j++)
			{
				for (int a=0; a<=k; a++)
				{
					if (!dp[h-1][i][a])
						continue;
					for (int b=0; a+b<=k; b++)
					{
						if (!dp[h-1][j][b])
							continue;
						//~ if (h==3 && i+j+1==4 && a+b==2)
							//~ debug() << h << " " << i << " " << j << " " << a << " " << b << "  " << dp[h-1][i][a] << " " << dp[h-1][j][b] << " " << kom[i+j][i];
						dod(dp[h][i+j+1][a+b], dp[h-1][i][a]*dp[h-1][j][b]%mod*kom[i+j][i]);
					}
				}
			}
		}
	}
	printf("%lld\n", dp[m][n][k]);
	return 0;
}