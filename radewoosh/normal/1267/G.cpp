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
const int nax=107;
const int vax=nax*nax;
using ld=long double;

int n, x;

int tab[nax];

const ll baza=1e15;
struct incior
{
	ll a=0;
	ll b=0;
	void norm()
	{
		a+=b/baza;
		b%=baza;
	}
	ld loge()
	{
		if (!a)
			return log(b);
		return log(baza)+log(a+b/(ld)baza);
	}
	int zero()
	{
		return (!a && !b);
	}
};

incior operator + (incior x, incior y)
{
	x.a+=y.a;
	x.b+=y.b;
	x.norm();
	return x;
}

incior dp[nax][vax];

ld wyn;

int main()
{
	scanf("%d%d", &n, &x);
	dp[0][0].b=1;
	int s=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		wyn+=tab[i];
		tab[i]-=x;
		for (int j=i-1; j>=0; j--)
			for (int l=s; l>=0; l--)
				dp[j+1][l+tab[i]]=(dp[j+1][l+tab[i]]+dp[j][l]);
		s+=tab[i];
	}
	for (int i=1; i<=n; i++)
	{
		incior sum;
		for (int j=0; j<=s; j++)
			sum=sum+dp[i][j];
		for (int j=0; j<=s; j++)
		{
			if (dp[i][j].zero())
				continue;
			ld fail=(n-i)/(ld)n;
			ld sr=(j-(x/2.0)*(n-i))/n;
			ld moz=sr/(1-fail);
			if (moz<=0)
				continue;
			ld opc=exp(dp[i][j].loge()-sum.loge());
			wyn-=opc*moz;
		}
	}
	printf("%.12lf\n", (double)wyn);
	return 0;
}