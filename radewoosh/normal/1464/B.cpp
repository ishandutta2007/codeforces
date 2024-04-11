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
char wcz[nax];

ll x, y;

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	scanf("%lld%lld", &x, &y);
	if (x>y)
	{
		swap(x, y);
		for (int i=1; i<=n; i++)
			if (wcz[i]=='0' || wcz[i]=='1')
				wcz[i]^=('0'^'1');
	}
	ll jedpra=0;
	ll zerpra=0;
	ll jedlew=0;
	ll zerlew=0;
	ll ter=0;
	for (int i=n; i; i--)
	{
		if (wcz[i]=='0')
		{
			ter+=jedpra*x;
			zerpra++;
		}
		if (wcz[i]=='1' || wcz[i]=='?')
		{
			ter+=zerpra*y;
			jedpra++;
		}
	}
	ll wyn=ter;
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='0')
		{
			zerpra--;
			zerlew++;
			continue;
		}
		if (wcz[i]=='1')
		{
			jedpra--;
			jedlew++;
			continue;
		}
		jedpra--;
		ter-=zerpra*y;
		ter+=jedpra*x;
		
		ter-=zerlew*x;
		ter+=jedlew*y;
		wyn=min(wyn, ter);
		zerlew++;
	}
	printf("%lld\n", wyn);
	return 0;
}