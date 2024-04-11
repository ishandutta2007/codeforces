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

int n;
ll zys;

ll dif[nax];
ll kosz[nax];

ll wyn;

void rek(int a, int b)
{
	if (a==b)
	{
		wyn=max(wyn, zys-kosz[a]);
		return;
	}
	int sr=(a+b)/2;
	rek(a, sr);
	rek(sr+1, b);
	ll s=0;
	ll dziu=0;
	vector <pll> lew, pra;
	for (int i=sr; i>=a; i--)
	{
		dziu=max(dziu, dif[i+1]-dif[i]);
		s+=zys-kosz[i];
		lew.push_back({dziu, s});
	}
	s=0;
	dziu=0;
	for (int i=sr+1; i<=b; i++)
	{
		dziu=max(dziu, dif[i]-dif[i-1]);
		s+=zys-kosz[i];
		pra.push_back({dziu, s});
	}
	vector < pair <ll,pll> > wek;
	for (pll i : lew)
		wek.push_back({i.first, {i.second, 0}});
	for (pll i : pra)
		wek.push_back({i.first, {i.second, 1}});
	sort(wek.begin(), wek.end());
	ll naj[]={-inf, -inf};
	for (auto i : wek)
	{
		naj[i.second.second]=max(naj[i.second.second], i.second.first);
		wyn=max(wyn, naj[0]+naj[1]-i.first*i.first);
	}
}

int main()
{
	scanf("%d%lld", &n, &zys);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &dif[i], &kosz[i]);
	rek(1, n);
	printf("%lld\n", wyn);
	return 0;
}