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
const int nax=200*1007;
const ll mod=998244353;
const int d=20;

int n, m;

vi graf[nax][2];

ll waga(pll v)
{
	return v.first+(1LL<<v.second)-1;
}

vector<pll> wyn;

int bylo[nax];
int norodl[nax];

int juz[nax][2];

pll comp(pll a, pll b)
{
	if (a.second==b.second || a.first==b.first)
		return min(a, b);
	if (a.second<d && b.second<d)
	{
		if (waga(a)<waga(b))
			return a;
		return b;
	}
	if (a.second<b.second)
		return a;
	return b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a][0].push_back(b);
		graf[b][1].push_back(a);
	}
	{
		priority_queue<pair<pll,pii>>kol;
		kol.push({{0, 0}, {1, 0}});
		while(!kol.empty())
		{
			pll dys=kol.top().first;
			dys={-dys.second, -dys.first};
			int v=kol.top().second.first;
			int typ=kol.top().second.second;
			kol.pop();
			if (juz[v][typ])
				continue;
			juz[v][typ]=1;
			if (v==n)
			{
				wyn.push_back(dys);
				break;
			}
			for (int i : graf[v][typ])
				kol.push({{-dys.second, -(dys.first+1)}, {i, typ}});
			kol.push({{-(dys.second+1), -(dys.first)}, {v, typ^1}});
		}
	}
	
	
	for (int i=1; i<=n; i++)
	{
		norodl[i]=0;
		bylo[i]=0;
	}
	
	bylo[1]=1;
	for (int h=0; h<=d; h++)
	{
		priority_queue<pii> kol;
		for (int i=1; i<=n; i++)
			if (bylo[i])
			{
				kol.push({-norodl[i], i});
				bylo[i]=0;
			}
		while(!kol.empty())
		{
			int v=kol.top().second;
			int dis=-kol.top().first;
			kol.pop();
			if (bylo[v])
				continue;
			bylo[v]=1;
			norodl[v]=dis;
			for (int i : graf[v][h&1])
				kol.push({-(dis+1), i});
		}
		if (bylo[n])
			wyn.push_back({norodl[n], h});
	}
	
	
	debug() << wyn;
	
	for (int i=0; i<(int)wyn.size(); i++)
		wyn[0]=comp(wyn[0], wyn[i]);
	ll x=1;
	for (int i=1; i<=wyn[0].second; i++)
		x=(x*2)%mod;
	x+=mod-1;
	x+=wyn[0].first;
	x%=mod;
	printf("%lld\n", x);
	return 0;
}