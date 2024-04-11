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
const int nax=1007;

void nope()
{
	printf("NO\n");
}

void tak()
{
	printf("YES\n");
}

int n, m;
char sta[nax];
char kon[nax];

int dp[nax];

void maxi(int &a, int b)
{
	a=max(a, b);
}

void test()
{
	scanf("%s", sta+1);
	scanf("%s", kon+1);
	n=strlen(sta+1);
	m=strlen(kon+1);
	for (int h=0; h<=m; h++)
	{
		for (int i=h; i<=m; i++)
			dp[i]=-1;
		dp[h]=0;
		for (int i=1; i<=n; i++)
		{
			for (int j=m; j>=h; j--)
			{
				if (dp[j]==-1)
					continue;
				if (j<m && sta[i]==kon[j+1])
				{
					maxi(dp[j+1], dp[j]);
				}
				if (dp[j]<h && sta[i]==kon[dp[j]+1])
				{
					dp[j]++;
				}
			}
		}
		if (dp[m]==h)
		{
			tak();
			return;
		}
	}
	nope();
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
		test();
	return 0;
}