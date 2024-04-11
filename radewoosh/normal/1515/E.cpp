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
const int nax=407;
ll mod;

int n;

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll dp[nax][nax];
ll f[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%lld", &n, &mod);
	for (int i=1; i<=n; i++)
	{
		ll wyj=1;
		ll powi=1;
		for (int j=1; j<=i; j++)
		{
			wyj=(wyj*j)%mod;
		}
		for (int j=1; j<i; j++)
			powi=(powi*2)%mod;
		f[i]=(powi*inv(wyj))%mod;
	}
	dp[0][0]=1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (!dp[i][j])
				continue;
			//~ debug() << i << " " << j;
			int s=i+2;
			if (!i)
				s--;
			for (int l=s; l<=n; l++)
			{
				dod(dp[l][j+l-s+1], dp[i][j]*f[l-s+1]);
			}
		}
	}
	ll wyn=0;
	for (int i=0; i<=n; i++)
	{
		ll spo=dp[n][i];
		int dziury=n-i;
		if (!spo)
			continue;
		for (int j=1; j<=i; j++)
			spo=(spo*j)%mod;
		//~ for (int j=1; j<=i-dziury-1; j++)
			//~ spo=(spo*2)%mod;
		dod(wyn, spo);
	}
	
	printf("%lld\n", wyn);
	return 0;
}