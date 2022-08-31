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
const int nax=2007;
const ll mod=998244353;

int n, k;

int dol[nax];
int gor[nax];

int czas;
ll dp[2][nax][nax];
int ost[2][nax][nax];

ll dajs(int a, int b)
{
	if (ost[(czas&1)^1][a][b]!=czas-1)
		return 0;
	return dp[(czas&1)^1][a][b];
}

ll &dajn(int a, int b)
{
	if (ost[czas&1][a][b]!=czas)
	{
		ost[czas&1][a][b]=czas;
		dp[czas&1][a][b]=0;
	}
	return dp[czas&1][a][b];
}

void ans(ll v)
{
	v%=mod;
	v+=mod;
	v%=mod;
	printf("%lld\n", v);
	exit(0);
}

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void dod2(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		dol[i]=max(x-k, 0);
		gor[i]=min(x+k, i);
	}
	for (int i=2; i<=n; i++)
		dol[i]=max(dol[i], dol[i-1]);
	for (int i=n-1; i; i--)
		gor[i]=min(gor[i], gor[i+1]);
	for (int i=1; i<=n; i++)
		if (dol[i]>gor[i])
			ans(0);
	czas=2;
	dajn(0, 0)=1;
	for (int i=1; i<=n; i++)
	{
		czas++;
		for (int j=dol[i-1]; j<=gor[i]; j++)
		{
			for (int l=0; l<=i-j+2; l++)
			{
				dp[czas&1][j][l]=0;
				ost[czas&1][j][l]=czas;
			}
		}
		for (int j=dol[i-1]; j<=gor[i-1]; j++)
		{
			for (int l=0; l<i-j+2; l++)
			{
				ll x=dp[(czas&1)^1][j][l];
				if (!x)
					continue;
				dod2(dp[czas&1][j+1][l], x);
			}
		}
		for (int j=dol[i-1]+1; j<gor[i]; j++)
		{
			for (int l=1; l<=i-j+2; l++)
			{
				ll x=dp[czas&1][j][l];
				if (!x)
					continue;
				dod(dp[czas&1][j+1][l-1], x*l);
			}
		}
		for (int j=dol[i-1]; j<=gor[i-1]; j++)
		{
			if (j>=dol[i] && j<=gor[i])
			{
				for (int l=0; l<i-j+2; l++)
				{
					ll x=dp[(czas&1)^1][j][l];
					if (!x)
						continue;
					dod(dp[czas&1][j][l], x*(j+l));
					dod2(dp[czas&1][j][l+1], x);
				}
			}
		}
	}
	ll wyn=0;
	for (int i=dol[n]; i<=gor[n]; i++)
	{
		ll mno=1;
		int jesz=n-i;
		for (int j=0; j<=n; j++)
		{
			dod(wyn, dajn(i, j)*mno);
			mno=(mno*jesz)%mod;
			jesz--;
		}
	}
	ans(wyn);
	return 0;
}