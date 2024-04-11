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

int n;
int tab[nax];
int gdz[nax];

ll drz[nax][2];

ordered_set <int> setel;

ll inv;

void pisz(int v, int p, ll w)
{
	for (int i=v; i; i-=(i&(-i)))
		drz[i][p]+=w;
}

ll czyt(int v, int p)
{
	ll ret=0;
	for (int i=v; i<=n; i+=(i&(-i)))
		ret+=drz[i][p];
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		gdz[tab[i]]=i;
	}
	for (int h=1; h<=n; h++)
	{
		int v=gdz[h];
		inv+=czyt(v, 0);
		pisz(v, 0, 1);
		setel.insert(v);
		auto it=*setel.find_by_order(h/2);
		pisz(v, 1, v);
		ll lew=h/2;
		ll pra=h-lew-1;
		ll spra=czyt(it, 1);
		ll slew=czyt(1, 1)-spra;
		spra-=(it);
		//~ debug() << imie(it);
		//~ debug() << h << " " << v << "  " << lew << " " << pra << "  " << slew << " " << spra << "  " << inv;
		spra=spra-pra*it;
		slew=lew*it-slew;
		//~ debug() << h << " " << v << "  " << lew << " " << pra << "  " << slew << " " << spra << "  " << inv;
		printf("%lld ", inv+spra+slew-lew*(lew+1)/2-pra*(pra+1)/2);
		//~ debug();
		
	}
	printf("\n");
	return 0;
}