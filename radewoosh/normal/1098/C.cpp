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

int n;
ll s;

int k=1;

ll ile[nax];
ll lim[nax];

vi tso[nax];

ll powy(int v)
{
	//~ ll ret=1;
	//~ vll dp(n);
	//~ dp[0]=1;
	//~ for (int i=1; i<n; i++)
	//~ {
		//~ dp[i]=dp[(i-1)/v]+1;
		//~ ret+=dp[i];
	//~ }
	//~ return ret;
	ll ret=1;
	ll ile=1;
	ll jesz=n-1;
	for (int i=2; jesz; i++)
	{
		ile=min(ile*v, jesz);
		jesz-=ile;
		ret+=i*ile;
	}
	return ret;
}

int main()
{
	scanf("%d%lld", &n, &s);
	if (s>n*(n+1LL)/2 || s<2*n-1)
	{
		printf("No\n");
		exit(0);
	}
	while(powy(k)>s)
		k++;
	//~ int bsa=1;
	//~ int bsb=n;
	//~ int bss;
	//~ while(bsa<bsb)
	//~ {
		//~ bss=(bsa+bsb)>>1;
		//~ if (powy(bss)<)
	//~ }
	//~ k=bsa;
	
	//~ debug() << imie(k);
	printf("Yes\n");
	lim[1]=1;
	for (int i=2; i<=n; i++)
		lim[i]=min((ll)n, lim[i-1]*k);
	ll ter=n*(n+1LL)/2;
	for (int i=1; i<=n; i++)
		ile[i]=1;
	for (int i=n; ter>s; i--)
	{
		int g=1;
		while(ile[g]==lim[g])
			g++;
		while(ter-(i-g)<s)
			g++;
		ile[i]--;
		ile[g]++;
		ter-=(i-g);
	}
	int m=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<ile[i]; j++)
		{
			m++;
			tso[i].push_back(m);
			if (m>1)
				printf("%d ", tso[i-1][j/k]);
		}
	}
	printf("\n");
	return 0;
}