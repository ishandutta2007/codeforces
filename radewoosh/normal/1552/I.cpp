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
const int nax=107;
const ll mod=998244353;

int n, k;

struct bn
{
	ll a=0;
	ll b=0;
	const int d=50;
	bn()
	{
		
	}
	int count()
	{
		return __builtin_popcountll(a)+__builtin_popcountll(b);
	}
	bn(ll aa, ll bb)
	{
		a=aa;
		b=bb;
	}
	void flip(int v)
	{
		if (v<=d)
			a^=(1LL<<v);
		else
			b^=(1LL<<(v-d));
	}
	int daj(int v)
	{
		if (v<=d)
			return (a>>v)&1;
		else
			return (b>>(v-d))&1;
	}
	void ustal(int v, int w)
	{
		if (w!=daj(v))
			flip(v);
	}
	int znajdz()
	{
		if (a)
			return __builtin_ctzll(a);
		return d+__builtin_ctzll(b);
	}
	bn &operator =(bn v)
	{
		a=v.a;
		b=v.b;
		return (*this);
	}
};

void wypisz(bn v)
{
	for (int i=1; i<=n; i++)
	{
		if (v.daj(i))
			printf("%d ", i);
		else
			printf("  ");
	}
	printf("\n");
}

bool operator <(bn a, bn b)
{
	if (a.a!=b.a)
		return a.a<b.a;
	return a.b<b.b;
}

bool operator ==(bn a, bn b)
{
	return (a.a==b.a && a.b==b.b);
}

bool operator !=(bn a, bn b)
{
	return !(a==b);
}

bn operator |(bn a, bn b)
{
	return bn(a.a|b.a, a.b|b.b);
}

bn operator &(bn a, bn b)
{
	return bn(a.a&b.a, a.b&b.b);
}

bn operator ^(bn a, bn b)
{
	return bn(a.a^b.a, a.b^b.b);
}

bn nal[nax];

ll sil[nax];

ll wyn=1;

set<bn> ist;

bn zero;

int ktotu[nax];
int wsk;

void rek(bn v)
{
	if (v.count()==0)
		return;
	if (v.count()==1)
	{
		wsk++;
		ktotu[wsk]=v.znajdz();
		return;
	}
	bn puz;
	for (bn i : ist)
		if (i!=v && (v&i)==i)
			puz=i;
	rek(puz);
	rek(v^puz);
}

#define PB push_back
#define SZ(x) ((int)(x).size())
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define VI vector<int>               //numeracja od zera
struct FU {                          //nie dawa multikrawdzi ani ptli
  VI p; vector<bool> b;              //nie odpala IsPlanar() ponad raz
  FU() {}
  FU(int n) : p(n), b(n) { iota(p.begin(), p.end(), 0); }
  pair<int, bool> Find(int v) {
    if (p[v] == v) { return {v, 0}; }
    auto res = Find(p[v]); res.second ^= b[v];
    p[v] = res.first; b[v] = res.second; return res;
  }
  bool Union(int x, int y, bool flip) {
    bool xb, yb; tie(x, xb) = Find(x); tie(y, yb) = Find(y);
    if (x == y) { return !(xb ^ yb ^ flip); }
    p[x] = y; b[x] = xb ^ yb ^ flip; return true;
  }
};
struct PlanarityTest {
  int N, M, tm;
  vector<VI> adj, dn, up; vector<pair<int,int>> e_up;
  vector<bool> vis; VI low, pre;
  FU fu;
  void DfsLow(int v, int p) {
    vis[v] = true; low[v] = pre[v] = tm++;
    for (int s : adj[v]) {
      if (s == p) { continue; }
      if (!vis[s]) {
        dn[v].PB(s); DfsLow(s, v); low[v] = min(low[v], low[s]);
      } else if (pre[s] < pre[v]) {
        up[v].PB(SZ(e_up)); e_up.PB({v, s});
        low[v] = min(low[v], pre[s]);
      }
    }
  }
  VI Interlace(const VI &ids, int lo) {
    VI ans;
    for (int e : ids) if (pre[e_up[e].second] > lo) ans.PB(e);
    return ans;
  }
  bool AddFU(const VI &a, const VI &b) {
    FOR (k, 1, SZ(a) - 1) if (!fu.Union(a[k - 1], a[k], 0)) { return false; }
    FOR (k, 1, SZ(b) - 1) if (!fu.Union(b[k - 1], b[k], 0)) { return false; }
    if (SZ(a) && SZ(b) && !fu.Union(a[0], b[0], 1)) { return false; }
    return true;
  }
  bool DfsPlanar(int v, int p) {
    for (int s : dn[v]) if (!DfsPlanar(s, v)) { return false; }
    auto sz = SZ(dn[v]);
    FOR (i, 0, sz - 1) {
      FOR (j, i + 1, sz - 1) {
        auto a = Interlace(up[dn[v][i]], low[dn[v][j]]);
        auto b = Interlace(up[dn[v][j]], low[dn[v][i]]);
        if (!AddFU(a, b)) { return false; }
      }
      for (int j : up[v]) {
        if (e_up[j].first != v) { continue; }
        auto a = Interlace(up[dn[v][i]], pre[e_up[j].second]);
        auto b = Interlace({j}, low[dn[v][i]]);
        if (!AddFU(a, b)) { return false; }
      }
    }
    for (int s : dn[v]) {
      for (int idx : up[s]) {
        if (pre[e_up[idx].second] < pre[p]) { up[v].PB(idx); }
      }
      up[s].clear(); up[s].shrink_to_fit();
    }
    return true;
  }
  PlanarityTest(int n) : N(n), M(0), adj(n) {}
  void AddEdge(int u, int v) { adj[u].PB(v); adj[v].PB(u); ++M; }
  bool IsPlanar() {
    if (N <= 3) { return true; }
    if (M > 3 * N - 6) { return false; }
    vis = vector<bool>(N);
    up = dn = vector<VI>(N);
    low = pre = VI(N);
    FOR (v, 0, N - 1) if (!vis[v]) {
      e_up.clear(); tm = 0; DfsLow(v, -1);
      fu = FU(SZ(e_up));
      if (!DfsPlanar(v, -1)) { return false; }
    }
    return true;
  }
};

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d", &a);
		//~ a=2;
		while(a--)
		{
			scanf("%d", &b);
			//~ b=i+a;
			nal[i].flip(b);
		}
	}
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=1; i<=k; i++)
		ist.insert(nal[i]);
	ist.insert(nal[0]);
	for (int i=1; i<=n; i++)
	{
		nal[0].flip(i);
		ist.insert(nal[0]);
		nal[0].flip(i);
	}
	for (int i=1; i<=n; i++)
		nal[0].flip(i);
	ist.insert(nal[0]);
	vector<bn> kolejka;
	for (bn i : ist)
		kolejka.push_back(i);
	while(!kolejka.empty())
	{
		if ((int)ist.size()>n*n/2+3*n+7)
		{
			printf("0\n");
			return 0;
		}
		bn j=kolejka.back();
		kolejka.pop_back();
		for (int i=1; i<=k; i++)
		{
			if ((j&nal[i])!=zero)
			{
				for (bn l : {j&nal[i], j|nal[i]})
				{
					if (!ist.count(l))
					{
						ist.insert(l);
						kolejka.push_back(l);
					}
				}
			}
		}
	}
	for (bn i : ist)
	{
		for (bn j : ist)
		{
			if (i==j)
				break;
			bn lacz=(i&j);
			if (lacz==zero || lacz==j || lacz==i)
				continue;
			bn wez=(i^j);
			//~ if (ist.count(wez))
			//~ {
				//~ wypisz(i);
				//~ wypisz(j);
				//~ wypisz(i^j);
				//~ printf("0\n");
				//~ return 0;
			//~ }
		}
	}
	//~ for (bn i : ist)
		//~ wypisz(i);
	//~ debug() << imie(ist.size());
	vector<bn> oni;
	for (bn i : ist)
		oni.push_back(i);
	int r=ist.size();
	{
		vector<pii> kra;
		bitset<60007> macierz[r];
		for (int i=0; i<r; i++)
			macierz[i].reset();
		PlanarityTest janusz=PlanarityTest(r);
		janusz.AddEdge(0, r-1);
		for (int i=1; i<r; i++)
		{
			vi tu;
			for (int j=i-1; j>=0; j--)
			{
				if (macierz[i][j] || (oni[i]&oni[j])!=oni[j])
					continue;
				janusz.AddEdge(i, j);
				macierz[i]|=macierz[j];
				macierz[i][j]=1;
			}
		}
		if (!janusz.IsPlanar())
		{
			printf("0\n");
			return 0;
		}
	}
	vector<unsigned long long> hasz(r);
	map<unsigned long long,int> iluma;
	map<unsigned long long,vi> ktoma;
	for (int i=r-1; i>=0; i--)
	{
		for (int j=i+1; j<r; j++)
			if ((oni[j]&oni[i])==oni[i])
				hasz[i]+=hasz[j];
		iluma[hasz[i]]++;
		ktoma[hasz[i]].push_back(i);
		hasz[i]+=rand();
		hasz[i]+=rand()*(10000LL);
		hasz[i]+=rand()*(10000000LL);
	}
	for (auto i : iluma)
	{
		if (i.second>1)
		{
			//~ if (i.second>2)
			//~ {
				//~ for (int a : ktoma[i.first])
				//~ {
					//~ for (int b : ktoma[i.first])
					//~ {
						//~ if (a==b)
							//~ break;
						//~ if ((oni[a]&oni[b])!=zero)
						//~ {
							//~ printf("0\n");
							//~ return 0;
						//~ }
					//~ }
				//~ }
			//~ }
			for (int j=1; j<=i.second; j++)
				wyn=(wyn*j)%mod;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}