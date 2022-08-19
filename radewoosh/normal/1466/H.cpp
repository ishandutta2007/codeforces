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
const int nax=47;
const ll mod=1000*1000*1000+7;
const ll sumod=10000000000000061LL;

int n;

ll kom[nax][nax];
ll sil[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void mnoz(ll &a, ll b)
{
	a=(a*b)%mod;
}

int tab[nax];
int bylo[nax];

int ter[nax];

ll rek(const vi &wek, int poprz, int skip);

//~ ll dp[nax][2];

ll policz(ll tak, ll nie, int r)
{
	//~ dp[0][0]=1;
	//~ dp[0][1]=0;
	//~ for (int i=1; i<=r; i++)
	//~ {
		//~ dp[i][0]=(dp[i-1][0]*nie)%mod;
		//~ dp[i][1]=((dp[i-1][0]+dp[i-1][1])*tak+dp[i-1][1]*nie)%mod;
	//~ }
	//~ return dp[r][1];
	
	ll a=1;
	ll b=1;
	for (int i=1; i<=r; i++)
	{
		a=(a*(tak+nie))%mod;
		b=(b*nie)%mod;
	}
	a-=b;
	if (a<0)
		a+=mod;
	return a;
	
	//~ ll ret=1;
	//~ for (int i=1; i<=r; i++)
		//~ ret=(ret*tak)%mod;
	//~ return ret;
}

ll sptak[nax][nax][nax];
ll spnie[nax][nax][nax];

ll rek2(int v, const vi &wek, int poprz, int skip, ll mno, int wybr)
{
	if (v==n+1)
	{
		if (!wybr)
			return 0;
		ll prze=1;
		int x=0;
		for (int i=1; i<=n; i++)
			x+=ter[i]*i;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=ter[i]; j++)
				prze=prze*(sptak[poprz][skip][i]-spnie[poprz][skip][i])%mod;
		if (prze<0)
			prze+=mod;
		vi now(n+1);
		for (int i=1; i<=n; i++)
			now[i]=wek[i]-ter[i];
		return rek(now, x, skip+poprz)*prze%mod*mno%mod;
	}
	ll ret=0;
	for (int i=0; i<=wek[v]; i++)
	{
		int pam=ter[v];
		ter[v]=i;
		ret+=rek2(v+1, wek, poprz, skip, (mno*kom[wek[v]][i])%mod, wybr+i);
		ter[v]=pam;
	}
	return ret%mod;
}

unordered_map<ll,ll> mapa[nax];

ll rek(const vi &wek, int poprz, int skip)
{
	int kon=1;
	for (int i=1; i<=n; i++)
		if (wek[i])
			kon=0;
	if (kon)
		return 1;
	ll ha=0;
	for (int i=1; i<=n; i++)
		ha=(ha*107+wek[i])%sumod;
	if (mapa[skip].count(ha))
		return mapa[skip][ha];
	ll ret=rek2(1, wek, poprz, skip, 1, 0);
	//~ debug() << wek << " " << poprz << " " << skip << " " << ret;
	return mapa[skip][ha]=ret%mod;
}

int main()
{
	scanf("%d", &n);
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j-1]+kom[i-1][j])%mod;
	}
	vi cyk;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		//~ tab[i]=i;
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		int v=i;
		int ile=0;
		while(!bylo[v])
		{
			bylo[v]=1;
			ile++;
			v=tab[v];
		}
		cyk.push_back(ile);
	}
	//~ cyk={1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6};
	//~ debug() << imie(cyk);
	for (int poprz=0; poprz<n; poprz++)
	{
		for (int skip=0; skip+poprz<n; skip++)
		{
			if (skip && !poprz)
				continue;
			ll strz=0;
			ll bez=0;
			for (int p=1-(!poprz); p<=poprz; p++)
			{
				for (int q=0; q<=skip; q++)
				{
					ll wyb=kom[poprz][p]*kom[skip][q]%mod;
					mnoz(wyb, sil[p+q]);
					mnoz(wyb, sil[n-p-q-1]);
					dod(strz, wyb);
				}
			}
			for (int p=0; p<=poprz; p++)
			{
				for (int q=0; q<=skip; q++)
				{
					ll wyb=kom[poprz][p]*kom[skip][q]%mod;
					mnoz(wyb, sil[p+q]);
					mnoz(wyb, sil[n-p-q-1]);
					dod(bez, wyb);
				}
			}
			bez=(bez-strz)%mod;
			bez+=mod;
			bez%=mod;
			sptak[poprz][skip][0]=1;
			spnie[poprz][skip][0]=1;
			for (int i=1; i<=n; i++)
			{
				sptak[poprz][skip][i]=(sptak[poprz][skip][i-1]*(strz+bez))%mod;
				spnie[poprz][skip][i]=(spnie[poprz][skip][i-1]*bez)%mod;
			}
		}
	}
	vi takie(n+1);
	for (int i : cyk)
		takie[i]++;
	ll wez=rek(takie, 0, 0);
	printf("%lld\n", wez);
	return 0;
}