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

int n, h, m;

int juz[nax][nax][nax];
int dp[nax][nax][nax];
int l[nax];
int r[nax];
int x[nax];
int c[nax];

int rek(int a, int b, int w)
{
	if (a>b || !w)
		return 0;
	if (juz[a][b][w])
		return dp[a][b][w];
	dp[a][b][w]=rek(a, b, w-1);
	vi tu;
	vi sum(n+3, 0);
	for (int i=1; i<=m; i++)
	{
		if (l[i]>=a && r[i]<=b && w>x[i])
		{
			sum[l[i]]+=c[i];
			sum[r[i]+1]-=c[i];
		}
	}
	for (int i=a+1; i<=b; i++)
		sum[i]+=sum[i-1];
	for (int i=a; i<=b; i++)
		dp[a][b][w]=max(dp[a][b][w], rek(a, i-1, w)+rek(i+1, b, w)+w*w-sum[i]);
	juz[a][b][w]=1;
	return dp[a][b][w];
}

int main()
{
	scanf("%d%d%d", &n, &h, &m);
	
	for (int i=1; i<=m; i++)
		scanf("%d%d%d%d", &l[i], &r[i], &x[i], &c[i]);
	printf("%d\n", rek(1, n, h));
	
	return 0;
}