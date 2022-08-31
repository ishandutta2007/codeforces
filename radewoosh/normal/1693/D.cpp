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

int n;

int tab[nax];

int nastwie[nax];
int nastmie[nax];

ll wyn;

int dolny[nax];
int nd[nax];
int ng[nax];

int pd[nax];
int pg[nax];

int spokdal[nax];

int lecimy[nax];

map<pii,int> mapa;

int dive(int d, int g)
{
	if (mapa.count({d, g}))
		return mapa[{d, g}];
	int x=max(d, g);
	if (x==n)
		return mapa[{d, g}]=n;
	x++;
	if (tab[x]>tab[d])
		return mapa[{d, g}]=dive(x, g);
	if (tab[x]<tab[g])
		return mapa[{d, g}]=dive(d, x);
	return mapa[{d, g}]=x-1;
}

int check(int a, int b)
{
	if (spokdal[a]>=b)
		return 1;
	int x=spokdal[a];
	int g=pg[x];
	int d=pd[x];
	assert(g && d);
	return dive(d, g)>=b;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
		//~ tab[i]=i;
	//~ {
		//~ if (i&1)
			//~ tab[i]=(i+1)/2;
		//~ else
			//~ tab[i]=n-(i-1)/2;
	//~ }
	//~ shandom_ruffle(tab+1, tab+1+n);
	for (int i=n; i; i--)
	{
		nastwie[i]=nastmie[i]=i+1;
		while(nastwie[i]<=n && tab[nastwie[i]]<tab[i])
			nastwie[i]=nastwie[nastwie[i]];
		while(nastmie[i]<=n && tab[nastmie[i]]>tab[i])
			nastmie[i]=nastmie[nastmie[i]];
	}
	for (int i=1; i<n; i++)
	{
		if (tab[i+1]>tab[i])
			dolny[i]=1;
	}
	nd[n+1]=ng[n+1]=n+1;
	for (int i=n; i; i--)
	{
		nd[i]=nd[i+1];
		ng[i]=ng[i+1];
		if (dolny[i])
			nd[i]=i;
		else
			ng[i]=i;
	}
	for (int i=1; i<=n; i++)
	{
		pd[i]=pd[i-1];
		pg[i]=pg[i-1];
		if (dolny[i])
			pd[i]=i;
		else
			pg[i]=i;
	}
	spokdal[n+1]=n;
	for (int i=n; i; i--)
	{
		spokdal[i]=spokdal[i+1];
		if (dolny[i])
		{
			int x=nd[i+1];
			if (x<=n && tab[x]<tab[i])
				spokdal[i]=min(spokdal[i], x-1);
		}
		else
		{
			int x=ng[i+1];
			if (x<=n && tab[x]>tab[i])
				spokdal[i]=min(spokdal[i], x-1);
		}
	}
	int w=n;
	ll wyn=0;
	for (int i=n; i; i--)
	{
		while(!check(i, w))
			w--;
		wyn+=w-i+1;
	}
	printf("%lld\n", wyn);
	//~ lecimy[n]=n;
	//~ for (int i=n-1; i; i--)
	//~ {
		//~ if (!pd[i] || !pg[i])
		//~ {
			//~ lecimy[i]=lecimy[i+1];
			//~ continue;
		//~ }
		//~ int d=pd[i];
		//~ int g=pg[i];
		//~ assert(d==i || g==i);
		//~ if (tab[i+1]>=tab[g])
		//~ {
			
		//~ }
	//~ }
	//~ debug() << range(spokdal+1, spokdal+1+n);
	//~ debug() << range(dolny+1, dolny+1+n);
	return 0;
}