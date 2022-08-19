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

ll tab[nax];

void ans(int v)
{
	if (v==1)
		printf("WIN\n");
	if (v==0)
		printf("DRAW\n");
	if (v==-1)
		printf("LOSE\n");
}

int dp[nax][2][2][2];
int pam[nax][2][2][2];

int licz(int jed, int zer, int ja, int on)
{
	if (!jed && !zer)
	{
		if (ja>on)
			return 1;
		if (ja==on)
			return 0;
		if (ja<on)
			return -1;
	}
	if (pam[jed][zer][ja][on])
		return dp[jed][zer][ja][on];
	int ret=-1;
	if (jed)
		ret=max(ret, -licz(jed-1, zer, on, ja^1));
	if (zer)
		ret=max(ret, -licz(jed, zer-1, on, ja));
	pam[jed][zer][ja][on]=1;
	return dp[jed][zer][ja][on]=ret;
}

void test()
{
	scanf("%d", &n);
	ll xo=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		xo^=tab[i];
	}
	if (!xo)
	{
		ans(0);
		return;
	}
	ll w=1;
	while(w*2<=xo)
		w*=2;
	int jed=0;
	int zer=0;
	for (int i=1; i<=n; i++)
	{
		if (tab[i]&w)
			jed++;
		else
			zer++;
	}
	ans(licz(jed, zer&1, 0, 0));
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}