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
const int nax=1007;

int n, m;

ll tab[nax];
pii kra[nax];

vi graf[nax];
int odw[nax][nax];

ll wyn[nax];

using T = int;
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

int sko[nax];
int typ[nax];

vi mak[nax];

void dfs1(int v, int s)
{
	if (odw[s][v])
		return;
	odw[s][v]=1;
	mak[s].push_back(v);
	for (int i : graf[v])
		dfs1(i, s);
}

int ost[nax];
int czas;

int dfs2(int v)
{
	ost[v]=czas;
	for (int i : mak[v])
	{
		if (!typ[i])
			continue;
		if (!sko[i] || (ost[sko[i]]!=czas && dfs2(sko[i])))
		{
			sko[i]=v;
			sko[v]=i;
			return 1;
		}
	}
	return 0;
}

int zwieksz()
{
	czas++;
	for (int i=1; i<=n; i++)
	{
		if (!typ[i] && !sko[i] && ost[i]!=czas && dfs2(i))
		{
			return 1;
		}
	}
	return 0;
}

int znacz[nax];

void oznacz(int v)
{
	if (znacz[v])
		return;
	znacz[v]=1;
	for (int i : graf[v])
		oznacz(i);
	if (typ[v] && sko[v])
		oznacz(sko[v]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		wyn[i]=tab[i];
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		kra[i]={a, b};
		graf[a].push_back(b);
	}
	for (int i=1; i<=n; i++)
		dfs1(i, i);
	set<ll> setel;
	for (int i=1; i<=n; i++)
		setel.insert(tab[i]);
	vll pos;
	for (ll i : setel)
		pos.push_back(i);
	ll res=0;
	for (int i=1; i<(int)pos.size(); i++)
	{
		ll a=pos[i-1];
		ll b=pos[i];
		for (int j=1; j<=n; j++)
		{
			int chce=typ[j];
			if (tab[j]<=a)
				chce=1;
			else
				chce=0;
			if (chce!=typ[j])
			{
				if (sko[j])
				{
					sko[sko[j]]=0;
					sko[j]=0;
				}
				typ[j]=chce;
			}
		}
		while (zwieksz());
		int wez=0;
		for (int j=1; j<=n; j++)
			wez+=(sko[j]>0);
		wez>>=1;
		res+=wez*(b-a);
		
		for (int j=1; j<=n; j++)
			znacz[j]=0;
		for (int j=1; j<=n; j++)
			if (!typ[j] && !sko[j])
				oznacz(j);
		for (int j=1; j<=n; j++)
		{
			if (tab[j]>a && !znacz[j])
				wyn[j]-=(b-a);
			else if (tab[j]<=a && znacz[j])
				wyn[j]+=(b-a);
		}
		//~ debug() << range(znacz+1, znacz+1+n);
		//~ debug() << range(wyn+1, wyn+1+n);
	}
	debug() << imie(res);
	//~ for (int i=1; i<=n; i++)
		//~ wyn[i]=tab[i];
	for (int i=1; i<=n; i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	return 0;
}