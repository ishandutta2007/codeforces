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
//~ const int nax=1000*1007;
const int nax=(1<<20);
const ll mod=998244353;

int n;

//~ ll ndp[nax];
//~ ll pdp[nax];

//~ void dod(ll &a, ll b)
//~ {
	//~ a=(a+b)%mod;
//~ }

//~ int wys(int v)
//~ {
	//~ int ret=0;
	//~ while((1<<ret)-1<v)
		//~ ret++;
	//~ return ret;
//~ }

bitset <nax> dp;

int main()
{
	scanf("%d", &n);
	int k=1;
	while(2*k+1<=n)
		k=2*k+1;
	int m=k+1;
	int r=n-k;
	int ile=0;
	for (int i=1; i<m; i++)
	{
		int x=__builtin_ctz(i);
		//~ debug() << i << " " << x;
		ile+=(x&1);
	}
	printf("%d\n", (int)(r==ile || r==ile+1));
	//~ for (int i=m-1; i; i--)
	//~ {
		//~ int licz=0;
		//~ for (int j=i+1; j<i+(i&(-i)); j++)
			//~ licz^=dp[j];
		
	//~ }
	//~ debug() << imie(m) << imie(r);
	//~ pdp[0]=ndp[0]=1;
	//~ int ile=0;
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ for (int j=1; j<=i; j++)
		//~ {
			//~ if (wys(j-1)>wys(i)-1 || wys(i-j)>wys(i)-1)
				//~ continue;
			//~ if (j&1)
				//~ dod(ndp[i], pdp[j-1]*pdp[i-j]);
			//~ else
				//~ dod(pdp[i], ndp[j-1]*pdp[i-j]);
		//~ }
		//~ ll x=(ndp[i]+pdp[i])%mod;
		//~ ile+=(x>0);
		//~ debug() << i << " " << x;
		//~ printf("%d %lld\n", i, (ndp[i]+pdp[i])%mod);
	//~ }
	//~ debug() << imie(ile);
	return 0;
}