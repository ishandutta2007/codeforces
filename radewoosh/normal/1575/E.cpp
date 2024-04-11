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
const ll mod=1000*1000*1000+7;
const ll o2=(mod+1)/2;

int n, k;

ll tab[nax];

vector<pii> graf[nax];

ll wyn;

vi spo;
int bylcen[nax];
int roz[nax];
int maxr[nax];

void dfs1(int v, int oj)
{
	spo.push_back(v);
	roz[v]=1;
	maxr[v]=0;
	for (pii i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		dfs1(i.first, v);
		roz[v]+=roz[i.first];
		maxr[v]=max(maxr[v], roz[i.first]);
	}
}

vector<pair<pii,ll>> glo;

void dfs2(int v, int oj, int pier, int ost, int zmia, ll sum)
{
	sum+=tab[v];
	glo.push_back({{pier, zmia}, sum});
	for (pii i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		dfs2(i.first, v, pier, i.second, zmia+(ost!=i.second), sum);
	}
}

vll sumpre[2];

ll daj(int v, int x)
{
	if (x<0)
		return 0;
	return sumpre[v][min(x, (int)sumpre[v].size()-1)];
}

pll trzachnij()
{
	sumpre[0]={0};
	sumpre[1]={0};
	for (auto i : glo)
	{
		int kol=i.first.first;
		int dlu=i.first.second;
		while((int)sumpre[kol].size()<=dlu)
			sumpre[kol].push_back(0);
		sumpre[kol][dlu]++;
	}
	for (int i=0; i<2; i++)
		for (int j=1; j<(int)sumpre[i].size(); j++)
			sumpre[i][j]+=sumpre[i][j-1];
	ll ret1=0;
	ll ret2=0;
	for (auto i : glo)
	{
		int kol=i.first.first;
		int dlu=i.first.second;
		ll wag=i.second;
		ll tu=0;
		for (int j=0; j<2; j++)
			tu+=daj(j, k-dlu-(j!=kol));
		ret1=(ret1+tu*wag)%mod;
		ret2=(ret2+tu)%mod;
		//~ debug() << i << " " << tu;
	}
	//~ debug() << glo;
	//~ debug() << ret1 << " " << ret2;
	
	//~ assert(!(ret2%2));
	//~ ret2/=2;
	return {ret1, ret2};
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs1(v, 0);
	int ss=spo.size();
	int c=-1;
	for (int i : spo)
		if (max(maxr[i], ss-roz[i])*2<=ss)
			c=i;
	assert(c>=0);
	glo.clear();
	for (pii i : graf[c])
	{
		if (bylcen[i.first])
			continue;
		dfs2(i.first, c, i.second, i.second, 0, 0);
	}
	for (auto i : glo)
		if (i.first.second<=k)
			wyn=(wyn+tab[c]+i.second)%mod;
	wyn=(wyn+tab[c])%mod;
	pll wez=trzachnij();
	//~ wyn=(wyn+wez.first+wez.second*tab[c])%mod;
	ll wa=0;
	ll wb=0;
	wa=(wa+wez.first)%mod;
	wb=(wb+wez.second)%mod;
	//~ debug() << c << "  " << wa << " " << wb;
	
	for (pii i : graf[c])
	{
		if (bylcen[i.first])
			continue;
		glo.clear();
		dfs2(i.first, c, i.second, i.second, 0, 0);
		pll wez=trzachnij();
		//~ wyn=(wyn-wez.first-wez.second*tab[c])%mod;
		wa=(wa-wez.first)%mod;
		wb=(wb-wez.second)%mod;
	}
	wa%=mod;
	wb%=mod;
	wb=(wb*o2)%mod;
	wyn=(wyn+wa+wb*tab[c])%mod;
	
	bylcen[c]=1;
	for (pii i : graf[c])
		szuk(i.first);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	szuk(1);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	
	printf("%lld\n", wyn);
	return 0;
}