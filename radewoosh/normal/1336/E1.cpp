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

void ff()
{
	fflush(stdout);
}

int n, m;

ll tab[nax];

ll mac[nax];

ll domno=1;

int zal[nax];
int niezal[nax];

void dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

void dorzuc(ll v)
{
	for (int i=0; i<m; i++)
	{
		if (v&(1LL<<i))
			v^=mac[i];
	}
	if (!v)
	{
		domno=(domno*2)%mod;
		return;
	}
	int x=0;
	while((1LL<<x)*2<=v)
		x++;
	mac[x]=v;
	//~ debug() << v << " " << x;
	for (int i=0; i<m; i++)
		if (i!=x && (mac[i]&(1LL<<x)))
			mac[i]^=v;
}

ll wyn[nax];

ll dp[107][1007];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		dorzuc(tab[i]);
	}
	int ile=0;
	for (int i=0; i<m; i++)
	{
		if (mac[i])
		{
			zal[i]=1;
			ile++;
		}
		else
		{
			niezal[i]=1;
		}
	}
	if (ile<=28)
	{
		vll wek;
		for (int i=0; i<m; i++)
			if (zal[i])
				wek.push_back(mac[i]);
		int r1=ile/2;
		int r2=ile-r1;
		vll pa, pb;
		for (int i=0; i<(1<<r1); i++)
		{
			ll x=0;
			for (int j=0; j<r1; j++)
				if (i&(1<<j))
					x^=wek[j];
			pa.push_back(x);
		}
		for (int i=0; i<(1<<r2); i++)
		{
			ll x=0;
			for (int j=0; j<r2; j++)
				if (i&(1<<j))
					x^=wek[r1+j];
			pb.push_back(x);
		}
		for (const ll &i : pa)
			for (const ll &j : pb)
				wyn[__builtin_popcountll(i^j)]++;
		for (int i=0; i<=m; i++)
			printf("%lld ", (wyn[i]*domno)%mod);
		printf("\n");
		return 0;
	}
	vll wek;
	int r=0;
	for (int i=0; i<m; i++)
		r+=niezal[i];
	for (int i=0; i<m; i++)
	{
		if (niezal[i])
			continue;
		int li=-1;
		ll x=0;
		for (int j=0; j<m; j++)
		{
			if (zal[j])
				continue;
			li++;
			if (mac[i]&(1LL<<j))
				x^=(1LL<<li);
		}
		wek.push_back(x);
	}
	dp[0][0]=1;
	for (int i=0; i<(int)wek.size(); i++)
	{
		for (int j=i; j>=0; j--)
		{
			for (int l=0; l<(1<<r); l++)
				dod(dp[j+1][l^wek[i]], dp[j][l]);
		}
	}
	for (int i=0; i<=(int)wek.size(); i++)
		for (int j=0; j<(1<<r); j++)
			dod(wyn[i+__builtin_popcount(j)], dp[i][j]);
	
	for (int i=0; i<=m; i++)
		printf("%lld ", (wyn[i]*domno)%mod);
	printf("\n");
	return 0;
}