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
const int nax=300*1007;
const int vax=20;

int n;

char wcz[vax][vax];
int mac[vax][vax];

vi graf[nax];

vll dp[nax][vax];

ll wyn[nax];

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%s", wcz[i]);
		for (int j=0; j<n; j++)
		{
			if (wcz[i][j]=='1')
			{
				mac[i][j]=1;
				graf[i].push_back(j);
			}
		}
	}
	for (int i=1; i<(1<<n); i++)
	{
		int p=__builtin_popcount(i);
		for (int j=0; j<n; j++)
			if (i&(1<<j))
				dp[i][j].resize(1<<(p-1));
	}
	for (int i=0; i<n; i++)
		dp[1<<i][i][0]=1;
	for (int i=1; i<(1<<n); i++)
	{
		int p=__builtin_popcount(i)-1;
		for (int j=0; j<n; j++)
		{
			if (i&(1<<j))
			{
				for (int l=0; l<n; l++)
				{
					if (!(i&(1<<l)))
					{
						for (int k=0; k<(int)dp[i][j].size(); k++)
						{
							dp[i|(1<<l)][l][k+(mac[j][l]<<p)]+=dp[i][j][k];
						}
					}
				}
			}
			//~ debug() << i << " " << j << " " << dp[i][j];
		}
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<(1<<(n-1)); j++)
			wyn[j]+=dp[(1<<n)-1][i][j];
	
	for (int i=0; i<(1<<(n-1)); i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	return 0;
}