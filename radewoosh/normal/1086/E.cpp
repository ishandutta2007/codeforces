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

//~ #define int long long

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=2007;
const ll mod=998244353;

int n;

ll dp[nax][nax];

int tab[nax][nax];

ll wyn;

void fix(ll &v)
{
	if ((v%=mod)<0)
		v+=mod;
}

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int drz[2][nax];

void czys()
{
	for (int h=0; h<2; h++)
		for (int i=1; i<=n; i++)
			drz[h][i]=0;
}

void pisz(int h, int v, int w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		drz[h][i]+=w;
}

int czyt(int h, int v)
{
	int ret=0;
	for (int i=v; i>0; i-=(i&(-i)))
		ret+=drz[h][i];
	return ret;
}

int wpie[nax];
int wdru[nax];

ll run[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &tab[i][j]);
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ for (int j=1; j<=n; j++)
			//~ tab[i][j]=j;
		//~ if (!(i&1))
			//~ reverse(tab[i]+1, tab[i]+1+n);
	//~ }
	dp[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=i; j++)
		{
			if (!j)
			{
				dod(dp[i][j], dp[i-1][0]*i);
			}
			else
			{
				dod(dp[i][j], dp[i-1][j-1]*(i-j));
				if (j>1)
					dod(dp[i][j], dp[i-1][j-2]*(j-1));
				//~ dod(dp[i][j], dp[);
			}
			//~ if (i>=2)
			//~ {
			//~ ll x=(dp[i-1][i-1]*i-dp)%mod;
			//~ debug() << i << " " << x;
			//~ debug() << i << " " << j << "  " << dp[i][j];
		}
	}
	run[0]=1;
	for (int i=1; i<=n; i++)
		run[i]=(run[i-1]*dp[n][n])%mod;
	for (int i=1; i<=n; i++)
	{
		ll ilemn=0;
		for (int j=i+1; j<=n; j++)
			if (tab[1][j]<tab[1][i])
				ilemn++;
		dod(wyn, ((ilemn*dp[n-i][0])%mod)*run[n-1]);
	}
	
	for (int i=2; i<=n; i++)
	{
		czys();
		for (int j=1; j<=n; j++)
		{
			wpie[tab[i-1][j]]=j;
			wdru[tab[i][j]]=j;
		}
		for (int j=1; j<=n; j++)
			pisz(0, j, 1);
		for (int j=1; j<=n; j++)
		{
			int x=tab[i-1][j];
			int y=tab[i][j];
			assert(x!=y);
			if (wpie[y]>j)
			{
				pisz(0, y, -1);
			}
			else
			{
				pisz(1, y, -1);
			}
			if (wdru[x]>j)
			{
				pisz(0, x, -1);
				pisz(1, x, 1);
			}
			else
			{
				
			}
			int popra=czyt(0, y-1);
			int niepra=czyt(1, y-1);
			if (wdru[x]>j && x<y)
				niepra--;
			int japopra=(wpie[y]>j);
			int konf=czyt(0, n);
			//~ debug() << i << " " << j << "  " << x << " " << y << "   " << popra << " " << niepra << " " << japopra;
			if (popra)
				dod(wyn, ((popra*dp[n-j][konf-1+japopra])%mod)*run[n-i]);
			dod(wyn, ((niepra*dp[n-j][konf+japopra])%mod)*run[n-i]);
			//~ debug() << imie(wyn);
		}
	}
	fix(wyn);
	printf("%lld\n", wyn);
	return 0;
}