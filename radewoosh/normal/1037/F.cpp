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
const int nax=2100*1007;
const int n1=(1<<20);
const ll mod=1000*1000*1000+7;

int n;
ll k;

ll mie[nax];
ll spam[nax];

pll drz[nax];

ll wyn;

pll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>grab || b<graa)
		return {-1e9, 0};
	if (a>=graa && b<=grab)
		return drz[v];
	return max(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

void rek(int l, int r)
{
	if (l>r)
		return;
	auto w=czyt(1, 1, n1, l, r);
	int m=w.second;
	rek(l, m-1);
	rek(m+1, r);
	ll ra=spam[r-l+1]-spam[m-l]-spam[r-m];
	wyn+=ra*w.first;
	wyn%=mod;
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &drz[n1+i-1].first);
		drz[n1+i-1].second=i;
	}
	for (int i=n1-1; i; i--)
		drz[i]=max(drz[i*2], drz[i*2+1]);
	for (int i=1; i<=n; i++)
	{
		mie[i]=mie[i-1];
		if (i>=(mie[i]+1)*(k-1)+1)
			mie[i]++;
		spam[i]=spam[i-1]+mie[i];
		spam[i]%=mod;
	}
	rek(1, n);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}