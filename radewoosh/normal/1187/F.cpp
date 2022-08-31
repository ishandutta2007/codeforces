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
const int nax=1000*1007;
const ll mod=1000*1000*1000+7;

int n;

ll l[nax];
ll r[nax];

ll zm2, zm;

ll tu[nax];

ll dlu[nax];

ll dziel(ll a, ll b)
{
	//~ debug() << a << " " << b;
	a%=mod;
	b%=mod;
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &l[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &r[i]);
	for (int i=1; i<n; i++)
	{
		ll wsz=(r[i]-l[i]+1)*(r[i+1]-l[i+1]+1)%mod;
		ll dob=0;
		ll a=max(l[i], l[i+1]);
		ll b=min(r[i], r[i+1]);
		if (a<=b)
			dob=b-a+1;
		dlu[i]=dob;
		ll x=dziel(mod+wsz-dob, wsz);
		zm=(zm+x)%mod;
		tu[i]=x;
	}
	ll s=0;
	//~ debug() << range(tu+1, tu+1+n);
	for (int i=2; i<=n; i++)
	{
		zm2=(zm2+tu[i]*s)%mod;
		s=(s+tu[i-1])%mod;
	}
	for (int i=1; i+2<=n; i++)
	{
		ll wsz=(r[i]-l[i]+1)*(r[i+1]-l[i+1]+1)%mod*(r[i+2]-l[i+2]+1)%mod;
		ll a=max(l[i], l[i+1]);
		ll b=min(r[i], r[i+1]);
		a=max(a, l[i+2]);
		b=min(b, r[i+2]);
		//~ debug() << imie(wsz);
		//~ debug() << imie(dlu[i]*(r[i+2]-l[i+2]+1));
		//~ debug() << imie(dlu[i+1]*(r[i]-l[i]+1));
		//~ debug() << imie(max(0LL, b-a+1));
		zm2+=dziel(wsz-dlu[i]*(r[i+2]-l[i+2]+1)-dlu[i+1]*(r[i]-l[i]+1)+max(0LL, b-a+1), wsz);
		zm2%=mod;
		zm2+=mod;
		zm2%=mod;
	}
	
	debug() << imie(zm);
	debug() << imie(zm2);
	
	zm2=(zm2*2+zm)%mod;
	
	printf("%lld\n", (zm2+2*zm+1)%mod);
	return 0;
}