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
const int nax=107;
const ll lim=1e15;
const int d=50;

ll n;

int najw(ll v)
{
	if (!v)
		return 0;
	return 64-__builtin_clzll(v);
}

unordered_set<ll> setel[nax];
vll wek[nax];

int znam(ll v)
{
	int g=najw(v);
	return setel[g].count(v);
}

vector<pair<int,pll>> wyn;

void poznaj(ll x)
{
	setel[najw(x)].insert(x);
	wek[najw(x)].push_back(x);
}

void dodaj(ll a, ll b)
{
	wyn.push_back({0, {a, b}});
	poznaj(a+b);
}

void xoruj(ll a, ll b)
{
	wyn.push_back({1, {a, b}});
	poznaj(a^b);
}

ll los()
{
	return rand()*1000000LL+rand();
}

int los(int a, int b)
{
	return a+los()%(b-a+1);
}

ll wylosuj(int v)
{
	if (wek[v].empty())
		return -1;
	int r=wek[v].size();
	return wek[v][los(0, r-1)];
}

void randomowo()
{
	int jeszcze=40*1000;
	while(jeszcze)
	{
		int a=los(1, d);
		int b=los(1, d);
		ll x=wylosuj(a);
		ll y=wylosuj(b);
		if (x<0 || y<0)
			continue;
		if (los(0, 1))
		{
			if (x+y<=lim && !znam(x+y))
			{
				dodaj(x, y);
				jeszcze--;
			}
		}
		else
		{
			if ((x^y)<=lim && !znam(x^y))
			{
				xoruj(x, y);
				jeszcze--;
			}
		}
	}
}

void losowe(int v)
{
	if (wek[v].empty())
		return;
	int jeszcze=1000;
	int supjeszcze=1000*30;
	while(jeszcze>0 && supjeszcze>0)
	{
		supjeszcze--;
		ll x=wylosuj(v);
		ll y=wylosuj(v);
		if ((x^y)<=lim && !znam(x^y))
		{
			xoruj(x, y);
			jeszcze--;
		}
	}
}

int main()
{
	scanf("%lld", &n);
	poznaj(n);
	randomowo();
	for (int i=d; i; i--)
		losowe(i);
	
	//~ for (int i=0; i<=d; i++)
		//~ debug() << imie(i) << imie(wek[i].size());
	
	assert(!wek[1].empty());
	
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
		printf("%lld %c %lld\n", i.second.first, "+^"[i.first], i.second.second);
	return 0;
}