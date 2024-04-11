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
const int nax=4007;
const ll inf=1e18;

int n, m;

ll tab[nax];

int wsk;

ll dp[nax][nax];
int roz[nax];

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

int rek(int a, int b)
{
	if (a>b)
		return 0;
	//~ if (a==b)
	//~ {
		//~ wsk++;
		//~ roz[wsk]=1;
		//~ dp[wsk][0]=0;
		//~ dp[wsk][1]=m*tab[a]-tab[a];
		//~ return wsk;
	//~ }
	int g=a;
	for (int i=a; i<=b; i++)
		if (tab[i]<tab[g])
			g=i;
	int x=rek(a, g-1);
	int y=rek(g+1, b);
	wsk++;
	int mx=roz[x];
	int my=roz[y];
	for (int i=0; i<=mx+my+1; i++)
		dp[wsk][i]=-inf;
	for (int i=0; i<=mx; i++)
	{
		for (int j=0; j<=my; j++)
		{
			maxi(dp[wsk][i+j], dp[x][i]+dp[y][j]-2*i*j*tab[g]);
			maxi(dp[wsk][i+j+1], dp[x][i]+dp[y][j]-2*i*j*tab[g]+m*tab[g]-(2*i+2*j+1)*tab[g]);
			
			
			
			//~ if (a==1 && b==n && i+j+1==4 && dp[x][i]+dp[y][j]-i*j*tab[g]+m*tab[g]-(i+j+1)*tab[g]==132)
				//~ debug() << i << " " << j;
			//~ if (a==1 && b==n && i+j==4 && dp[x][i]+dp[y][j]-i*j*tab[g]==132)
				//~ debug() << i << " " << j;
				
				
			//~ if (a==3 && b==n && i+j+1==3 && dp[x][i]+dp[y][j]-i*j*tab[g]+m*tab[g]-(i+j+1)*tab[g]==93)
				//~ debug() << i << " " << j;
			//~ if (a==3 && b==n && i+j==3 && dp[x][i]+dp[y][j]-i*j*tab[g]==93)
				//~ debug() << i << " " << j;
				
				
			//~ if (a==3 && b==5 && i+j+1==3 && dp[x][i]+dp[y][j]-i*j*tab[g]+m*tab[g]-(i+j+1)*tab[g]==93)
				//~ debug() << i << " " << j;
			//~ if (a==3 && b==5 && i+j==3 && dp[x][i]+dp[y][j]-i*j*tab[g]==93)
				//~ debug() << i << " " << j;
		}
	}
	roz[wsk]=mx+my+1;
	//~ debug() << a << " " << b << " " << range(dp[wsk], dp[wsk]+1+roz[wsk]);
	return wsk;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	dp[0][0]=0;
	int wez=rek(1, n);
	printf("%lld\n", dp[wez][m]);
	return 0;
}