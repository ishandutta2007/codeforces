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
int n1;

int n;

pair <int,ll> tab[nax];

ll wyn;

ll narz[nax];
ll pod[nax];

ll daj(int v)
{
	return pod[v]+narz[v];
}

void upd(int v)
{
	pod[v]=max(daj(2*v), daj(2*v+1));
}

void pisz(int v, int a, int b, int graa, int grab, ll w)
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

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d%lld", &tab[i].first, &tab[i].second);
	wyn=0;
	n1=1;
	while(n1<=n)
		n1<<=1;
	sort(tab+1, tab+1+n);
	vector <pair<ll,int> > wek;
	for (int i=1; i<=n; i++)
		wek.push_back({tab[i].second, i});
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	for (int i=1; i<2*n1; i++)
		narz[i]=pod[i]=0;
	pisz(1, 1, n1, 1, n, -(n-1));
	for (auto i : wek)
	{
		int x=i.second;
		pisz(1, 1, n1, x, x, tab[x].first);
		pisz(1, 1, n1, 1, x-1, 1);
		if (daj(1)<=0)
		{
			wyn+=i.first;
		}
		else
		{
			pisz(1, 1, n1, x, x, -tab[x].first);
			pisz(1, 1, n1, 1, x-1, -1);
		}
	}
	
	ll sum=0;
	for (int i=1; i<=n; i++)
		sum+=tab[i].second;
	printf("%lld\n", sum-wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}