//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int nax=57;

int n;

char wcz[nax];

int sum[nax][nax];

int dp[nax][nax][nax][nax];

int licz(int a, int b, int x, int y)
{
	a--;
	b--;
	return sum[x][y]-sum[a][y]-sum[x][b]+sum[a][b];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=n; j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(wcz[j]=='#');
	}
	//~ debug() << imie(licz(1, n, 1, n));
	for (int j=1; j<=n; j++)
	{
		for (int i=j; i; i--)
		{
			for (int b=1; b<=n; b++)
			{
				for (int a=b; a; a--)
				{
					if (!licz(i, a, j, b))
						continue;
					dp[i][a][j][b]=max(b-a+1, j-i+1);
					if (b-a>j-i)
					{
						for (int x=a; x<b; x++)
						{
							dp[i][a][j][b]=min(dp[i][a][j][b], dp[i][a][j][x]+dp[i][x+1][j][b]);
						}
					}
					else
					{
						for (int x=i; x<j; x++)
						{
							dp[i][a][j][b]=min(dp[i][a][j][b], dp[i][a][x][b]+dp[x+1][a][j][b]);
						}
					}
					//~ debug() << i << " " << a << " " << j << " " << b << "  " << dp[i][a][j][b];
				}
			}
		}
	}
	printf("%d\n", dp[1][1][n][n]);
	return 0;
}