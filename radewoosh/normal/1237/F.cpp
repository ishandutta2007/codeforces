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
const int nax=3707;
const ll mod=998244353;

int n, m, k;

int zak1[nax];
int zak2[nax];

vi raz, dwa;

ll dp1[nax][nax];
ll dp2[nax][nax];

void dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

ll sil[nax];
ll kom[nax][nax];

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=0; i<nax; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j-1]+kom[i-1][j])%mod;
	}
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		zak1[a]=zak1[x]=1;
		zak2[b]=zak2[y]=1;
	}
	zak1[n+1]=1;
	zak2[m+1]=1;
	zak1[0]=1;
	zak2[0]=1;
	{
		int v=0;
		while(v<n)
		{
			v++;
			int ile=0;
			while(!zak1[v])
				v++, ile++;
			//~ v++;
			if (ile)
				raz.push_back(ile);
		}
	}
	{
		int v=0;
		while(v<m)
		{
			v++;
			int ile=0;
			while(!zak2[v])
				v++, ile++;
			//~ v++;
			if (ile)
				dwa.push_back(ile);
		}
	}
	//~ debug() << raz << " " << dwa;
	dp1[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=n; j++)
			dp1[i][j]=dp1[i-1][j];
		if (!zak1[i] && !zak1[i-1])
			for (int j=1; j<=n; j++)
				dod(dp1[i][j], dp1[i-2][j-1]);
	}
	dp2[0][0]=1;
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<=m; j++)
			dp2[i][j]=dp2[i-1][j];
		if (!zak2[i] && !zak2[i-1])
			for (int j=1; j<=m; j++)
				dod(dp2[i][j], dp2[i-2][j-1]);
	}
	//~ debug() << range(dp1[n], dp1[n]+n+1);
	//~ debug() << range(dp2[m], dp2[m]+m+1);
	int p1=0;
	int p2=0;
	for (int i=1; i<=n; i++)
		p1+=(!zak1[i]);
	for (int i=1; i<=m; i++)
		p2+=(!zak2[i]);
	ll wyn=0;
	for (int i=0; 2*i<=p1; i++)
	{
		for (int j=0; 2*j<=p2; j++)
		{
			ll moz=dp1[n][i]*dp2[m][j]%mod;
			if (2*i+j<=p1 && 2*j+i<=p2 && moz)
			{
				wyn=(wyn+moz*kom[p1-2*i][j]%mod*sil[j]%mod*kom[p2-2*j][i]%mod*sil[i]%mod)%mod;
			}
		}
	}
	printf("%lld\n", wyn);
	return 0;
}