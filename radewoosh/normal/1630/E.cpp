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
const int nax=1000*1007;
const ll inf=1e18;
const ll mod=998244353;

int n;
int tab[nax];
int ile[nax];
int liczno[nax];

int wych[nax];

vector<pii> wek;

ll wyn;

ll sil[nax];
ll odw[nax];

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

ll jedna(int v)
{
	return odw[v]*sil[v-1]%mod;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		ile[i]=0;
		liczno[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		ile[tab[i]]++;
	}
	{
		int row=1;
		for (int i=2; i<=n; i++)
			if (tab[i]!=tab[i-1])
				row=0;
		if (row)
		{
			printf("1\n");
			return;
		}
	}
	for (int i=1; i<=n; i++)
		if (ile[i])
			liczno[ile[i]]++;
	int g=0;
	wek.clear();
	for (int i=1; i<=n; i++)
		if (liczno[i])
			wek.push_back({i, liczno[i]});
	//~ debug() << wek;
	for (pii i : wek)
		g=__gcd(g, i.first);
	//~ debug() << imie(g);
	for (int i=1; i<=n; i++)
		wych[i]=0;
	for (int i=1; i<=n; i++)
		wych[__gcd(i, n)]++;
	//~ debug() << range(wych+1, wych+1+n);
	wyn=0;
	ll wsz=0;
	for (int i=1; i<=n; i++)
	{
		if (!wych[i])
			continue;
		int dz=n/i;
		if (g%dz)
			continue;
		//~ debug() << "robie " << i << " " << dz;
		//~ for ()
		ll per=sil[n/dz];
		for (pii j : wek)
			per=(per*pot(odw[j.first/dz], j.second))%mod;
		//~ debug() << imie(per);
		wsz=(wsz+per*wych[i])%mod;
		for (pii j : wek)
		{
			ll szan=(j.first/dz-1)*jedna(n/dz-1)%mod;
			wyn=(wyn+per*szan%mod*wych[i]%mod*dz%mod*j.second%mod*(j.first/dz))%mod;
		}
	}
	//~ debug() << imie(wsz) << " " << imie(wyn);
	//~ wyn%=mod;
	//~ wyn+=mod;
	//~ wyn%=mod;
	//~ wyn*=inv(n);
	//~ wyn%=mod;
	wyn=n-wyn*inv(wsz);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[nax-1]=inv(sil[nax-1]);
	for (int i=nax-1; i; i--)
		odw[i-1]=(odw[i]*i)%mod;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}