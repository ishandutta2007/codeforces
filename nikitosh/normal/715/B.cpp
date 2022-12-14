#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 1e5 + 5;
const ll INF = 1e18;

set<pair<ll, int>> s;
ll d[MAX_N];
vector<pii> g[MAX_N], gr[MAX_N], edges;

void dijkstra(int st, int n) {
 	forn (i, n)
 		d[i] = INF;
 	d[st] = 0;
 	forn (i, n)
 		s.insert(mp(d[i], i));
 	while (sz(s)) {
 	    int v = s.begin()->sc;
 	    s.erase(s.begin());
 	    for (auto np : g[v]) {
 	     	int u = np.fs;
 	     	//	printf("v = %d u = %d\n", v, u);
 	     	//printf(I64 " " I64 "\n", d[v], d[u]);
 	     	if (d[u] > d[v] + np.sc) {
 	     	 	s.erase(mp(d[u], u));
 	     	 	d[u] = d[v] + np.sc;
 	     	 	s.insert(mp(d[u], u));
 	     	}
 	    }
 	} 		
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, l, st, t;
	scanf("%d%d%d%d%d", &n, &m, &l, &st, &t);
	forn (i, m) {
	 	int v, u, w;
	 	scanf("%d%d%d", &v, &u, &w);
	 	if (w == 0)
			edges.pb(mp(v, u));
		else
			gr[v].pb(mp(u, w)), gr[u].pb(mp(v, w));
	}
	forn (i, n)
		g[i] = gr[i];
	dijkstra(st, n);
	if (d[t] < l) {
	 	puts("NO");
	 	return 0;
	}
	for (auto e : edges)
		g[e.fs].pb(mp(e.sc, 1)), g[e.sc].pb(mp(e.fs, 1));
	dijkstra(st, n);
	if (d[t] > l) {
	 	puts("NO");
	 	return 0;
	}
	puts("YES");
	forn (i, n)
		for (pii np : gr[i])
			if (np.fs > i)
				printf("%d %d %d\n", i, np.fs, np.sc);
	int bl = 0, br = 1 + sz(edges);
	while (br - bl > 1) {
	 	int bm = (bl + br) / 2;
		forn (i, n)
			g[i] = gr[i];
		forn (j, bm)
			g[edges[j].fs].pb(mp(edges[j].sc, 1)), g[edges[j].sc].pb(mp(edges[j].fs, 1));
		dijkstra(st, n);
		if (d[t] < l)
			br = bm;
		else
			bl = bm;
	}
   	forn (i, n)
   		g[i] = gr[i];
   	forn (j, bl)
   		g[edges[j].fs].pb(mp(edges[j].sc, 1)), g[edges[j].sc].pb(mp(edges[j].fs, 1));
	dijkstra(st, n);
	if (d[t] == l) {
	 	forn (j, bl)
	 		printf("%d %d %d\n", edges[j].fs, edges[j].sc, 1);
	 	forab (j, bl, sz(edges))
	 		printf("%d %d %d\n", edges[j].fs, edges[j].sc, int(1e9 + 1));
	 	return 0;
	}
	int v0 = edges[bl].fs, u0 = edges[bl].sc;
	ll sV0 = d[v0], sU0 = d[u0];
	dijkstra(t, n);
	ll tV0 = d[v0], tU0 = d[u0];
	ll path = min(sV0 + tU0, sU0 + tV0);
	assert(path < l);
	forn (j, bl)
		printf("%d %d %d\n", edges[j].fs, edges[j].sc, 1);
	printf("%d %d " I64 "\n", v0, u0, l - path);
	forab (j, bl + 1, sz(edges))
		printf("%d %d %d\n", edges[j].fs, edges[j].sc, int(1e9 + 1));
	g[v0].pb(mp(u0, l - path));
	g[u0].pb(mp(v0, l - path));
	dijkstra(st, n);
	assert(d[t] == l);
	return 0;
}