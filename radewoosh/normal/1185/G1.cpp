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
const int nax=2507;
const ll mod=1000*1000*1000+7;

int n, m;

int dlu[nax];
int typ[nax];

int ile[nax];

int na, nb, nc;
vll dp[52][52][52];

ll wyn;

ll dp2[52][52][52][4];
ll sil[nax];

void dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &dlu[i], &typ[i]);
		ile[typ[i]]++;
	}
	na=ile[1];
	nb=ile[2];
	nc=ile[3];
	for (int i=0; i<=na; i++)
		for (int j=0; j<=nb; j++)
			for (int l=0; l<=nc; l++)
				dp[i][j][l].resize(m+1);
	dp[0][0][0][0]=1;
	int ds=0;
	for (int h=1; h<=n; h++)
	{
		for (int p=ds; p>=0; p--)
		{
			if (p+dlu[h]>m)
				continue;
			for (int i=0; i<=na; i++)
				for (int j=0; j<=nb; j++)
					for (int l=0; l<=nc; l++)
					{
						if (!dp[i][j][l][p])
							continue;
						int ii=i;
						int jj=j;
						int ll=l;
						if (typ[h]==1)
							ii++;
						if (typ[h]==2)
							jj++;
						if (typ[h]==3)
							ll++;
						dod(dp[ii][jj][ll][p+dlu[h]], dp[i][j][l][p]);
					}
		}
		ds+=dlu[h];
	}
	dp2[0][0][0][0]=1;
	for (int i=0; i<=na; i++)
		for (int j=0; j<=nb; j++)
			for (int l=0; l<=nc; l++)
				for (int p=0; p<4; p++)
					for (int w=1; w<4; w++)
						if (w!=p)
							dod(dp2[i+(w==1)][j+(w==2)][l+(w==3)][w], dp2[i][j][l][p]);
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i%mod);
	for (int i=0; i<=na; i++)
		for (int j=0; j<=nb; j++)
			for (int l=0; l<=nc; l++)
			{
				ll x=dp[i][j][l][m];
				ll s=0;
				for (int p=0; p<4; p++)
					s+=dp2[i][j][l][p];
				s%=mod;
				dod(wyn, x*s%mod*sil[i]%mod*sil[j]%mod*sil[l]%mod);
			}
	printf("%lld\n", wyn);
	return 0;
}