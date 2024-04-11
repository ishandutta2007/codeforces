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
const int n1=(1<<17);

int n, q;
ll tab[nax];

ll sum[nax];

pii prz[nax];
vi zap[nax];
ll ans[nax];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
	}
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		tab[i]=x-tab[i];
	}
	for (int i=1; i<=n; i++)
		sum[i]=tab[i]+sum[i-1];
	//~ debug() << range(tab+1, tab+1+n);
	//~ debug() << range(sum+1, sum+1+n);
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		prz[i]={a, b};
		//~ if (sum[a-1]!=sum[b])
		//~ {
			//~ printf("-1\n");
			//~ continue;
		//~ }
		zap[b].push_back(i);
	}
	vi duz, mal;
	for (int i=0; i<=n; i++)
	{
		while(!duz.empty() && sum[i]>sum[duz.back()])
			duz.pop_back();
		duz.push_back(i);
		while(!mal.empty() && sum[i]<sum[mal.back()])
			mal.pop_back();
		mal.push_back(i);
		//~ debug() << i << " " << mal << " " << duz;
		for (int p : zap[i])
		{
			int a=prz[p].first;
			int b=prz[p].second;
			if (sum[a-1]!=sum[b] || !binary_search(mal.begin(), mal.end(), a-1))
			{
				ans[p]=-1;
				continue;
			}
			int x=lower_bound(duz.begin(), duz.end(), a-1)-duz.begin();
			//~ debug() << p << " " << duz[x];
			ans[p]=sum[duz[x]]-sum[a-1];
		}
	}
	
	
	for (int i=1; i<=q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}