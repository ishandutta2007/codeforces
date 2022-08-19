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

vector<pii> graf[nax];
int sto[nax];

pii kra[nax];

vi skie[nax];

vi wyn;

int bylo[nax];

int nope;

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

void wypisz()
{
	for (int i : wyn)
		printf("%d %d\n", kra[i].first, kra[i].second);
}

void dfs1(int v, int oj)
{
	for (pii i : graf[v])
	{
		if (i.second==oj)
			continue;
		dfs1(i.first, i.second);
	}
	vi gru[2];
	for (pii i : graf[v])
	{
		if (i.second==oj)
			continue;
		gru[sto[i.first]].push_back(i.second);
	}
	int juz=(!oj);
	int ma=sto[v];
	vi kol;
	while(!gru[0].empty() || !gru[1].empty() || !juz)
	{
		if (!gru[ma].empty())
		{
			kol.push_back(gru[ma].back());
			gru[ma].pop_back();
			ma^=1;
			continue;
		}
		if (juz)
		{
			nope=1;
			break;
		}
		sto[v]=ma;
		kol.push_back(oj);
		ma^=1;
		juz=1;
	}
	for (int i=1; i<(int)kol.size(); i++)
		skie[kol[i]].push_back(kol[i-1]);
}

void zrob(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i : skie[v])
		zrob(i);
	wyn.push_back(v);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		sto[i]=0;
		skie[i].clear();
		bylo[i]=0;
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		sto[a]^=1;
		sto[b]^=1;
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
		kra[i]={a, b};
	}
	wyn.clear();
	nope=0;
	dfs1(1, 0);
	if (nope)
	{
		ans(0);
	}
	else
	{
		for (int i=1; i<n; i++)
			zrob(i);
		ans(1);
		wypisz();
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}