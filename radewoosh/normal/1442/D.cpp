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

int n, k;

vll wek[nax];
ll sum[nax];

ll wyn;

ll dp[3007][3007];

void doloz(int v, int gdz)
{
	for (int i=0; i<=k; i++)
		dp[gdz+1][i]=dp[gdz][i];
	int r=wek[v].size();
	for (int i=0; i+r<=k; i++)
		dp[gdz+1][i+r]=max(dp[gdz+1][i+r], dp[gdz][i]+sum[v]);
}

void rek(int a, int b, int g)
{
	if (a==b)
	{
		ll suma=0;
		for (int i=0; i<=(int)wek[a].size() && i<=k; i++)
		{
			wyn=max(wyn, suma+dp[g][k-i]);
			if (i<(int)wek[a].size())
				suma+=wek[a][i];
		}
		return;
	}
	int s=(a+b)>>1;
	{
		int p=g;
		for (int i=a; i<=s; i++)
		{
			doloz(i, p);
			p++;
		}
		rek(s+1, b, p);
	}
	{
		int p=g;
		for (int i=s+1; i<=b; i++)
		{
			doloz(i, p);
			p++;
		}
		rek(a, s, p);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			wek[i].push_back(y);
			sum[i]+=y;
		}
	}
	rek(1, n, 0);
	printf("%lld\n", wyn);
	return 0;
}