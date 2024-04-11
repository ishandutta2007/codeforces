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
const int nax=2007;

int n;

char sta[nax];
char kon[nax];

int pref[nax];
map<char,int> mapa;

int niez;

int dp[nax][nax];

int dod(char c, int x)
{
	if (mapa[c]>0)
		niez--;
	mapa[c]+=x;
	if (mapa[c]>0)
		niez++;
}

void test()
{
	scanf("%d", &n);
	scanf("%s", sta+1);
	scanf("%s", kon+1);
	mapa.clear();
	for (int i=1; i<=n; i++)
	{
		mapa[sta[i]]++;
		mapa[kon[i]]--;
	}
	for (auto i : mapa)
	{
		if (i.second)
		{
			printf("-1\n");
			return;
		}
	}
	mapa.clear();
	int w=0;
	niez=0;
	for (int i=1; i<=n; i++)
	{
		dod(sta[i], 1);
		while(niez)
		{
			w++;
			dod(kon[w], -1);
		}
		pref[i]=w;
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j]=-nax;
	dp[0][0]=0;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i)
				dp[i][j]=max(dp[i][j], dp[i-1][j]);
			if (j)
				dp[i][j]=max(dp[i][j], dp[i][j-1]);
			if (i && j && pref[i]<=j && sta[i]==kon[j])
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
		}
	}
	printf("%d\n", n-dp[n][n]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}