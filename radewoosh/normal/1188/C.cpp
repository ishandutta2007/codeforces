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
const int nax=1007;
const ll mod=998244353;

void dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

int n, k;

int tab[nax];

ll dp[nax][nax];

ll wyn;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	sort(tab+1, tab+1+n);
	for (int h=1; h*(k-1)<=tab[n]; h++)
	{
		for (int i=0; i<=k; i++)
			for (int j=0; j<=n; j++)
				dp[i][j]=0;
		for (int i=1; i<=n; i++)
			dp[1][i]=1;
		for (int i=1; i<k; i++)
		{
			ll s=0;
			int w=0;
			for (int j=1; j<=n; j++)
			{
				while(w+1<j && tab[j]-tab[w+1]>=h)
				{
					w++;
					dod(s, dp[i][w]);
				}
				dp[i+1][j]=s;
			}
		}
		for (int i=1; i<=n; i++)
			dod(wyn, dp[k][i]);
	}
	printf("%lld\n", wyn);
	return 0;
}