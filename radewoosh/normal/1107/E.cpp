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
const ll inf=1e18;

int n;

char wcz[nax];

ll tab[nax];

ll opt[nax][nax][nax][2];
ll dp[nax][nax];

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++)
			for (int l=0; l<=n+1; l++)
				for (int h=0; h<2; h++)
					opt[i][j][l][h]=-inf;
	for (int i=1; i<=n; i++)
		opt[i+1][i][0][0]=opt[i+1][i][0][1]=0;
	for (int j=1; j<=n; j++)
	{
		for (int i=j; i; i--)
		{
			int x=wcz[i]-'0';
			for (int l=0; l<=n; l++)
				maxi(opt[i][j][l+1][x], opt[i+1][j][l][x]);
			for (int l=0; l<=n; l++)
				for (int h=0; h<2; h++)
					for (int g=i; g<=j; g++)
						maxi(opt[i][j][l][h], opt[g+1][j][l][h]+dp[i][g]);
			for (int l=0; l<=n; l++)
				for (int h=0; h<2; h++)
					maxi(dp[i][j], opt[i][j][l][h]+tab[l]);
		}
	}
	
	printf("%lld\n", dp[1][n]);
	return 0;
}