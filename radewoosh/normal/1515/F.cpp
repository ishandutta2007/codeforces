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

void nope()
{
	printf("NO\n");
	exit(0);
}

int n, m;
ll potrz;

ll tab[nax];
pii dro[nax];

vector<pii> graf[nax];

vi wyn;

int oj[nax];

int lacz;

priority_queue<pll> kol[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

void dfs1(int v, int o)
{
	for (pii &i : graf[v])
	{
		if (i.first==o)
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	for (pii i : graf[v])
		dfs1(i.first, v);
}

pll dfs2(int v, int czym)
{
	for (pii i : graf[v])
	{
		kol[czym].push(dfs2(i.first, i.second));
		//~ if ((int)kol[i.second].size()>(int)kol[czym].size())
			//~ kol[czym].swap(kol[i.second]);
		//~ for (pii i : kol[i.second])
			//~ kol[czym].push_back(i);
		//~ kol[i.second]={};
	}
	ll mam=tab[v];
	while(!kol[czym].empty() && kol[czym].top().first+mam>=potrz)
	{
		pll wez=kol[czym].top();
		kol[czym].pop();
		wyn.push_back(wez.second);
		int x=wez.second;
		mam=mam+wez.first-potrz;
		if ((int)kol[x].size()>(int)kol[czym].size())
			kol[czym].swap(kol[x]);
		while(!kol[x].empty())
		{
			kol[czym].push(kol[x].top());
			kol[x].pop();
		}
		kol[x]={};
	}
	return {mam, czym};
}

int main()
{
	scanf("%d%d%lld", &n, &m, &potrz);
	ll s=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		oj[i]=i;
		s+=tab[i];
	}
	if (s<(n-1)*potrz)
		nope();
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (fin(a)==fin(b))
			continue;
		uni(a, b);
		dro[i]={a, b};
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	for (int i=1; i<=n; i++)
		oj[i]=i;
	dfs1(1, 0);
	dfs2(1, 0);
	
	printf("YES\n");
	for (int i : wyn)
		printf("%d\n", i);
	return 0;
}