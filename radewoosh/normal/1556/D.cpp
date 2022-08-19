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
const int d=30;

void ff()
{
	fflush(stdout);
}

int n, k;

int ukr[]={1,6,4,2,3,5,4};

int pytand(int a, int b)
{
	printf("and %d %d\n", a, b);
	ff();
	int x;
	scanf("%d", &x);
	//~ x=ukr[a-1]&ukr[b-1];
	return x;
}

int pytor(int a, int b)
{
	printf("or %d %d\n", a, b);
	ff();
	int x;
	scanf("%d", &x);
	//~ x=ukr[a-1]|ukr[b-1];
	return x;
}

ll suma(int a, int b)
{
	return pytor(a, b)+pytand(a, b);
}

vll known;

int main()
{
	scanf("%d%d", &n, &k);
	ll a=suma(1, 2);
	ll b=suma(1, 3);
	ll c=suma(2, 3);
	known.push_back(a+b-c);
	known.push_back(a+c-b);
	known.push_back(b+c-a);
	for (ll &i : known)
		i/=2;
	ll odj=known[0];
	for (int i=4; i<=n; i++)
		known.push_back(suma(1, i)-odj);
	//~ debug() << known;
	sort(known.begin(), known.end());
	printf("finish %lld\n", known[k-1]);
	ff();
	return 0;
}