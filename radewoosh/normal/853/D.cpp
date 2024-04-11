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

const int nax=300*1007;
const int d=50;
const long long inf=1e12;

int n;
long long tab[nax];
long long pre[nax];

long long wyn;

long long dp[nax][d+1];

inline long long sum(long long a, long long b)
{
	return pre[b]-pre[a-1];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		pre[i]=pre[i-1]+tab[i];
	}
	wyn=pre[n];
	
	for (int i=0; i<=n; i++)
		for (int j=0; j<=d; j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for (int i=0; i<n; i++)
	{
		int zm=tab[i+1]/1000;
		for (int j=0; j<=d; j++)
		{
			dp[i+1][min(j+zm, d)]=min(dp[i+1][min(j+zm, d)], dp[i][j]+tab[i+1]);
			int mog=min(j*100LL, tab[i+1]);
			int ile=mog/100;
			dp[i+1][j-ile]=min(dp[i+1][j-ile], dp[i][j]+tab[i+1]-mog);
		}
	}
	for (int i=0; i<=d; i++)
		wyn=min(wyn, dp[n][i]);
	printf("%lld\n", wyn);
	return 0;
}