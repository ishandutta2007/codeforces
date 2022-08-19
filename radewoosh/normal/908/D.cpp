//while (clock()<=69*CLOCKS_PER_SEC)
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

const int nax=1007;
using ll=long long;
const ll mod=1000*1000*1000+7;

ll dziel(ll a, ll b)
{
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

int k, pa, pb;

ll sa, sb;

ll dp[nax][nax];

ll wyn;

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

ll mag;

int main()
{
	scanf("%d%d%d", &k, &pa, &pb);
	sa=dziel(pa, pa+pb);
	sb=dziel(pb, pa+pb);
	dp[1][0]=1;
	
	mag=dziel(sa, mod+1-sa);
	
	for (int i=1; i<=k; i++)
	{
		for (int j=0; j<=k; j++)
		{
			if (!dp[i][j])
				continue;
			if (i+j>=k)
			{
				//hack
				ll nor=i+j;
				dod(wyn, (nor+mag)*dp[i][j]);
				
				continue;
			}
			dod(dp[i+1][j], dp[i][j]*sa);
			dod(dp[i][j+i], dp[i][j]*sb);
		}
	}
	printf("%lld\n", wyn);
	return 0;
}