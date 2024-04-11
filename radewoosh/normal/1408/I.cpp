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
const int nax=(1<<16);
const int vax=20;
const ll mod=998244353;
const ll o2=(mod+1)/2;

int n, k, c;
int tab[nax];

ll ruch[vax][nax];

ll inv(ll a)
{
	if (a<=1)
		return a;
	return inv(mod%a)*(mod-mod/a)%mod;
}

ll pom[nax];

ll dp[vax][nax];

ll newt[vax][vax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void cofnij(ll *x)
{
	for (int i=0; i<c; i++)
	{
		for (int j=0; j<(1<<c); j++)
		{
			if (j&(1<<i))
				continue;
			ll a=x[j];
			ll b=x[j^(1<<i)];
			x[j]=(a+b)*o2%mod;
			x[j^(1<<i)]=(a-b+mod)*o2%mod;
		}
	}
}

void zrob(ll *x)
{
	for (int i=0; i<c; i++)
	{
		for (int j=0; j<(1<<c); j++)
		{
			if (j&(1<<i))
				continue;
			ll a=x[j];
			ll b=x[j^(1<<i)];
			x[j]=(a+b)%mod;
			x[j^(1<<i)]=(a-b+mod)%mod;
		}
	}
}

unordered_map<int,ll> mapa[vax];

int zm[nax];

int main()
{
	for (int i=0; i<vax; i++)
	{
		newt[i][0]=1;
		for (int j=1; j<=i; j++)
			newt[i][j]=newt[i-1][j-1]+newt[i-1][j];
	}
	scanf("%d%d%d", &n, &k, &c);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=k; j++)
			zm[j]=tab[i]^(tab[i]-j);
		for (int j=1; j<=k; j++)
		{
			mapa[j].clear();
			mapa[j][zm[j]]++;
			for (int l=1; l<j; l++)
				for (auto w : mapa[l])
					mapa[j][w.first^zm[j-l]]-=w.second*newt[j-1][l-1];
			for (auto w : mapa[j])
				dod(ruch[j][w.first], mod+w.second);
		}
	}
	for (int i=1; i<=k; i++)
		zrob(ruch[i]);
	int xo=0;
	for (int i=1; i<=n; i++)
		xo^=tab[i];
	dp[0][xo]=1;
	zrob(dp[0]);
	
	for (int i=1; i<=k; i++)
		for (int l=1; l<=i; l++)
			for (int j=0; j<(1<<c); j++)
				dod(dp[i][j], ruch[l][j]*dp[i-l][j]%mod*newt[i-1][l-1]);
	cofnij(dp[k]);
	
	ll dodz=1;
	for (int i=1; i<=k; i++)
		dodz=(dodz*n)%mod;
	dodz=inv(dodz);
	
	for (int i=0; i<(1<<c); i++)
		printf("%lld ", (dp[k][i]*dodz)%mod);
	printf("\n");
	return 0;
}