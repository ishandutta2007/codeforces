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

void ans(vector<pii> wek)
{
	printf("%d\n", (int)wek.size());
	for (pii i : wek)
		printf("%d %d\n", i.first, i.second);
	//~ set<pii> setel;
	//~ for (pii i : wek)
	//~ {
		//~ int a=i.first;
		//~ int b=i.second;
		//~ for (int j=-n; j<=n; j++)
		//~ {
			//~ setel.insert({a+j, b});
			//~ setel.insert({a, b+j});
			//~ setel.insert({a+j, b+j});
		//~ }
	//~ }
	//~ for (int i=1; i<=n; i++)
		//~ for (int j=1; j<=n; j++)
			//~ assert(setel.count({i, j}));
	exit(0);
}

int spoko[nax];

int main()
{
	scanf("%d", &n);
	vector<pii> wek;
	int v=1;
	while(v+v+1+v+1<=n)
		v++;
	v--;
	while(n>v+v+1+v+1)
	{
		wek.push_back({n, n});
		n--;
	}
	for (int i=1; i<=v; i++)
	{
		wek.push_back({i, v+1-i});
	}
	for (int i=1; i<=v+1; i++)
	{
		wek.push_back({v+i, v+v+2-i});
	}
	
	
	ans(wek);
	return 0;
}