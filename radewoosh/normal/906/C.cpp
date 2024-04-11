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

const int nax=22;

int n, m;

int zna[nax];

int dp[1<<nax];
int z[1<<nax];
int z2[1<<nax];

vector <int> wyn;

int main()
{
	scanf("%d%d", &n, &m);
	if (m*2==n*(n-1))
	{
		printf("0\n");
		return 0;
	}
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		zna[a]|=(1<<b);
		zna[b]|=(1<<a);
	}
	for (int i=0; i<(1<<n); i++)
		dp[i]=2*nax;
	for (int i=0; i<n; i++)
		dp[1<<i]=0;
	for (int i=0; i<(1<<n); i++)
	{
		if (dp[i]>nax)
			continue;
		for (int j=0; j<n; j++)
		{
			if (!(i&(1<<j)))
				continue;
			int now=(i|zna[j]);
			if (dp[i]+1<dp[now])
			{
				dp[now]=dp[i]+1;
				z[now]=j;
				z2[now]=i;
			}
		}
	}
	printf("%d\n", dp[(1<<n)-1]);
	int v=(1<<n)-1;
	while(dp[v])
	{
		wyn.push_back(z[v]+1);
		v=z2[v];
	}
	reverse(wyn.begin(), wyn.end());
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}