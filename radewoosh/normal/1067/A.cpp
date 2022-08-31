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
const ll mod=998244353;
const int d=200;

int n;

ll dps[nax][2];
ll dpn[nax][2];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

inline int mog(int v, int i)
{
	if (v==i)
		return 1;
	if (v==-1)
		return i>0;
	return 0;
}

void upd(int v)
{
	for (int i=0; i<=d; i++)
	{
		for (int j=0; j<2; j++)
		{
			dps[i][j]=dpn[i][j];
			dpn[i][j]=0;
		}
	}
	ll s=0;
	for (int i=0; i<=d; i++)
	{
		if (mog(v, i))
			dod(dpn[i][0], s);
		dod(s, dps[i][0]+dps[i][1]);
	}
	s=0;
	for (int i=d; i>=0; i--)
	{
		if (mog(v, i))
			dod(dpn[i][1], s);
		dod(s, dps[i][1]);
	}
	for (int i=0; i<=d; i++)
	{
		if (mog(v, i))
			dod(dpn[i][1], dps[i][0]+dps[i][1]);
	}
}

int main()
{
	scanf("%d", &n);
	dpn[0][1]=1;
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		upd(x);
	}
	upd(0);
	printf("%lld\n", dpn[0][1]);
	return 0;
}