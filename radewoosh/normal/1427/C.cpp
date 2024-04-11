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
const int nax=1000*1007;
const int vax=507;

int r, n;

int czas[nax];
pii gdz[nax];

int dp[vax][vax];

int dpon[nax];

void maxi(int &a, int b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d%d", &r, &n);
	for (int i=1; i<=n; i++)
		scanf("%d%d%d", &czas[i], &gdz[i].first, &gdz[i].second);
	gdz[0]={1, 1};
	for (int i=1; i<=n; i++)
	{
		dpon[i]=-nax;
	}
	for (int i=1; i<=r; i++)
		for (int j=1; j<=r; j++)
			dp[i][j]=-nax;
	int w=0;
	int wyn=0;
	dp[1][1]=0;
	for (int h=1; h<=czas[n]; h++)
	{
		for (int i=w; i>=0 && czas[i]>=h-r; i--)
		{
			int roz=h-czas[i];
			if (gdz[i].first-roz>=1)
				maxi(dp[gdz[i].first-roz][gdz[i].second], dpon[i]);
			if (gdz[i].first+roz<=r)
				maxi(dp[gdz[i].first+roz][gdz[i].second], dpon[i]);
		}
		if (w<n && czas[w+1]==h)
		{
			w++;
			maxi(dpon[w], dp[gdz[w].first][gdz[w].second]+1);
			maxi(dp[gdz[w].first][gdz[w].second], dpon[w]);
		}
		for (int i=w+1; i<=n && czas[i]<=h+r; i++)
		{
			if (i<0 || czas[i]<h)
				continue;
			int roz=czas[i]-h;
			if (gdz[i].second-roz>=1)
				maxi(dpon[i], dp[gdz[i].first][gdz[i].second-roz]+1);
			if (gdz[i].second+roz<=r)
				maxi(dpon[i], dp[gdz[i].first][gdz[i].second+roz]+1);
		}
	}
	//~ debug() << range(dpon+1, dpon+1+n);
	for (int i=1; i<=n; i++)
		maxi(wyn, dpon[i]);
	printf("%d\n", wyn);
	return 0;
}