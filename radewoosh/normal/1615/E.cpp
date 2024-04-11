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

int n, k;

vi graf[nax];

vi wek;

int dfs1(int v, int oj)
{
	for (int &i : graf[v])
	{
		if (i==oj)
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	int ret=0;
	for (int i : graf[v])
	{
		int wez=dfs1(i, v);
		if (wez>ret)
			swap(ret, wez);
		wek.push_back(wez);
	}
	ret++;
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int wez=dfs1(1, 0);
	wek.push_back(wez);
	while((int)wek.size()<n)
		wek.push_back(0);
	sort(wek.begin(), wek.end());
	ll wyn=-1e18;
	reverse(wek.begin(), wek.end());
	ll s=0;
	for (int i=1; i<=k; i++)
	{
		s+=wek[i-1];
		ll moze=n-s;
		moze=min(moze, n/2LL);
		//~ debug() << i << " " << s << " " << moze;
		wyn=max(wyn, (n-i-moze)*(i-moze));
	}
	printf("%lld\n", wyn);
	return 0;
}