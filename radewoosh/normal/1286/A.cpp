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
const int nax=107;
const int inf=1e9;

int n;

int tab[nax];

int jest[nax];

int musz[nax];

int dp[nax][nax][2];

void mini(int &a, int b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		jest[tab[i]]++;
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j][0]=dp[i][j][1]=inf;
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	for (int i=0; i<=n/2; i++)
	{
		for (int j=0; j<=(n+1)/2; j++)
		{
			int g=i+j;
			if (g==n)
				continue;
			for (int l=0; l<2; l++)
			{
				if (!tab[g+1] || !(tab[g+1]&1))//parz
				{
					mini(dp[i+1][j][0], dp[i][j][l]+(l==1));
				}
				if (!tab[g+1] || (tab[g+1]&1))
				{
					mini(dp[i][j+1][1], dp[i][j][l]+(l==0));
				}
			}
		}
	}
	printf("%d\n", min(dp[n/2][(n+1)/2][0], dp[n/2][(n+1)/2][1]));
	return 0;
}