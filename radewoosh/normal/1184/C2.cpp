//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int n1=(1<<23);

int n, r;

pii tab[nax];

int wyn;

int spod[n1*2];
int narz[n1*2];

int daj(int v)
{
	return spod[v]+narz[v];
}

void upd(int v)
{
	spod[v]=max(daj(2*v), daj(2*v+1));
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
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
	upd(v);
}

int main()
{
	scanf("%d%d", &n, &r);
	//~ r*=4;
	r*=2;
	int naj=n1;
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		tab[i]={x+y, x-y};
		naj=min(naj, tab[i].second);
	}
	naj=-naj+1;
	for (int i=1; i<=n; i++)
		tab[i].second+=naj;
	debug() << range(tab+1, tab+1+n);
	vector <pii> eve;
	for (int i=1; i<=n; i++)
	{
		eve.push_back({tab[i].first, tab[i].second});
		eve.push_back({tab[i].first+r+1, -tab[i].second});
	}
	sort(eve.begin(), eve.end());
	for (pii i : eve)
	{
		if (i.second>0)
			pisz(1, 1, n1, i.second, i.second+r, 1);
		else
			pisz(1, 1, n1, -i.second, -i.second+r, -1);
		wyn=max(wyn, daj(1));
	}
	
	printf("%d\n", wyn);
	return 0;
}