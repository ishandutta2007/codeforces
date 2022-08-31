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
const ll d=2100*2100;
const ll inf=1e18;

int n;
ll tab[nax];

vll kwa;

vector<pll> prz;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ost[nax];
int ile;
ll wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		//~ tab[i]=2*i-(rand()&1);
		if (tab[i]==tab[i-1])
		{
			n--;
			i--;
		}
	}
	shuffle(tab+1, tab+1+n, rng);
	for (int i=1; i<=n; i++)
		ost[i]=-1;
	for(int h=0; ile<n; h++)
	{
		int v=h%n+1;
		if (ost[v]==wyn)
			continue;
		ll x=sqrt(tab[v]+wyn);
		if (x*x>tab[v]+wyn)
			x--;
		ll d=x*x;
		ll g=(x+1)*(x+1);
		if (tab[v]+wyn-d>=g-(tab[v]+wyn))
		{
			wyn=g-tab[v];
			ile=1;
			ost[v]=wyn;
		}
		else
		{
			ost[v]=wyn;
			ile++;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}