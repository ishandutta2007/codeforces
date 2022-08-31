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

const int nax=2007;
using ll=long long;
const ll mod=998244353;
const ll modo=(mod+1)/2;

int n;

int a, b;
ll p, p1;

ll stro[nax];
ll pot2[nax*nax];
//~ ll odw[nax*nax];
ll kom[nax][nax];

ll wyla[nax][nax];

ll dp[nax];

ll ppot[nax];
ll p1pot[nax];

ll dp2[nax];

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

inline int kra(ll v)
{
	return (v*(v-1))/2;
}

inline void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	p=dziel(a, b);
	p1=(1-p+mod)%mod;
	debug() << imie(p) << " " << imie(p1);
	pot2[0]=ppot[0]=p1pot[0]=1;
	for (int i=1; i<=n*n; i++)
	{
		pot2[i]=(pot2[i-1]*2)%mod;
		//~ odw[i]=(odw[i-1]*modo)%mod;
	}
	for (int i=1; i<=n; i++)
	{
		ppot[i]=(ppot[i-1]*p)%mod;
		p1pot[i]=(p1pot[i-1]*p1)%mod;
	}
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	
	wyla[0][0]=1;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=i; j++)
		{
			dod(wyla[i+1][j], ((wyla[i][j]*ppot[j])%mod));
			dod(wyla[i+1][j+1], ((wyla[i][j]*p1pot[i-j])%mod));
			debug() << "wyla " << i << " " << j << " " << wyla[i][j];
			//~ wyla[i][j]=(wyla[i][j]*odw[kra(i)])%mod;
			debug() << "wyla " << i << " " << j << " " << wyla[i][j];
		}
		debug();
	}
	
	stro[1]=1;
	for (int i=2; i<=n; i++)
	{
		stro[i]=1;
		for (int j=1; j<i; j++)
			dod(stro[i], -((stro[j]*wyla[i][j])%mod));
		
		stro[i]%=mod;
		stro[i]+=mod;
		stro[i]%=mod;
		
		debug() << "Stro " << i << " " << stro[i];
	}
	
	for (int i=2; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			ll x=(stro[j]*wyla[i][j])%mod;
			dod(dp2[i], x*(dp[j]+dp2[i-j]));
			debug() << "x " << i << " " << j << " " << x;
		}
		dod(dp[i], dp2[i]+kra(i));
		//~ dod(dp[i], kra(i));
		debug() << "dp " << i << " " << dp[i] << " " << (mod+1-stro[i]);
		dp[i]=dziel(dp[i], (mod+1-stro[i]));
		debug() << "dp " << i << " " << dp[i];
		dod(dp2[i], dp[i]*stro[i]);
	}
	
	printf("%lld\n", dp[n]);
	return 0;
}