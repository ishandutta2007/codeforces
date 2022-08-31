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
const ll mod=1000*1000*1000+7;

int n;

ll tab[nax];

ll wyn;

ll drz[nax][2];//0 to z lewej

void pisz(int v, ll w, int p)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		drz[i][p]=(drz[i][p]+w)%mod;
}

ll czyt(int a, int b, int p)
{
	ll ret=0;
	for (int i=b; i; i-=(i&(-i)))
		ret+=drz[i][p];
	for (int i=a-1; i; i-=(i&(-i)))
		ret-=drz[i][p];
	ret%=mod;
	if (ret<0)
		ret+=mod;
	return ret;
}

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
		dod(wyn, tab[i]*i%mod*(n-i+1));
	vector <pll> wek;
	for (int i=1; i<=n; i++)
		wek.push_back({tab[i], i});
	sort(wek.begin(), wek.end());
	debug() << imie(wyn);
	for (pll h : wek)
	{
		int i=h.second;
		ll lew=czyt(1, i-1, 0);
		ll pra=czyt(i+1, n, 1);
		dod(wyn, lew*(n+1-i)%mod*tab[i]+pra*i%mod*tab[i]);
		pisz(i, i, 0);
		pisz(i, n-i+1, 1);
	}
	
	printf("%lld\n", wyn);
	return 0;
}