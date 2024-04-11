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

int n, m;
ll k;

int t1[nax];
int t2[nax];

int g;

int gdz[nax];

//~ ll nat[nax];

ll odw;
ll bed[nax];

ll check(ll v)
{
	ll ret=v;
	int jed=m/g;
	for (int i=0; i<n; i++)
	{
		bed[i]=(v+n-i-1)/n;
		if (gdz[t1[i]]==-1)
			continue;
		int j=gdz[t1[i]];
		if ((i%g)!=(j%g))
			continue;
		ll ruch=(j/g-(i%m)/g+(jed))%(jed);
		ruch=(ruch*odw)%(jed);
		//~ ruch*=g;
		//~ ruch+=(i%g);
		//~ debug() << i << " " << ruch;
		
		if (ruch>=bed[i])
			continue;
		//~ debug() << i << " " << bed[i] << " " << ruch;
		ret-=(bed[i]-ruch-1+(m/g))/(m/g);
	}
	//~ exit(0);
	return ret;
}

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	for (int i=0; i<n; i++)
		scanf("%d", &t1[i]);
	for (int i=0; i<m; i++)
		scanf("%d", &t2[i]);
	memset(gdz, -1, sizeof(gdz));
	g=__gcd(n, m);
	for (int i=0; i<m; i++)
		gdz[t2[i]]=i;
	//~ check(47);
	//~ ll odw=0;
	for (int i=1; i<=(m/g); i++)
	{
		//~ debug() << i << " " << (n/g)*i << " " << (n/g)*i%(m/g);
		if ((i*(ll)(n/g))%(m/g)==(1%(m/g)))
			odw=i;
	}
	debug() << imie(odw);
	
	//~ check(44);
	//~ return 0;
	ll bsa=0;
	ll bsb=1e18;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb)>>1;
		if (check(bss)>=k)
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%lld\n", bsa);
	return 0;
}