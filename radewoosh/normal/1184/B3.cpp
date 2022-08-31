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
const int nax=1007;
const ll inf=1e18;

int n, m;

ll odl[nax][nax];

int s, b;
int k;
int g[nax*nax];
ll sil[nax*nax];
ll pal[nax*nax];
ll cen[nax*nax];

vector <pll> bazy[nax];

using T = long long;
struct Flow {
  struct E {
    int dest;
    T orig, *lim, *rev;
  };
  int zr, uj, n = 0;
  vector<unique_ptr<T>> ts;
  vector<vector<E>> graf;
  vector<int> ptr, odl;
  void vert(int v) {
    n = max(n, v + 1);
    graf.resize(n);
    ptr.resize(n);
    odl.resize(n);
  }
  bool iszero(T v) {
    return !v; // Zmieni dla doubli.
  }
  void bfs() {
    fill(odl.begin(), odl.end(), 0);
    vector<int> kol = {zr};
    odl[zr] = 1;
    for (int i = 0; i < (int) kol.size(); i++) {
      for (E& e : graf[kol[i]]) {
        if (!odl[e.dest] and !iszero(*e.lim)) {
          odl[e.dest] = odl[kol[i]] + 1;
          kol.push_back(e.dest);
        }
      }
    }
  }
  T dfs(int v, T lim) {
    if (v == uj) return lim;
    T ret = 0, wez;
    for (int& i = ptr[v]; i < (int) graf[v].size(); i++) {
      E& e = graf[v][i];
      if (odl[e.dest] == odl[v] + 1 and !iszero(*e.lim) and
          !iszero(wez = dfs(e.dest, min(*e.lim, lim)))) {
        ret += wez;
        *e.lim -= wez;
        *e.rev += wez;
        lim -= wez;
        if (iszero(lim)) break;
      }
    }
    return ret;
  }
  void add_edge(int u, int v, T lim, bool bi = false /* bidirectional? */) {
    vert(max(u, v));
    T *a = new T(lim), *b = new T(lim * bi);
    ts.emplace_back(a);
    ts.emplace_back(b);
    graf[u].push_back(E{v, lim,      a, b});
    graf[v].push_back(E{u, lim * bi, b, a});
  }
  T dinic(int zr_, int uj_) {
    zr = zr_; uj = uj_;
    vert(max(zr, uj));
    T ret = 0;
    while (true) {
      bfs();
      fill(ptr.begin(), ptr.end(), 0);
      const T sta = dfs(zr, numeric_limits<T>::max());  // Dla doubli mona da
      if (iszero(sta)) break;                           // infinity() zamiast
      ret += sta;                                       // max().
    }
    return ret;
  }
  vector<int> cut() {
    vector<int> ret;
    bfs();
    for (int i = 0; i < n; i++)
      if (odl[i])
        ret.push_back(i);
    return ret;
  }
  map<pair<int, int>, T> get_flowing() {  // Tam gdzie plynie 0 moe nie by
    map<pair<int, int>, T> ret;           // krawdzi.
    for (int i = 0; i < n; i++)
      for (E& e : graf[i])
        if (*e.lim < e.orig)
          ret[make_pair(i, e.dest)] += e.orig - *e.lim;
    for (auto& i : ret) {
      const pair<int, int> rev{i.first.second, i.first.first};
      const T x = min(i.second, ret[rev]);
      i.second -= x;
      ret[rev] -= x;
    }
    return ret;
  }
};

ll best(int v, ll og)
{
	int bsa=0;
	int bsb=(int)bazy[v].size()-1;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (bazy[v][bss].second<=og)
			bsa=bss;
		else
			bsb=bss-1;
	}
	return bazy[v][bsa].first;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			odl[i][j]=(i!=j)*inf;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a!=b)
			odl[a][b]=odl[b][a]=1;
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				odl[i][j]=min(odl[i][j], odl[i][k]+odl[k][j]);
	scanf("%d%d%d", &s, &b, &k);
	for (int i=1; i<=s; i++)
		scanf("%d%lld%lld%lld", &g[i], &sil[i], &pal[i], &cen[i]);
	for (int i=1; i<=b; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		bazy[x].push_back({z, -y});
	}
	for (int i=1; i<=n; i++)
	{
		bazy[i].push_back({-inf, 0});
		sort(bazy[i].begin(), bazy[i].end());
		auto pom=bazy[i];
		bazy[i].clear();
		for (pll j : pom)
		{
			j.second*=-1;
			while(!bazy[i].empty() && bazy[i].back().second>=j.second)
				bazy[i].pop_back();
			bazy[i].push_back(j);
		}
		//~ debug() << i << " " << bazy[i];
	}
	for (int i=1; i<=s; i++)
	{
		ll x=-inf;
		for (int j=1; j<=n; j++)
			if (pal[i]>=odl[g[i]][j])
				x=max(x, best(j, sil[i]));
		cen[i]=x-cen[i];
	}
	ll wyn=0;
	Flow janusz;
	for (int i=1; i<=s; i++)
	{
		if (cen[i]>=0)
		{
			wyn+=cen[i];
			janusz.add_edge(0, i, cen[i]);
		}
		else
		{
			janusz.add_edge(i, s+1, -cen[i]);
		}
	}
	for (int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//~ debug() << imie(a);
		//~ debug() << imie(b);
		janusz.add_edge(a, b, inf);
	}
	//~ debug() << imie(wyn);
	//~ debug() << imie(range(cen+1, cen+1+s));
	printf("%lld\n", wyn-janusz.dinic(0, s+1));
	return 0;
}