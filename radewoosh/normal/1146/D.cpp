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
const ll inf=1e18;

ll n;
ll a, b;

ll wyn;

ll suf(ll x, ll y)
{
	return (x+y-1)/y;
}

void ogarnij(ll pocz, ll kon, ll gdz)
{
	if (gdz>n)
		return;
	//~ debug() << pocz << " " << kon << " " << gdz;
	ll dod=suf(gdz-pocz, a);
	wyn+=dod*(n-gdz+1);
	pocz+=dod*a;
	if (pocz>n)
		return;
	ll miej=n-pocz;
	//~ debug() << pocz << " " << gdz << "  " << wyn << "  " << miej;
	ll bedz=miej/a;
	wyn+=(bedz+1)*(miej+1);
	wyn-=a*(bedz*(bedz+1)/2);
}

int main()
{
	scanf("%lld%lld%lld", &n, &a, &b);
	ll v=0;
	ll naj=0;
	map <ll,ll> mapa;
	for (int i=0; i<a; i++)
		mapa[i]=inf;
	for (int h=0; !h || v; h++)
	{
		if (v<mapa[v%a])
		{
			ogarnij(v, mapa[v%a], naj);
			mapa[v%a]=v;
		}
		if (v>=b)
			v-=b;
		else
			v+=a;
		naj=max(naj, v);
	}
	
	
	
	
	printf("%lld\n", wyn);
	return 0;
}