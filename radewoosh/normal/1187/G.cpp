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
const int mag=150;

struct MinCost {
	struct kra {
		int cel, *prze1, *prze2;
		ll koszt;
	};
	int n=0, zr, uj;
	const ll inf=1e9;
	vector <vector <kra>> graf;
	vector <int> bylo, aktu;
	vector <ll> odl, pamodl;
	void vert(int v) {
		if (v>n) {
			n=v;
			graf.resize(n);
			bylo.resize(n);
			aktu.resize(n);
			odl.resize(n);
			pamodl.resize(n);
		}
	}
	void add_edge(int v, int u, int prze, ll koszt) {
		vert(v+1); vert(u+1);
		kra ret1{u, new int(prze), new int(0), koszt};
		kra ret2{v, ret1.prze2, ret1.prze1, -koszt};
		graf[v].push_back(ret1);
		graf[u].push_back(ret2);
	}
	void spfa() {
		for (int i=0; i<n; i++) {
			aktu[i]=1;
			pamodl[i]=inf;
		}
		aktu[zr]=pamodl[zr]=0;
		queue <int> kol;
		kol.push(zr);
		while(!kol.empty()) {
			int v=kol.front();
			kol.pop();
			if (aktu[v])
				continue;
			aktu[v]=1;
			for (kra i : graf[v]) {
				if (*i.prze1 && pamodl[v]+i.koszt<pamodl[i.cel]) {
					pamodl[i.cel]=pamodl[v]+i.koszt;
					aktu[i.cel]=0;
					kol.push(i.cel);
				}
			}
		}
	}
	void dij() {
		for (int i=0; i<n; i++)
			odl[i]=inf;
		priority_queue < pair <ll,int> > dijks;
		dijks.push({0, zr});
		while(!dijks.empty()) {
			ll dis=-dijks.top().first;
			int v=dijks.top().second;
			dijks.pop();
			if (odl[v]!=inf)
				continue;
			odl[v]=pamodl[v]+dis;
			for (auto j : graf[v])
				if ((*j.prze1) && odl[j.cel]==inf)
					dijks.push({-(dis+pamodl[v]-pamodl[j.cel]+j.koszt), j.cel});
		}
	}
	int dfs(int v) {
		if (v==uj)
			return 1;
		bylo[v]=1;
		for (int i=0; i<(int)graf[v].size(); i++) {
			if (!bylo[graf[v][i].cel] && (*graf[v][i].prze1) &&
			odl[v]+graf[v][i].koszt==odl[graf[v][i].cel] && dfs(graf[v][i].cel)) {
				(*graf[v][i].prze1)--;
				(*graf[v][i].prze2)++;
				return 1;
			}
		}
		return 0;
	}
	pair <int,ll> flow(int zrzr, int ujuj) {
		zr=zrzr; uj=ujuj;
		vert(zr+1); vert(uj+1);
		//~ spfa();
		pair <int,ll> ret{0, 0};
		while(1) {
			//~ dij();
			spfa();
			odl=pamodl;
			for (int i=0; i<n; i++)
				bylo[i]=0;
			if (!dfs(zr))
				break;
			ret.first++;
			ret.second+=odl[uj];
		}
		return ret;
	}
};


int n, m, k, c, d;

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
	MinCost janusz;
	int zr=mag*n+1;
	for (int i=0; i<mag; i++)
		janusz.add_edge(i*n+1, 0, k, 0);
	for (int i=0; i+1<mag; i++)
		for (int j=1; j<=n; j++)
			janusz.add_edge(i*n+j, (i+1)*n+j, k, c);
	for (int i=1; i<=k; i++)
	{
		int x;
		scanf("%d", &x);
		janusz.add_edge(zr, x, 1, 0);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		for (int h=0; h<2; h++)
		{
			for (int j=0; j+1<mag; j++)
				for (int l=1; l<=k; l++)
					janusz.add_edge(j*n+a, (j+1)*n+b, 1, (2*l-1)*d+c);
			swap(a, b);
		}
	}
	auto wez=janusz.flow(zr, 0);
	assert(wez.first==k);
	printf("%lld\n", wez.second);
	return 0;
}