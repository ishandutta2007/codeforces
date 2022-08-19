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
const ll inf=1e12;

int n;

vector<pair<pll,pll>> sci;
vector<pll> ver;

int k;
vi drz[nax];
ll gle[nax];
pll ory[nax];

int pocz[nax];
int kon[nax];

map<pll,int> mapa;

ll gl(pll v)
{
	return v.first+v.second;
}

ll f(ll v)
{
	if (!v)
		return inf;
	return v&(-v);
}

ll dopel(ll v)
{
	ll x=63-__builtin_clzll(v);
	return (1LL<<x)-1;
}

pll skocz(pll v, ll ile)
{
	if (!ile)
		return v;
	ll a=v.first;
	ll b=v.second;
	ll tni=dopel(ile);
	ll au=a&tni;
	ll bu=b&tni;
	{
		a^=au;
		b^=bu;
		ile-=au+bu;
		assert(ile>=0);
	}
	v={a, b};
	
	while(ile)
	{
		if (!v.first)
			return {0LL, v.second-ile};
		if (!v.second)
			return {v.first-ile, 0LL};
		const ll a=(v.first&(-v.first));
		const ll b=(v.second&(-v.second));
		if (a<b)
		{
			ll x=min(a, ile);
			v.first-=x;
			ile-=x;
		}
		else
		{
			ll x=min(b, ile);
			v.second-=x;
			ile-=x;
		}
	}
	return v;
}

bool mniej_pre(pll a, pll b)
{
	if (a==b)
		return false;
	ll ga=gl(a);
	ll gb=gl(b);
	if (ga==gb)
		return a<b;
	if (ga>gb)
	{
		a=skocz(a, ga-gb);
		if (a<b)
			return true;
		return false;
	}
	else
	{
		b=skocz(b, gb-ga);
		if (a<=b)
			return true;
		return false;
	}
}

bool przodek(pll gora, pll dol)
{
	ll gg=gl(gora);
	ll gd=gl(dol);
	if (gd<gg)
		return false;
	return skocz(dol, gd-gg)==gora;
}

pll lca(pll a, pll b)
{
	ll ga=gl(a);
	ll gb=gl(b);
	if (ga>gb)
	{
		a=skocz(a, ga-gb);
		ga=gb;
	}
	if (gb>ga)
	{
		b=skocz(b, gb-ga);
		gb=ga;
	}
	if (a==b)
		return a;
	ll bsa=0;
	ll bsb=ga;
	//~ for (ll i=31; i>=0; i--)
	//~ {
		//~ if ((1LL<<i)>ga)
			//~ continue;
		//~ pll pa=skocz(a, (1LL<<i));
		//~ pll pb=skocz(b, (1LL<<i));
		//~ if (pa!=pb)
		//~ {
			//~ a=pa;
			//~ b=pb;
			//~ ga-=(1LL<<i);
		//~ }
		
	//~ }
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb)>>1;
		if (skocz(a, bss)==skocz(b, bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	return skocz(a, bsa);
}

set<ll> zmiana;

void flip(ll v)
{
	if (zmiana.count(v))
		zmiana.erase(v);
	else
		zmiana.insert(v);
}

void oznacz(ll a, ll b)
{
	flip(b);
	if (a)
		flip(a-1);
}

int dfs1(int v, ll goj)
{
	int ret=pocz[v]-kon[v];
	for (int i : drz[v])
		ret+=dfs1(i, gle[v]);
	if (ret)
	{
		//~ dlugi.push_back({goj+1, gle[v]});
		oznacz(goj+1, gle[v]);
	}
	else
	{
		if (kon[v])
		{
			//~ dlugi.push_back({gle[v], gle[v]});
			
			oznacz(gle[v], gle[v]);
		}
	}
	return ret;
}

int main()
{
	//~ pll a={0, 1};
	//~ pll b={1, 0};
	//~ debug() << imie(przodek(a, b));
	//~ debug() << imie(przodek(b, a));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		pll x={a, b};
		pll y={c, d};
		pll z=lca(x, y);
		sci.push_back({x, z});
		sci.push_back({y, z});
		ver.push_back(x);
		ver.push_back(y);
		ver.push_back(z);
		//~ debug() << imie(x) << imie(y) << imie(z);
	}
	debug() << imie(ver.size());
	ver.push_back(make_pair(0LL, 0LL));
	sort(ver.begin(), ver.end(), mniej_pre);
	ver.resize(unique(ver.begin(), ver.end())-ver.begin());
	debug() << imie(ver.size());
	for (int i=(int)ver.size()-1; i>=1; i--)
	{
		pll x=lca(ver[i], ver[i-1]);
		ver.push_back(x);
	}
	sort(ver.begin(), ver.end(), mniej_pre);
	ver.resize(unique(ver.begin(), ver.end())-ver.begin());
	//~ debug() << ver;
	debug() << imie(ver.size());
	//~ return 0;
	vi stos;
	for (pll i : ver)
	{
		ory[k]=i;
		gle[k]=gl(i);
		mapa[i]=k;
		if (!stos.empty())
		{
			while (!przodek(ory[stos.back()], i))
				stos.pop_back();
			drz[stos.back()].push_back(k);
		}
		stos.push_back(k);
		//~ debug() << "po " << k << " mamy " << stos;
		k++;
	}
	for (auto i : sci)
	{
		pocz[mapa[i.first]]++;
		kon[mapa[i.second]]++;
	}
	dfs1(0, -1);
	
	//~ debug() << zmiana;
	printf("%d\n", (int)zmiana.size());
	//~ debug() << imie(dlugi);
	//~ for (int i=0; i<k; i++)
		//~ debug() << i << " " << ory[i] << " " << drz[i];
	return 0;
}