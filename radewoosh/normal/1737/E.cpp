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
const ll mod=1000*1000*1000+7;

int n;

ll p2[nax];
ll o2[nax];

ll baza[nax];

ll nikt[nax];

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

void fix(ll &v)
{
	v%=mod;
	if (v<0)
		v+=mod;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		baza[i]=o2[(i+1)/2-(i==n)];
	}
	baza[n+1]=0;
	baza[n+2]=0;
	nikt[n]=2;
	ll s=2;
	for (int i=n-1; i; i--)
	{
		s=s*o2[1]%mod;
		if (2*i<=n)
			s-=nikt[2*i]*o2[i];
		if (2*i+1<=n)
			s-=nikt[2*i+1]*o2[i+1];
		fix(s);
		nikt[i]=s;
		s=(s+nikt[i])%mod;
	}
	nikt[n]=1;
	for (int i=1; i<=n; i++)
		printf("%lld\n", baza[i]*nikt[i]%mod);
}

int main()
{
	p2[0]=1;
	o2[0]=1;
	p2[1]=2;
	o2[1]=inv(2);
	for (int i=2; i<nax; i++)
	{
		p2[i]=(p2[i-1]*2)%mod;
		o2[i]=(o2[i-1]*o2[1])%mod;
	}
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}