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
const int nax=10*1000*1007;
const int vax=50*1007;

int n, q;

set<ll> ciecie;

char wcz[100];

int typ[vax];
pll prz[vax];

int r;
vll wek;

vi oj;
vector<bool> dead;

//~ int oj[nax];
//~ int dead[nax];
int ans[vax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	//~ if (fin(a)!=fin(b))
		//~ debug() << "lacze " << a << " " << b;
	oj[fin(a)]=fin(b);
}

int znajdz(ll v)
{
	return upper_bound(wek.begin(), wek.end(), v)-wek.begin()-1;
}

void tnij(ll a, ll b, int poz=-2)
{
	if (poz==-2)
		poz=n-1;
	ll szi=(1LL<<poz);
	if ((b&szi)!=(a&szi))
	{
		ll pocz=(b&(b^(szi-1)));
		ciecie.insert(pocz);
		tnij(a, pocz-1, poz);
		tnij(pocz, b, poz);
		return;
	}
	if (a+szi-1==b)
		return;
	tnij(a, b, poz-1);
}

//~ set<pll> zywe;

//~ vi graf[nax];
vector<vi> graf;

void probuj(int a, int b, ll hint)
{
	pll pa={wek[a], wek[a+1]-1};
	pa.first^=hint;
	pa.second^=hint;
	pll pb={wek[b], wek[b+1]-1};
	if (pa.second<pb.first || pa.first>pb.second)
		return;
	uni(a, b);
}

void polacz(int v, ll a, ll b)
{
	/*ll szi=b+1-a;
	//~ debug() << "jade " << v << " " << a << " " << b << "    " << szi;
	while(szi<(1LL<<n))
	{
		ll lew=(a^szi);
		ll pra=(b^szi);
		auto it=zywe.upper_bound({lew, 1e9});
		it--;
		while(it!=zywe.end() && (*it).first<=pra)
		{
			//~ int x=znajdz(*it);
			int x=(*it).second;
			probuj(v, x, szi);
			//~ uni(v, znajdz(*it));
			it++;
		}
		szi<<=1;
	}*/
	for (int i : graf[v])
		if (!dead[i])
			uni(v, i);
}

void edge(int a, int b)
{
	graf[a].push_back(b);
	graf[b].push_back(a);
}

void buduj(ll a, ll b)
{
	if (a+1==b)
		return;
	ll s=(a+b)>>1;
	if (!ciecie.count(s))
		return;
	int sx=znajdz(a);
	int sy=znajdz(s);
	int kon=znajdz(b);
	int x=sx;
	int y=sy;
	while(x<sy && y<kon)
	{
		edge(x, y);
		if (wek[x+1]+(s-a)==wek[y+1])
		{
			x++;
			y++;
		}
		else
		{
			if (wek[x+1]+(s-a)<wek[y+1])
				x++;
			else
				y++;
		}
	}
	buduj(a, s);
	buduj(s, b);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=q; i++)
	{
		ll a, b;
		scanf("%s %lld%lld", wcz, &a, &b);
		prz[i]={a, b};
		if (wcz[0]=='b')
		{
			typ[i]=0;
			ciecie.insert(a);
			ciecie.insert(b+1);
		}
		else
		{
			typ[i]=1;
			ciecie.insert(a);
			ciecie.insert(a+1);
			ciecie.insert(b);
			ciecie.insert(b+1);
		}
	}
	ciecie.insert(0);
	ciecie.insert(1LL<<n);
	vll kop;
	for (ll i : ciecie)
		kop.push_back(i);
	for (int i=0; i+1<(int)kop.size(); i++)
		tnij(kop[i], kop[i+1]-1);
	debug() << imie(ciecie.size());
	//~ return 0;
	r=ciecie.size()-1;
	graf.resize(r);
	oj.resize(r);
	dead.resize(r);
	for (ll i : ciecie)
		wek.push_back(i);
	for (int i=0; i<r; i++)
		oj[i]=i;
	buduj(0, (1LL<<n));
	//~ debug() << wek;
	for (int i=1; i<=q; i++)
	{
		if (typ[i])
			continue;
		int x=znajdz(prz[i].first);
		while(wek[x]<=prz[i].second)
		{
			dead[x]=1;
			x++;
		}
	}
	//~ debug() << range(dead, dead+r);
	for (int i=0; i<r; i++)
	{
		if (!dead[i])
		{
			//~ debug() << "norm " << i;
			//~ zywe.insert({wek[i], i});
			polacz(i, wek[i], wek[i+1]-1);
		}
	}
	debug() << "po";
	for (int i=q; i; i--)
	{
		if (typ[i])
		{
			ans[i]=(fin(znajdz(prz[i].first))==fin(znajdz(prz[i].second)));
			continue;
		}
		else
		{
			int x=znajdz(prz[i].first);
			while(wek[x]<=prz[i].second)
			{
				dead[x]=0;
				//~ debug() << "super";
				polacz(x, wek[x], wek[x+1]-1);
				//~ zywe.insert({wek[x], x});
				x++;
			}
		}
	}
	
	
	for (int i=1; i<=q; i++)
		if (typ[i])
			printf("%d\n", ans[i]);
	return 0;
}