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
ll mod;

int n, m;

ll kom[nax][nax];

ll roz1[nax];
ll sum1[nax];

ll roz2[nax][nax];
ll sum2[nax][nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%d%lld", &n, &m, &mod);
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j-1]+kom[i-1][j])%mod;
	}
	sum1[0]=0;
	roz1[0]=1;
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<=i; j++)
		{
			ll wcze_roz=kom[i-1][j-1]*roz1[j-1]%mod*roz1[i-j]%mod;
			ll wcze_sum=kom[i-1][j-1]*((roz1[j-1]*sum1[i-j]+sum1[j-1]*roz1[i-j])%mod)%mod;
			for (int l=1; l<=j; l++)
			{
				dod(roz1[i], wcze_roz);
				dod(sum1[i], wcze_sum+wcze_roz*abs(j-l));
			}
			for (int l=j; l<=i; l++)
			{
				dod(roz1[i], wcze_roz);
				dod(sum1[i], wcze_sum+wcze_roz*abs(j-l));
			}
		}
	}
	//~ debug() << range(sum1, sum1+1+m);
	//~ debug() << range(roz1, roz1+1+m);
	roz2[0][0]=1;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			if (!roz2[i][j] && !sum2[i][j])
				continue;
			for (int l=0; i+l+1<=n+1 && j+l<=m; l++)
			{
				int cel=i+l+1;
				dod(roz2[cel][j+l], (roz2[i][j]*roz1[l])%mod*kom[j+l][l]);
				dod(sum2[cel][j+l], (roz2[i][j]*sum1[l]+sum2[i][j]*roz1[l])%mod*kom[j+l][l]);
			}
		}
	}
	//~ for (int i=0; i<=n+1; i++)
		//~ debug() << i << " " << range(roz2[i], roz2[i]+1+m) << " " << range(sum2[i], sum2[i]+1+m);
	printf("%lld\n", sum2[n+1][m]);
	return 0;
}