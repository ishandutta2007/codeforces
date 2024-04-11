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
const int nax=4400*1007;

int n, m;

int taba[nax];
int tabb[nax];

ll wyn;

int fen[nax];
int k;
vector<pii> ska;

int n1;
int sta[nax];
pii drz[nax];

int pyt(int v)
{
	int ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=fen[i];
	return ret;
}

void oper(int v, int w)
{
	for (int i=v; i<=k; i+=(i&(-i)))
		fen[i]+=w;
}

pii scal(pii a, pii b)
{
	return {a.first+b.first, min(a.second, a.first+b.second)};
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		drz[v].first+=w;
		drz[v].second=min(drz[v].second, drz[v].first);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	drz[2*v]=scal(drz[2*v], drz[v]);
	drz[2*v+1]=scal(drz[2*v+1], drz[v]);
	drz[v]={0, 0};
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &taba[i]);
	for (int i=1; i<=m; i++)
		scanf("%d", &tabb[i]);
	k=0;
	ska.clear();
	for (int i=1; i<=n; i++)
		ska.push_back({taba[i], i});
	for (int i=1; i<=m; i++)
		ska.push_back({tabb[i], -i});
	sort(ska.begin(), ska.end());
	k=1;
	for (int i=1; i<(int)ska.size(); i++)
		if (ska[i].first!=ska[i-1].first)
			k++;
	int ter=1;
	for (int i=0; i<(int)ska.size(); i++)
	{
		if (i && ska[i].first!=ska[i-1].first)
			ter++;
		if (ska[i].second>0)
			taba[ska[i].second]=ter;
		else
			tabb[-ska[i].second]=ter;
	}
	for (int i=1; i<=k; i++)
		fen[i]=0;
	wyn=0;
	for (int i=1; i<=n; i++)
	{
		wyn+=pyt(taba[i]);
		oper(1, 1);
		oper(taba[i], -1);
	}
	for (int i=1; i<=k; i++)
		sta[i]=pyt(i);
	//~ debug() << range(sta+1, sta+1+k);
	n1=1;
	while(n1<=k)
		n1<<=1;
	for (int i=1; i<2*n1; i++)
	{
		drz[i]={0, 0};
	}
	for (int i=n; i; i--)
	{
		pisz(1, 1, n1, 1, taba[i]-1, -1);
		pisz(1, 1, n1, taba[i]+1, k, 1);
	}
	for (int i=1; i<=k; i++)
	{
		pisz(1, 1, n1, i, i, 0);
		sta[i]+=drz[n1-1+i].second;
	}
	for (int i=1; i<=m; i++)
		wyn+=sta[tabb[i]];
	//~ debug() << range(sta+1, sta+1+k);
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}