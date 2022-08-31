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

int n, d;
ll m;

ll tab[nax];

//~ ll dp[nax];

ll male[nax];

int main()
{
	scanf("%d%d%lld", &n, &d, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	//~ for (int i=n; i; i--)
	//~ {
		//~ dp[i]=dp[i+1];
		//~ if (tab[i]<=m)
			//~ dp[i]+=tab[i];
		//~ else
			//~ dp[i]=max(dp[i], tab[i]+dp[min(n+1, i+d)]);
	//~ }
	vll mnie, wie;
	ll wyn=0;
	for (int i=1; i<=n; i++)
	{
		if (tab[i]<=m)
			mnie.push_back(tab[i]);
		else
			wie.push_back(tab[i]);
	}
	sort(mnie.begin(), mnie.end());
	reverse(mnie.begin(), mnie.end());
	sort(wie.begin(), wie.end());
	reverse(wie.begin(), wie.end());
	for (int i=1; i<=(int)mnie.size(); i++)
	{
		male[i]=male[i-1]+mnie[i-1];
	}
	for (int i=(int)mnie.size()+1; i<nax; i++)
		male[i]=male[i-1];
	ll s=0;
	//~ debug() << mnie << " " << wie;
	for (int i=0; i<=(int)wie.size(); i++)
	{
		ll ile=(i-1)*(ll)(d+1)+1;
		if (!i)
			ile=0;
		if (ile<=n)
			wyn=max(wyn, s+male[n-ile]);
		//~ debug() << i << " " << ile << " " << s << " " << male[n-ile];
		
		if (i<(int)wie.size())
			s+=wie[i];
	}
	//~ printf("%lld\n", dp[1]);
	printf("%lld\n", wyn);
	return 0;
}