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

ll a, b, x, y, wx, wy;

int check(ll v)
{
	ll vx=v;
	ll vy=0;
	if (v>x)
	{
		vx=x;
		vy=v-x;
	}
	for (ll i=0; i<=vx && i*wx<=a; i++)
	{
		ll jesz=(a-i*wx)/wy;
		jesz=min(jesz, vy);
		if ((vx-i)*wx+(vy-jesz)*wy<=b)
			return 1;
	}
	return 0;
}

void test()
{
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &x, &y, &wx, &wy); 
	if (wx>wy)
	{
		swap(x, y);
		swap(wx, wy);
	}
	ll bsa=0;
	ll bsb=x+y;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb+2)>>1;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss-1;
	}
	printf("%lld\n", bsa);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}