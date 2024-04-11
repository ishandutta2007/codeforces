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
using bn=bitset<nax>;
const ll inf=1e18;

int n, k;

pair<pll,int> tab[nax];

vi best;
ll bestwar;

ll dp[nax][nax];
bn jak[nax][nax];

void test()
{
	scanf("%d%d", &n, &k);
	bestwar=-inf;
	for (int i=1; i<=n; i++)
	{
		pll x;
		scanf("%lld%lld", &x.second, &x.first);
		tab[i]={x, i};
	}
	sort(tab+1, tab+1+n);
	for (int kon=1; kon<=n; kon++)
	{
		swap(tab[kon], tab[n]);
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				dp[i][j]=-inf;
		dp[0][0]=0;
		for (int i=1; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if (dp[i-1][j]+(k-1)*tab[i].first.first>dp[i][j])
				{
					dp[i][j]=dp[i-1][j]+(k-1)*tab[i].first.first;
					jak[i][j]=jak[i-1][j];
				}
				if (dp[i-1][j]+j*tab[i].first.first+tab[i].first.second>dp[i][j+1])
				{
					dp[i][j+1]=dp[i-1][j]+j*tab[i].first.first+tab[i].first.second;
					jak[i][j+1]=jak[i-1][j];
					jak[i][j+1][i]=1;
				}
			}
		}
		ll bedzie=dp[n-1][k-1]+tab[n].first.second+(k-1)*tab[n].first.first;
		if (bedzie>bestwar)
		{
			bestwar=bedzie;
			best.clear();
			bn wez=jak[n-1][k-1];
			for (int i=1; i<n; i++)
			{
				if (wez[i])
					best.push_back(tab[i].second);
			}
			for (int i=1; i<n; i++)
			{
				if (!wez[i])
				{
					best.push_back(tab[i].second);
					best.push_back(-tab[i].second);
				}
			}
			best.push_back(tab[n].second);
		}
		
		
		swap(tab[kon], tab[n]);
	}
	printf("%d\n", 2*n-k);
	for (int i : best)
		printf("%d ", i);
	printf("\n");
	debug() << imie(bestwar);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}