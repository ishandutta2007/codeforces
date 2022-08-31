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
const ll inf=1e18;

int n;

int wys[nax];
int gdz[nax];
ll faj[nax];

int nap[nax];
int nal[nax];
int zl[nax];
int zp[nax];

vll dp[nax];//calosc, miej lew, miej pra, miej oba

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &wys[i]);
		gdz[wys[i]]=i;
	}
	for (int i=1; i<=n; i++)
		scanf("%lld", &faj[i]);
	for (int i=1; i<=n; i++)
	{
		nap[i]=nal[i]=zp[i]=zl[i]=i;
	}
	for (int i=n; i; i--)
	{
		int v=gdz[i];
		vll lew, pra;
		
		if (wys[nal[v-1]]>i)
		{
			lew=dp[nal[v-1]];
			zl[v]=zl[nal[v-1]];
		}
		else
		{
			lew.resize(4);
		}
		
		if (wys[nap[v+1]]>i)
		{
			pra=dp[nap[v+1]];
			zp[v]=zp[nap[v+1]];
		}
		else
		{
			pra.resize(4);
		}
		
		nap[zl[v]]=v;
		nal[zp[v]]=v;
		
		dp[v].resize(4, -inf);
		ll tu=faj[v];
		
		//~ maxi(dp[v][0], tu);
		//~ maxi(dp[v][0], tu+pra[0]);
		//~ maxi(dp[v][0], tu+pra[1]);
		
		for (ll a : {0LL, pra[0], pra[1]})
			for (ll b : {0LL, lew[0], lew[2]})
				maxi(dp[v][0], tu+a+b);
		for (ll a : {0LL, pra[0], pra[1]})
			for (ll b : {0LL, lew[0], lew[2], lew[3], lew[1]})
				maxi(dp[v][1], tu+a+b);
		for (ll a : {0LL, pra[0], pra[1], pra[2], pra[3]})
			for (ll b : {0LL, lew[0], lew[2]})
				maxi(dp[v][2], tu+a+b);
		for (ll a : {0LL, pra[0], pra[1], pra[2], pra[3]})
			for (ll b : {0LL, lew[0], lew[2], lew[1], lew[3]})
				maxi(dp[v][3], tu+a+b);
		
		for (ll x : {0LL, pra[0], pra[1]})
			maxi(dp[v][1], x);
		for (ll x : {0LL, lew[0], lew[2]})
			maxi(dp[v][2], x);
		for (ll x : {0LL, lew[0], lew[1], lew[2], lew[3], pra[0], pra[1], pra[2], pra[3]})
			maxi(dp[v][3], x);
		
		maxi(dp[v][1], dp[v][0]);
		maxi(dp[v][2], dp[v][0]);
		maxi(dp[v][3], dp[v][1]);
		maxi(dp[v][3], dp[v][2]);
	}
	printf("%lld\n", dp[gdz[1]][0]);
	return 0;
}