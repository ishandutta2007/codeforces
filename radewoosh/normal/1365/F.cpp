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
ll a[nax];
ll b[nax];

void ans(int v)
{
	if (v)
		printf("Yes\n");
	else
		printf("No\n");
}

vi operator *(vi a, vi b)
{
	vi ret(n);
	for (int i=0; i<n; i++)
		ret[i]=b[a[i]];
	return ret;
}

pll para(ll *w, int a, int b)
{
	pll ret={w[a], w[b]};
	if (ret.first>ret.second)
		swap(ret.first, ret.second);
	return ret;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &b[i]);
	if ((n&1) && a[n/2+1]!=b[n/2+1])
	{
		ans(0);
		return;
	}
	map<pll,int> mapa;
	for (int i=1; i<=n/2; i++)
	{
		mapa[para(a, i, n+1-i)]++;
		mapa[para(b, i, n+1-i)]--;
	}
	for (auto i : mapa)
	{
		if (i.second)
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