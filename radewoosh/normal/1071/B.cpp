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
const int nax=2007;
const int inf=1e9;

int n, k;

char tab[nax][nax];

int dp[nax][nax];
vector <pii> war[nax*2];

void zbi(int &a, int b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", tab[i]+1);
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dp[i][j]=inf;
	dp[1][1]=0;
	if (k && tab[1][1]!='a')
	{
		k--;
		tab[1][1]='a';
	}
	printf("%c", tab[1][1]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			war[i+j].push_back({i, j});
	for (int i=2; i<2*n; i++)
	{
		char mini='z';
		for (pii j : war[i])
		{
			int a=j.first;
			int b=j.second;
			if (dp[a][b]<=k)
			{
				if (a<n)
					mini=min(mini, tab[a+1][b]);
				if (b<n)
					mini=min(mini, tab[a][b+1]);
			}
			if (dp[a][b]<k)
			{
				mini='a';
			}
		}
		printf("%c", mini);
		for (pii j : war[i])
		{
			int a=j.first;
			int b=j.second;
			if (dp[a][b]<=k)
			{
				if (a<n)
					zbi(dp[a+1][b], dp[a][b]+(tab[a+1][b]!=mini));
				if (b<n)
					zbi(dp[a][b+1], dp[a][b]+(tab[a][b+1]!=mini));
			}
		}
	}
	
	printf("\n");
	return 0;
}