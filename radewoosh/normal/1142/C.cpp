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
using ld=long double;
const ld eps=1e-18;

int n;

pll tab[nax];

vector <pll> oto;

bool mniej(pll a, pll b)
{
	a.second*=-1;
	b.second*=-1;
	return a<b;
}

int wyn;

#define kwa(x) (x*x)

int czyw(pll a, pll b, pll s)
{
	if (a.first<b.first)
		swap(a, b);
	ll bb=(a.second-b.second)-(kwa(a.first)-kwa(b.first));
	//~ bb/=(a.first-b.first);
	//~ debug() << imie(bb);
	//~ debug() << imie(s.second);
	//~ debug() << imie(a);
	//~ debug() << imie(a.second-kwa(a.first)-a.first*bb);
	//~ debug() << imie(kwa(s.first)+s.first*bb+a.second-kwa(a.first)-a.first*bb);
	return s.second*(a.first-b.first)<=kwa(s.first)*(a.first-b.first)+s.first*bb+a.second*(a.first-b.first)-kwa(a.first)*(a.first-b.first)-a.first*bb;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	sort(tab+1, tab+1+n, mniej);
	for (int i=1; i<=n; i++)
	{
		if (i>1 && tab[i].first==tab[i-1].first)
			continue;
		int r=oto.size();
		while(r>=2 && czyw(oto[r-2], tab[i], oto[r-1]))
		{
			r--;
			oto.pop_back();
		}
		oto.push_back(tab[i]);
	}
	debug() << oto;
	wyn=oto.size();
	wyn--;
	printf("%d\n", wyn);
	return 0;
}