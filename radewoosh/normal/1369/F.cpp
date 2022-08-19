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

int n;

ll sta[nax];
ll kon[nax];

int dp[nax];

int daj(ll odko, ll co, int tryb, int start)
{
	if (!tryb)
		return start;
	return (co^odko^start)&1;
}

int rozw(ll odko, ll co, int tryb, int start)//0 to stale, 1 to na zmiane
{
	if (co>=odko)
		return daj(odko, co, tryb, start);
	ll noodko=(odko+1)/2;
	if (noodko+1==odko)
	{
		int tam=(!daj(odko, noodko+1, tryb, start) || !daj(odko, noodko*2, tryb, start));
		return rozw(noodko, co, 0, tam);
	}
	int ost=(!daj(odko, (odko-1)+1, tryb, start) || !daj(odko, (odko-1)*2, tryb, start));
	int pre=(!ost || !daj(odko, (odko-2)*2, tryb, start));
	if (ost==pre)
		return rozw(noodko, co, 0, ost);
	int zmie=((odko-1-noodko)^ost)&1;
	return rozw(noodko, co, 1, zmie);
}

void solve()
{
	for (int i=n; i; i--)
	{
		if (!dp[i+1])//chce wygrac
		{
			dp[i]=rozw(kon[i]+1, sta[i], 0, 1);
		}
		else//chce przegrac
		{
			dp[i]=rozw(kon[i]+1, sta[i], 0, 0);
		}
	}
}

//~ int pom[nax];

int main()
{
	//~ const int m=60;
	//~ for (int i=m; i; i--)
	//~ {
		//~ if (!pom[i+1] || !pom[2*i])
			//~ pom[i]=1;
	//~ }
	//~ for (int i=1; i<=m; i++)
		//~ debug() << i << " " << (m)/i << " " << pom[i];
	//~ return 0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &sta[i], &kon[i]);
	for (int h=0; h<=1; h++)
	{
		memset(dp, sizeof(dp), 0);
		dp[n+1]=h;
		solve();
		printf("%d%c", dp[1], " \n"[h]);
	}
	return 0;
}