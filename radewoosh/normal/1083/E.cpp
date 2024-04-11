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
const int nax=1200*1007;
using mag=long double;

int n;

pair <pll,ll> tab[nax];

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

mag ilowek(pll s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	return a.first*(mag)b.second-a.second*(mag)b.first;
}

ll wyn;
ll dp[nax];

vector <pll> oto;

void wrzuc(pll v)
{
	int r=oto.size();
	while(r>=2 && ilowek(oto[r-2], oto[r-1], v)<=0)
	{
		r--;
		oto.pop_back();
	}
	oto.push_back(v);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld%lld", &tab[i].first.first, &tab[i].first.second, &tab[i].second);
	sort(tab+1, tab+1+n);
	int l=0;
	for (int i=1; i<=n; i++)
	{
		wrzuc({dp[i-1], tab[i-1].first.first});
		ll x=tab[i].first.first;
		ll y=tab[i].first.second;
		l=min(l, (int)oto.size()-1);
		while(l+1<(int)oto.size() && oto[l+1].first-oto[l+1].second*y>=oto[l].first-oto[l].second*y)
			l++;
		dp[i]=oto[l].first+y*(x-oto[l].second)-tab[i].second;
		wyn=max(wyn, dp[i]);
		//~ debug() << tab[i] << " " << dp[i] << " " << oto;
	}
	
	printf("%lld\n", wyn);
	return 0;
}