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
const ll mod=998244353;

int n;

ll pra[nax];

ll wyn[nax];

ll sil[nax];
ll osil[nax];

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

ll inv(ll v)
{
	return pot(v, mod-2);
}

ll kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return sil[a]*osil[b]%mod*osil[a-b]%mod;
}

int main()
{
	scanf("%d", &n);
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=sil[i-1]*i%mod;
	osil[n]=inv(sil[n]);
	for (int i=n; i; i--)
		osil[i-1]=osil[i]*i%mod;
	pra[1]=1;
	for (int i=2; i<=(n+1)/2; i++)
	{
		pra[i]=kom(n-(n+1)/2, i-1)*inv(kom(n-1, i-1))%mod;
		//~ debug() << i << " " << kom(n-(n+1)/2, i-1) << " " << (kom(n-1, i-1));
	}
	
	//~ debug() << range(pra+1, pra+1+n);
	ll zle=0;
	for (int i=n; i; i--)
	{
		//~ debug() << i << " " << zle;
		wyn[i]=(pra[i]-zle)%mod;
		wyn[i]%=mod;
		wyn[i]+=mod;
		wyn[i]%=mod;
		zle=(zle+pra[i]*inv(i-1))%mod;
	}
	
	for (int i=1; i<=n; i++)
		printf("%lld ", wyn[i]*sil[n-1]%mod);
	printf("\n");
	return 0;
}