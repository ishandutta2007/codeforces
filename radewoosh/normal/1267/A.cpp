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
const ll inf=2e18;

int n;

ll a[nax];
ll b[nax];
ll t[nax];

vector <pll> wek;

ll wyn;

multiset <ll> setel;

void wrzu(ll v)
{
	setel.insert(v);
}

void usun(ll v)
{
	setel.erase(setel.find(v));
}

ll mini()
{
	auto it=setel.begin();
	return (*it);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);
		wek.push_back({a[i], -i});
		wek.push_back({b[i]-t[i], i});
	}
	sort(wek.begin(), wek.end());
	//~ ll ost=-inf;
	//~ ll teraz=-inf;
	ll najb=inf;
	for (int i=0; i<2*n; i++)
	{
		int v=abs(wek[i].second);
		if (wek[i].second<0)
		{
			wrzu(t[v]);
			najb=min(najb, a[v]+t[v]);
		}
		else
		{
			usun(t[v]);
		}
		//~ debug() << v << " " << wek[i] << "   " << najb;
		if (i+1==2*n || najb<=wek[i+1].first)
		{
			wyn++;
			if (setel.empty())
			{
				najb=inf;
				continue;
			}
			ll x=mini();
			ll przer=wek[i+1].first-najb;
			ll ile=przer/x;
			//~ debug() << imie(x) << imie(przer) << imie(ile);
			wyn+=ile;
			najb+=(ile+1)*x;
			//~ debug() << imie(najb);
		}
		else
		{
			continue;
		}
	}
	
	
	printf("%lld\n", wyn);
	return 0;
}