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

int n, m;
vector <pii> graf[nax];

int dp[nax];

vector <pii> wez[nax];

int gle[nax];
int ojc[nax];
int dooj[nax];

void cons(vi &wek)
{
	int g=0;
	int r=wek.size();
	for (int i=0; i<r; i++)
		if (wek[i]<wek[g])
			g=i;
	vi pom=wek;
	wek.clear();
	for (int i=0; i<r; i++)
		wek.push_back(pom[(g+i)%r]);
	g=0;
	for (int i=0; i<r; i++)
		if (wek[i]>wek[g])
			g=i;
	for (int i=0; i<g; i++)
		if (wek[i]>wek[i+1])
			return;
	for (int i=r-1; i>g; i--)
		if (wek[i]>wek[i-1])
			return;
	wez[wek[0]].push_back({wek[g], -1});
}

void dfs1(int v, int oj)
{
	for (pii i : graf[v])
	{
		if (i.second==oj)
			continue;
		if (gle[i.first])
		{
			if (gle[i.first]>gle[v])
				continue;
			vi cyk{i.second};
			int u=v;
			while(u!=i.first)
			{
				cyk.push_back(dooj[u]);
				u=ojc[u];
			}
			cons(cyk);
			continue;
		}
		gle[i.first]=gle[v]+1;
		ojc[i.first]=v;
		dooj[i.first]=i.second;
		dfs1(i.first, i.second);
	}
}

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
		int r=graf[i].size();
		for (int j=0; j+1<r; j++)
			wez[graf[i][j].second].push_back({graf[i][j+1].second, 1});
		dp[graf[i].back().second]++;
	}
	gle[1]=1;
	dfs1(1, 0);
	debug() << range(dp+1, dp+1+m);
	for (int i=m; i; i--)
		for (pii j : wez[i])
			dp[i]+=dp[j.first]*j.second;
	debug() << range(dp+1, dp+1+m);
	
	
	for (int i=1; i<=n; i++)
		printf("%d ", dp[graf[i][0].second]-1);
	printf("\n");
	return 0;
}