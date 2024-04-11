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

ll pre[nax];
ll suf[nax];

ll sum[nax];

void ans(int v)
{
	if (v==1)
		printf("YES\n");
	else
		printf("NO\n");
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=0; i<=n+2; i++)
		pre[i]=suf[i]=0;
	if (n<=2)
	{
		ans(1);
		return;
	}
	tab[n+1]=0;
	for (int i=1; i<n; i++)
	{
		if (tab[i]<tab[i+1])
		{
			suf[i+1]=tab[i+1]-tab[i];
		}
		else
		{
			pre[i]=tab[i]-tab[i+1];
		}
	}
	for (int i=2; i<=n; i++)
		suf[i]+=suf[i-1];
	for (int i=n-1; i; i--)
		pre[i]+=pre[i+1];
	ll dod=max(0LL, tab[1]-(pre[1]+suf[1]));
	debug() << range(pre+1, pre+1+n);
	debug() << range(suf+1, suf+1+n);
	for (int i=1; i<=n; i++)
	{
		if (pre[i]+suf[i]+dod!=tab[i])
		{
			ans(0);
			return;
		}
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}