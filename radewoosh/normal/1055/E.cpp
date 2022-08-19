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

int n, s, m, k;
int tab[nax];

pii prze[nax];

bool mniej(pii a, pii b)
{
	a.second*=-1;
	b.second*=-1;
	return a<b;
}

int war[nax];

int pyt(int a, int b)
{
	return war[b]-war[a-1];
}

int dp[nax][nax];

void maxi(int &a, int b)
{
	a=max(a, b);
}

int check(int v)
{
	for (int i=1; i<=n; i++)
		war[i]=war[i-1]+(tab[i]<=v);
	for (int i=0; i<=s; i++)
		for (int j=0; j<=m; j++)
			dp[i][j]=0;
	int w=0;
	for (int i=1; i<=s; i++)
	{
		for (int j=0; j<=m; j++)
			maxi(dp[i][j], dp[i-1][j]);
		while(prze[w+1].second<prze[i].first)
			w++;
		for (int j=1; j<=m; j++)
		{
			maxi(dp[i][j], dp[w][j-1]+pyt(prze[i].first, prze[i].second));
			if (w+1<i)
				maxi(dp[i][j], dp[w+1][j-1]+pyt(prze[w+1].second+1, prze[i].second));
		}
	}
	
	for (int i=0; i<=m; i++)
		if (dp[s][i]>=k)
			return 1;
	return 0;
}

int main()
{
	scanf("%d%d%d%d", &n, &s, &m, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<=s; i++)
		scanf("%d%d", &prze[i].first, &prze[i].second);
	vector <pii> trz;
	sort(prze+1, prze+1+s, mniej);
	for (int i=1; i<=s; i++)
		if (trz.empty() || prze[i].second>trz.back().second)
			trz.push_back(prze[i]);
	s=0;
	for (pii i : trz)
	{
		s++;
		prze[s]=i;
	}
	if (!check(1e9+7))
	{
		printf("-1\n");
		return 0;
	}
	int bsa=0;
	int bsb=1e9+7;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%d\n", bsa);
	return 0;
}