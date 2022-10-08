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
const int nax=1007*1007;

void nope()
{
	printf("NO\n");
	exit(0);
}

void nom()
{
	printf("YES\n");
}

vector<pii> dajdp(int v)
{
	if (v==9)
		return vector<pii>{pii{1, 1}, pii{3, 3}};
	if (v==1 || v==3)
		return vector<pii>{pii{0, 0}};
	int b=(v-3)/2;
	if (!(v&(v+1)))
		return vector<pii>{pii{0, 0}, pii{2, b}};
	return vector<pii>{pii{1, b}};
}

int wyn[nax];

int m;

int nast()
{
	m++;
	return m;
}

ll myrand()
{
	return ((ll)rand())*10000LL+rand();
}

int los(int a, int b)
{
	return a+myrand()%(b-a+1);
}

int doda(int a, int b)
{
	return (a>=2*b || b>=2*a);
}

vector<pii> przesun(vector<pii> wek, int v)
{
	for (pii &i : wek)
	{
		i.first+=v;
		i.second+=v;
	}
	return wek;
}

vector<pii> suma(vector<pii> a, vector<pii> b)
{
	vector<pii> ret;
	for (pii i : a)
		for (pii j : b)
			ret.push_back({i.first+j.first, i.second+j.second});
	return ret;
}

int jest(vector<pii> wek, int v)
{
	for (pii i : wek)
		if (i.first<=v && i.second>=v)
			return 1;
	return 0;
}

pii gdz(vector<pii> wek, int v)
{
	for (pii i : wek)
		if (i.first<=v && i.second>=v)
			return i;
	assert(0);
}

pii rozdziel(pii a, pii b, int x)
{
	x-=a.first+b.first;
	pii ret{a.first, b.first};
	int y=min(a.second-a.first, x);
	ret.first+=y;
	x-=y;
	y=min(b.second-b.first, x);
	ret.second+=y;
	x-=y;
	assert(!x);
	return ret;
}

int zrob(int n, int k)
{
	int v=nast();
	if (n==1)
		return v;
	for (int h=1; 1; h++)
	{
		int lew;
		
		if (h<=20 && ((1<<h)-1)<n)
			lew=(1<<h)-1;
		else
			lew=los(1, n-1);
		if (!(lew&1))
			continue;
		int pra=n-1-lew;
		auto zlew=dajdp(lew);
		auto zpra=dajdp(pra);
		int dod=doda(lew, pra);
		if (!jest(przesun(suma(zlew, zpra), dod), k))
			continue;
		pii wez;
		for (pii i : zlew)
			for (pii j : zpra)
				if (i.first+j.first+dod<=k && k<=i.second+j.second+dod)
					wez=rozdziel(i, j, k-dod);
		int raz=zrob(lew, wez.first);
		int dwa=zrob(pra, wez.second);
		wyn[raz]=wyn[dwa]=v;
		return v;
	}
}

int main()
{
	srand(time(0));
	int n, k;
	scanf("%d%d", &n, &k);
	if (!(n&1) || !jest(dajdp(n), k))
		nope();
	nom();
	zrob(n, k);
	
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}