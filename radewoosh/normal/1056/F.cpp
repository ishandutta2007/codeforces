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
const int nax=1007;
const double inf=1e18;

double c, t;
int n, m;

pii tab[nax];

double dp[nax][nax];

double f(double v, double x)
{
	return x+v/(1+c*x);
}

double mini(double v)
{
	double tsa=0;
	double tsb=t;
	for (int h=0; h<60; h++)
	{
		double ts1=(3*tsa+2*tsb)/5;
		double ts2=(2*tsa+3*tsb)/5;
		if (f(v, ts1)<f(v, ts2))
			tsb=ts2;
		else
			tsa=ts1;
	}
	//~ debug() << (tsa+tsb)/2 << " " << f(v, (tsa+tsb)/2);
	return f(v, (tsa+tsb)/2);
}

void test()
{
	scanf("%d", &n);
	scanf("%lf%lf", &c, &t);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &tab[i].first, &tab[i].second);
	sort(tab+1, tab+1+n);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n*10; j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	int s=0;
	for (int i=1; i<=n; i++)
	{
		for (int l=i-1; l>=0; l--)
			for (int j=s; j>=0; j--)
				dp[l+1][j+tab[i].second]=min(dp[l+1][j+tab[i].second], dp[l][j]*10.0/9.0+tab[i].first);
		s+=tab[i].second;
	}
	int wyn=0;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=s; j++)
		{
			if (dp[i][j]>inf/2)
				continue;
			if (i*10.0+mini(dp[i][j]*10.0/9.0)<=t)
			{
				wyn=max(wyn, j);
				//~ if (j==9)
					//~ debug() << i << " " << j << "  " << dp[i][j];
			}
		}
	}
	
	printf("%d\n", wyn);
	//~ exit(0);
	//~ debug() << range(dp, dp+1+s);
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while(tt--)
		test();
	return 0;
}