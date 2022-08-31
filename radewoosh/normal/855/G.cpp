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
const int nax=100*1007;

int n;
vector <int> graf[nax];

int repr[nax];
int gor[nax];
int roz[nax];
vector <pii> som[nax];
vi nal[nax];
ll sk[nax];

int odl[nax];

ll wyn;

ll kwa(ll v)
{
	return v*v;
}

int poj[nax];

int dfs1(int v, int oj)
{
	poj[v]=oj;
	roz[v]=1;
	repr[v]=v;
	gor[v]=v;
	nal[v].push_back(v);
	int ret=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		odl[i]=odl[v]+1;
		int w=dfs1(i, v);
		ret+=w;
		som[v].push_back({i, w});
	}
	if (oj)
		som[v].push_back({oj, n-ret});
	wyn+=kwa(n-1);
	for (pii i : som[v])
	{
		sk[v]+=kwa(i.second);
		wyn-=kwa(i.second);
	}
	return ret;
}

ll wielo(ll v)
{
	return v*(v-1)*(n-v)*2+v*(v-1)*(v-2);
}

void uni(int a, int b)
{
	if (roz[a]>roz[b])
		swap(a, b);
	wyn-=wielo(roz[a]);
	wyn-=wielo(roz[b]);
	wyn+=wielo(roz[a]+roz[b]);
	wyn-=roz[a]*kwa(n-roz[a]);
	wyn-=roz[b]*kwa(n-roz[b]);
	wyn+=(roz[a]+roz[b])*kwa(n-roz[a]-roz[b]);
	wyn+=roz[a]*sk[a]+roz[b]*sk[b];
	for (pii i : som[a])
	{
		if (repr[i.first]==b)
		{
			int rb=i.second;
			int ra=n-i.second;
			sk[b]=sk[a]-kwa(rb)+sk[b]-kwa(ra);
			wyn-=(roz[a]+roz[b])*sk[b];
			continue;
		}
		som[b].push_back(i);
	}
	nal[b].resize(roz[a]+roz[b]);
	int num=roz[b];
	for (int i : nal[a])
	{
		repr[i]=b;
		//~ nal[b].push_back(i);
		nal[b][num]=i;
		num++;
	}
	nal[a].clear();
	if (odl[gor[a]]<odl[gor[b]])
		gor[b]=gor[a];
	roz[b]+=roz[a];
}

void lacz(int a, int b)
{
	while(repr[a]!=repr[b])
	{
		a=repr[a];
		b=repr[b];
		if (odl[gor[a]]<odl[gor[b]])
			swap(a, b);
		uni(a, repr[poj[gor[a]]]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	odl[1]=1;
	dfs1(1, 0);
	printf("%lld\n", wyn);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		lacz(a, b);
		printf("%lld\n", wyn);
	}
	return 0;
}