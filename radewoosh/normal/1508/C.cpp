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

int n, m;

vector<pair<int,ll>> graf[nax];

ll xo;

pii kra[nax];
ll wag[nax];

set<int> nieo;

int k;
int spo[nax];

set<pii> akra;

int oj[nax];

ll wyn;

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

void dfs1(int v)
{
	spo[v]=k;
	vi ter;
	for (int i : nieo)
		if (!akra.count({v, i}))
			ter.push_back(i);
	for (int i : ter)
		nieo.erase(i);
	//~ debug() << v << " " << ter;
	for (int i : ter)
	{
		uni(v, i);
		dfs1(i);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d%lld", &a, &b, &wag[i]);
		xo^=wag[i];
		kra[i]={a, b};
		graf[a].push_back({b, wag[i]});
		graf[b].push_back({a, wag[i]});
		akra.insert({a, b});
		akra.insert({b, a});
	}
	for (int i=1; i<=n; i++)
		nieo.insert(i);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=n; i++)
	{
		if (!nieo.count(i))
			continue;
		k++;
		nieo.erase(i);
		dfs1(i);
	}
	//~ debug() << range(spo+1, spo+1+n);
	
	vector<pair<ll,pii>>wek;
	for (int i=1; i<=m; i++)
		wek.push_back({wag[i], kra[i]});
	sort(wek.begin(), wek.end());
	vll nie;
	vector<pii> fakt;
	for (auto i : wek)
	{
		ll w=i.first;
		int a=i.second.first;
		int b=i.second.second;
		if (fin(a)!=fin(b))
		{
			wyn+=w;
			uni(a, b);
			fakt.push_back({a, b});
		}
		else
		{
			//~ nie.push_back(w);
		}
	}
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (pii i : fakt)
		uni(i.first, i.second);
	for (auto i : wek)
	{
		ll w=i.first;
		int a=i.second.first;
		int b=i.second.second;
		if (fin(a)!=fin(b))
		{
			nie.push_back(w);
		}
		else
		{
			//~ nie.push_back(w);
		}
	}
	ll wsz=n*(n-1LL)/2;
	ll pus=wsz-m;
	//~ debug() << imie(wsz) << imie(pus) << imie(k) << imie(n-pus) << imie(xo) << imie(wyn);
	sort(nie.begin(), nie.end());
	if (n-pus==k)
	{
		if (nie.empty())
			wyn+=xo;
		else
			wyn+=min(xo, nie[0]);
	}
	else
	{
		
	}
	
	printf("%lld\n", wyn);
	//~ debug() << range(spo+1, spo+1+n);
	return 0;
}