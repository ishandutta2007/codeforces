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
const int nax=1000*1007;
const int vax=3007;
const ll mod=998244353;

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

int n, m;

int lubi[nax];
ll wag[nax];

ll sum;
ll sud;
ll suj;

ll dpog[vax][vax];

ll dpd[vax][vax];
//~ ll dpz[vax][vax];

ll srd[vax];
//~ ll srz[vax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
	if (a<0)
		a+=mod;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &lubi[i]);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &wag[i]);
		sum+=wag[i];
		if (!lubi[i])
			suj+=wag[i];
		else
			sud+=wag[i];
	}
	dpog[0][0]=1;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<=i; j++)
		{
			ll dob=sud+j;
			ll zle=suj-(i-j);
			if (!zle)
			{
				dod(dpog[i+1][j+1], dpog[i][j]);
				continue;
			}
			ll x=dziel(1, dob+zle);
			dod(dpog[i+1][j+1], dpog[i][j]*dob%mod*x);
			dod(dpog[i+1][j], dpog[i][j]*zle%mod*x);
		}
	}
	
	dpd[0][0]=1;
	for (int i=0; i<m; i++)
	{
		ll wsz=sud+i;
		ll x=dziel(1, wsz);
		for (int j=0; j<=i; j++)
		{
			ll ja=1+j;
			dod(dpd[i+1][j+1], dpd[i][j]*ja%mod*x);
			dod(dpd[i+1][j], dpd[i][j]*(wsz-ja)%mod*x);
		}
	}
	for (int i=0; i<=m; i++)
		for (int j=0; j<=i; j++)
			dod(srd[i], dpd[i][j]*j);
	
	debug() << range(dpog[m], dpog[m]+1+m);
	
	ll supd=0;
	for (int i=0; i<=m; i++)
		dod(supd, srd[i]*dpog[m][i]);
		
	ll utra=0;
	for (int i=0; i<=m; i++)
		if (i<=suj)
			dod(utra, dziel(i, suj)*dpog[m][m-i]);
	
	for (int i=1; i<=n; i++)
	{
		if (lubi[i])
		{
			ll x=wag[i]+wag[i]*supd;
			
			x%=mod;
			if (x<0)
				x+=mod;
			printf("%lld\n", x);
		}
		else
		{
			ll x=wag[i]-wag[i]*utra;
			
			
			x%=mod;
			if (x<0)
				x+=mod;
			printf("%lld\n", x);
		}
	}
	
	return 0;
}