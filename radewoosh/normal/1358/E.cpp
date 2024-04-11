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
ll pref[nax];

int sr;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		if (i<=(n+1)/2+1)
			scanf("%lld", &tab[i]);
		else
			tab[i]=tab[i-1];
	}
	for (int i=1; i<=n; i++)
		pref[i]=pref[i-1]+tab[i];
	sr=((n+1)/2)+1;
	multiset<ll> setel;
	int pol=sr-1;
	int ost=0;
	for (int i=1; i+pol-1<=n; i++)
	{
		setel.insert(pref[i+pol-1]-pref[i-1]);
		ost=i;
	}
	debug() << setel;
	for (int i=0; pol+i<=n; i++)
	{
		auto it=setel.begin();
		if ((*it)+i*tab[sr]>0)
		{
			printf("%d\n", pol+i);
			return 0;
		}
		if (pol+i==n)
			break;
		ll daj=ost-i;
		if (daj+pol+i-1==n)
			setel.erase(setel.find(pref[daj+pol-1]-pref[daj-1]));
	}
	printf("-1\n");
	return 0;
}