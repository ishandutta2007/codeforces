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

int tab[nax];

set<int> setel, pary;
vi wyn;

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	wyn.clear();
	setel.clear();
	pary.clear();
	for (int i=1; i<=n; i++)
	{
		setel.insert(i);
	}
	for (int i=1; i<n; i++)
		if (__gcd(tab[i], tab[i+1])==1)
			pary.insert(i);
	if (__gcd(tab[1], tab[n])==1)
		pary.insert(n);
	int ost=0;
	while(1)
	{
		if (pary.empty())
			break;
		auto it=pary.upper_bound(ost);
		if (it==pary.end())
			it=pary.begin();
		int x=(*it);
		
		if (!setel.count(x))
		{
			pary.erase(x);
			continue;
		}
		
		auto jt=setel.upper_bound(x);
		if (jt==setel.end())
			jt=setel.begin();
		int y=(*jt);
		wyn.push_back(y);
		ost=x;
		
		pary.erase(x);
		setel.erase(y);
		if (setel.empty())
			break;
		
		auto kt=setel.upper_bound(x);
		if (kt==setel.end())
			kt=setel.begin();
		int z=(*kt);
		if (__gcd(tab[x], tab[z])==1)
			pary.insert(x);
	}
	
	
	printf("%d", (int)wyn.size());
	for (int i : wyn)
		printf(" %d", i);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}