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

const int nax=1000*1007;
const long long mod=1000*1000*1000+7;

int n, k;

long long sil[nax];
long long odw[nax];

long long dp[nax];

long long dziel(long long a, long long b)
{
	long long wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

long long kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return (sil[a]*((odw[b]*odw[a-b])%mod))%mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	k++;
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=dziel(1, sil[n]);
	for (int i=n-1; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	dp[1]=1;
	dp[2]=1;
	for (int i=3; i<=n; i++)
	{
		dp[i]=(dp[i-1]*(i-2)+dp[i-1])%mod;
		//debug() << i << " " << dp[i];
		if (i>k)
		{
			//debug() << "uj " << (sil[i-2]*odw[i-k-1])%mod;
			dp[i]-=((dp[i-k]*sil[i-2])%mod)*odw[i-k-1];
			dp[i]%=mod;
			dp[i]+=mod;
			dp[i]%=mod;
		}
	}
	//debug() << range(dp+1, dp+1+n);
	long long wyn=0;
	for (int i=1; i<=n; i++)
		wyn=(wyn+(dp[i]*kom(n-1, i-1)%mod)*sil[n-i])%mod;
	printf("%lld\n", (sil[n]-wyn+mod)%mod);
	return 0;
}