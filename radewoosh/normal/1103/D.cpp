//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18;
const ll lim=1e12;

int n;
ll k;

ll tab[nax];
ll kosz[nax];

ll g;

int m;
vll roz;

void ans(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

ll li=0;

void rek(int v, ll w)
{
	if (w>lim/g)
		return;
	if (v==m)
	{
		li++;
		return;
	}
	rek(v, w*roz[v]);
	rek(v+1, w);
}

ll czysc(ll v)
{
	ll ret=1;
	for (ll i : roz)
	{
		while(!(v%i))
		{
			ret*=i;
			v/=i;
		}
	}
	return ret;
}

map <ll,vll> mapa;

ll dp[12][1<<11];

int czyok[1<<11];

int czy(ll v, int mas)
{
	ll ret=1;
	for (int i=0; i<m; i++)
	{
		if (mas&(1<<i))
		{
			while(!(v%roz[i]))
			{
				v/=roz[i];
				ret*=roz[i];
			}
		}
	}
	return (ret<=k);
}

void mini(ll &a, const ll &b)
{
	a=min(a, b);
}

void dodaj(ll v, int num)
{
	for (int i=m-1; i>=num; i--)
	{
		for (int j=0; j<(1<<m); j++)
		{
			int l=j;
			while(1)
			{
				if (czyok[l])
					mini(dp[i+1][j], dp[i][j^l]+v);
				if (!l)
					break;
				l=((l-1)&j);
			}
		}
	}
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &kosz[i]);
	for (int i=1; i<=n; i++)
		g=__gcd(g, tab[i]);
	debug() << imie(g);
	if (g==1)
		ans(0);
	ll pom=g;
	for (ll i=2; i*i<=pom; i++)
	{
		if (!(pom%i))
		{
			roz.push_back(i);
			pom/=i;
			i--;
		}
	}
	roz.push_back(pom);
	roz.resize(unique(roz.begin(), roz.end())-roz.begin());
	debug() << roz;
	m=roz.size();
	for (int i=1; i<=n; i++)
	{
		tab[i]=czysc(tab[i]);
		mapa[tab[i]].push_back(kosz[i]);
	}
	for (auto &i : mapa)
	{
		sort(i.second.begin(), i.second.end());
		while((int)i.second.size()>m)
			i.second.pop_back();
	}
	for (int i=0; i<=m; i++)
		for (int j=0; j<(1<<m); j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for (auto i : mapa)
	{
		for (int j=0; j<(1<<m); j++)
			czyok[j]=czy(i.first, j);
		debug() << i << " " << range(czyok, czyok+(1<<m));
		int num=0;
		for (ll j : i.second)
		{
			dodaj(j, num);
			num++;
		}
	}
	ll wyn=inf;
	int c=(1<<m)-1;
	for (int i=0; i<=m; i++)
		if (dp[i][c]<inf)
			mini(wyn, dp[i][c]*i);
	if (wyn==inf)
		wyn=-1;
	printf("%lld\n", wyn);
	return 0;
}