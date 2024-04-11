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

int n;
vi graf[nax];

int wyn[nax];

int dol[nax];
int gor[nax];

vector <pii> odl[nax];

void cons(int v, int w)
{
	wyn[v]=max(wyn[v], w);
}

void dfs1(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
		dol[v]=max(dol[v], dol[i]);
	}
	dol[v]++;
}

void dfs2(int v, int oj)
{
	gor[v]++;
	vector <pii> wek;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		wek.push_back({dol[i]+1, i});
	}
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		for (pii j : wek)
		{
			if (j.second==i)
				continue;
			gor[i]=j.first;
			break;
		}
		gor[i]=max(gor[i], gor[v]);
		dfs2(i, v);
	}
	
	if (oj)
		odl[v].push_back({gor[v]-1, oj});
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		odl[v].push_back({dol[i], i});
	}
	sort(odl[v].begin(), odl[v].end());
	reverse(odl[v].begin(), odl[v].end());
}

map <pii,int> kt;

vi inter[nax];

int wierow(int v, int x)
{
	int bsa=0;
	int bsb=(int)graf[v].size();
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (odl[v][bss-1].first>=x)
			bsa=bss;
		else
			bsb=bss-1;
	}
	return bsa;
}

void solve(int a, int b)
{
	int onma=kt[{b, a}];
	int jamam=kt[{a, b}];
	//~ for (int i=0; i<(int)odl[a].size(); i++)
	for (int i : inter[a])
	{
		if (odl[a][i].second==b)
			continue;
		int w=wierow(b, odl[a][i].first);
		if (onma>=odl[a][i].first)
			w--;
		int tu=i+1;
		if (jamam>=odl[a][i].first)
			tu--;
		int jest=tu+w;
		cons(2*odl[a][i].first, jest);
	}
}

void algo()
{
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)odl[i].size(); j++)
		{
			cons(2*odl[i][j].first, j+1);
			cons(2*odl[i][j].first-1, j+1);
		}
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)odl[i].size(); j++)
			if (j>0 && odl[i][j-1].first>odl[i][j].first)
				cons(2*odl[i][j].first+1, j+1);
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)odl[i].size(); j++)
			kt[{i, odl[i][j].second}]=odl[i][j].first;
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)odl[i].size(); j++)
			if (j+1==(int)odl[i].size() || odl[i][j].first!=odl[i][j+1].first)
				inter[i].push_back(j);
	for (int i=1; i<=n; i++)
		for (int j : graf[i])
				solve(i, j);
	wyn[1]=0;
	for (int i=1; i<=n; i++)
		cons(1, graf[i].size()+1);
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
	dfs1(1, 0);
	dfs2(1, 0);
	int naj=0;
	for (int i=1; i<=n; i++)
		naj=max(naj, max(gor[i], dol[i])-1);
	for (int i=1; i<=n; i++)
		cons(i, 1);
	for (int i=1; i<=naj; i++)
		cons(i, 2);
	
	//~ debug() << range(dol+1, dol+1+n);
	//~ debug() << range(gor+1, gor+1+n);
	
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << odl[i];
	
	algo();
	
	for (int i=n-2; i>1; i--)
		cons(i, wyn[i+2]);
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}