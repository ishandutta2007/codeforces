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
const int nax=1200*1007;
const int n1=(1<<19);
const int inf=1e9;

int n;
ll d;

pll tab[nax];

int zas[nax];

int pref[nax];

vi kon[nax];

bool mniej(pll a, pll b)
{
	swap(a.first, a.second);
	swap(b.first, b.second);
	return a<b;
}

int narz[nax];
int pod[nax];

int daj(int v)
{
	return narz[v]+pod[v];
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (v==1)
	{
		graa++;
		grab++;
	}
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
	{
		return -inf;
	}
	return max(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	)+narz[v];
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (v==1)
	{
		graa++;
		grab++;
	}
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	pod[v]=max(daj(2*v), daj(2*v+1));
}

int main()
{
	scanf("%d%lld", &n, &d);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
		tab[i].first-=d;
		tab[i].second-=d;
		if (tab[i].first<0)
		{
			i--;
			n--;
		}
	}
	if (!n)
	{
		printf("0\n");
		return 0;
	}
	sort(tab+1, tab+1+n, mniej);
	//~ for (int i=1; i<=n; i++)
		//~ debug() << tab[i];
	for (int i=1; i<=n; i++)
	{
		int bsa=i;
		int bsb=n;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb+2)>>1;
			if (tab[bss].second<=tab[i].first)
				bsa=bss;
			else
				bsb=bss-1;
		}
		zas[i]=bsa;
		kon[zas[i]].push_back(i);
	}
	//~ debug() << range(zas+1, zas+1+n);
	for (int i=1; i<=n; i++)
	{
		int bsa=0;
		int bsb=i-1;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb+2)>>1;
			if (tab[bss].second<=tab[i].first)
				bsa=bss;
			else
				bsb=bss-1;
		}
		pref[i]=bsa;
	}
	//~ debug() << range(pref+1, pref+1+n);
	int wyn=0;
	for (int i=1; i<=n; i++)
	{
		pisz(1, 1, n1, 0, i-1, 1);
		int x=czyt(1, 1, n1, 0, pref[i]);
		pisz(1, 1, n1, i, i, x);
		wyn=max(wyn, x);
		for (int j : kon[i])
			pisz(1, 1, n1, 0, j-1, -1);
	}
	printf("%d\n", wyn);
	return 0;
}