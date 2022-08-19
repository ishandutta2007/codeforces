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
const int nax=1007*1007;
const ll mod=998244353;

int n;
char wcz[nax];

ll sil[nax];
ll odw[nax];

ll wyn;

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

void fix(ll &v)
{
	v%=mod;
	if (v<0)
		v+=mod;
}

ll kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return (sil[a]*(odw[b]*odw[a-b]%mod))%mod;
}

ll nor[nax];
ll pojeb[nax];

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	sil[0]=odw[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=dziel(1, sil[n]);
	for (int i=n-1; i; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	
	int zaw=0;
	for (int i=1; i<=n; i++)
		zaw+=(wcz[i]=='?');
	
	for (int i=0; i<=zaw; i++)
		nor[i+1]=(nor[i]+kom(zaw, i))%mod;
	
	if (zaw)
	{
		for (int i=0; i<=zaw-1; i++)
			pojeb[i+1]=(pojeb[i]+kom(zaw-1, i))%mod;
	}
	
	int otw=0;
	int zam=0;
	int puslew=0;
	int puspra=0;
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]==')')
			zam++;
		if (wcz[i]=='?')
			puspra++;
	}
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]==')')
		{
			zam--;
			continue;
		}
		if (wcz[i]=='(')
		{
			otw++;
		}
		if (wcz[i]=='?')
		{
			puspra--;
			otw++;
		}
		//~ debug() << i << "  " << otw << " " << zam << "  " << puslew << " " << puspra;
		//~ for (int j=0; j<=puslew+puspra; j++)
		//~ {
			//~ if (j<=-otw+zam+puspra)
				//~ wyn+=kom(puslew+puspra, j);
			//~ wyn%=mod;
		//~ }
		
		if (puslew+puspra==zaw)
		{
			int lim=-otw+zam+puspra;
			lim=max(lim, -1);
			lim=min(lim, zaw);
			//~ debug() << imie(lim);
			wyn=(wyn+nor[lim+1])%mod;
		}
		else
		{
			int lim=-otw+zam+puspra;
			lim=max(lim, -1);
			lim=min(lim, zaw-1);
			//~ debug() << imie(lim);
			wyn=(wyn+pojeb[lim+1])%mod;
		}
		
		if (wcz[i]=='(')
		{
		}
		if (wcz[i]=='?')
		{
			puslew++;
			otw--;
		}
	}
	
	
	printf("%lld\n", wyn);
	return 0;
}