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
const int inf=1;

int n;

int a[nax];
int b[nax];

short int dp[nax][nax][nax*nax];

short int wyn[nax];

void maxi(short int &a, int b)
{
	a=max((int)a, b);
}

int main()
{
	scanf("%d", &n);
	int s=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		s+=a[i];
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int l=0; l<=s; l++)
				dp[i][j][l]=-inf;
	dp[0][0][0]=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=i; j++)
		{
			for (int l=0; l<=s; l++)
			{
				if (dp[i][j][l]<0)
					continue;
				maxi(dp[i+1][j][l], dp[i][j][l]+b[i+1]);
				maxi(dp[i+1][j+1][l+a[i+1]], dp[i][j][l]+b[i+1]*2);
			}
		}
	}
	//~ for (int i=0; i<=n; i++)
	//~ {
		//~ for (int j=0; j<=i; j++)
		//~ {
			//~ for (int l=0; l<=s; l++)
			//~ {
				//~ if (dp[i][j][l]<0)
					//~ continue;
				//~ debug() << i << " " << j << " " << l << " " << dp[i][j][l];
			//~ }
		//~ }
	//~ }
	for (int i=1; i<=n; i++)
		for (int j=0; j<=s; j++)
			maxi(wyn[i], min((int)dp[n][i][j], 2*j));
	
	for (int i=1; i<=n; i++)
		printf("%.11lf ", (double)(wyn[i]/2.0));
	printf("\n");
	return 0;
}