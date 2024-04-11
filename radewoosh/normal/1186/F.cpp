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
const int nax=2000*1007;

int n, m;

vector <pii> graf[nax];

int bylo[nax];

int juz[nax];

void oznacz(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (pii i : graf[v])
		oznacz(i.first);
}

vi kol;

void dfs(int v)
{
	while(!graf[v].empty())
	{
		int u=graf[v].back().first;
		int x=graf[v].back().second;
		graf[v].pop_back();
		if (juz[x])
			continue;
		juz[x]=1;
		dfs(u);
	}
	kol.push_back(v);
}

int tak[nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	for (int i=1; i<=n; i++)
	{
		if (graf[i].size()&1)
		{
			graf[0].push_back({i, m+i});
			graf[i].push_back({0, m+i});
			oznacz(i);
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (!bylo[i])
		{
			if (graf[i].empty())
				continue;
			int x=graf[i][0].first;
			graf[0].push_back({i, m+i});
			graf[i].push_back({0, m+i});
			graf[0].push_back({x, m+x});
			graf[x].push_back({0, m+x});
			oznacz(i);
		}
	}
	dfs(0);
	vector <pii> wyn;
	int k=kol.size();
	int p=0;
	for (int i=0; i<k; i++)
	{
		if (!kol[i])
		{
			p=0;
			if (i>=2)
				tak[i-2]=1;
		}
		else
		{
			p^=1;
			if (kol[i+1])
				tak[i]=p;
		}
	}
	for (int i=0; i<k; i++)
		if (tak[i])
			wyn.push_back({kol[i], kol[i+1]});
	debug() << kol;
	
	
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}