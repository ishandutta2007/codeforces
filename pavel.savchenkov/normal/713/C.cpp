#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 5e6 + 10;
const ll INF = 1e18;

struct Edge {
	int v, to;
	ll cap, cost, flow;
};

ll dist[MAXN];
int Q[MAXN];
int ql, qr;
int prev[MAXN];

struct Graph {
	vvi g;
	vector<Edge> es;
	int n;

	Graph(int n = 0) : n(n) {
		g.resize(n);
	}

	void addE(int v, int to, ll cap, ll cost) {
		// printf("%d -> %d, cap=%lld, cost=%lld\n", v, to, cap, cost);

		g[v].pb(sz(es));
		es.pb(Edge{v, to, cap, cost, 0});

		g[to].pb(sz(es));
		es.pb(Edge{to, v, 0, -cost, 0});
	}

	ll add_flow() {
		forn(i, n) {
			dist[i] = INF;
			prev[i] = -1;
		}
		ql = qr = 0;
		dist[0] = 0;
		Q[qr++] = 0;
		while (ql != qr) {
			int v = Q[ql++];
			for (int id : g[v]) {
				if  (es[id].cap > es[id].flow && dist[es[id].to] > dist[es[id].v] + es[id].cost) {
					dist[es[id].to] = dist[es[id].v] + es[id].cost;
					prev[es[id].to] = id;
					Q[qr++] = es[id].to;
				}
			}
		}

		if  (prev[n - 1] == -1) {
			return 0;
		}

		ll add = INF;
		int v = n - 1;
		while (v) {
			int id = prev[v];
			add = min(add, es[id].cap - es[id].flow);
			v = es[id].v;
		}

		v = n - 1;
		while (v) {
			int id = prev[v];
			es[id].flow += add;
			es[id ^ 1].flow -= add;
			v = es[id].v;
		}

		return add;
	}

	ll min_cost() {
		ll f = 0;
		while (1) {
			ll cur = add_flow();
			if  (!cur) {
				break;
			}
			// cerr << "add: " << cur << endl;
			f += cur;
		}

		// cerr << "flow = " << f << endl;

		ll cost = 0;
		forn(v, n) {
			for (int id : g[v]) {
				if  (es[id].flow > 0) {
					cost += es[id].flow * es[id].cost;
				}
			}
		}

		return cost;
	}
};

int n;
ll a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	a[0] = -INF;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	++n;
	a[n++] = INF;
	return true;
}

ll d[MAXN];

ll solve() {
	// forn(i, n) {
	// 	printf("%lld ", a[i]);
	// }
	// puts("");

	d[0] = a[0];
	for (int i = 1; i < n; ++i) {
		d[i] = a[i] - a[i - 1];
	}
	d[n - 1] = a[n - 1];

	// forn(i, n) {
	// 	printf("%lld\n", d[i]);
	// }

	Graph g(1 + n + 1);
	forn(i, n) {
		if  (d[i] <= 0) {
			if  (i > 0) {
				g.addE(0, i + 1, -d[i] + 1, 0);
			} else {
				g.addE(i + 1, n + 1, INF, 0);
			}
		} else {
			g.addE(i + 1, n + 1, d[i] - 1, 0);
		}
	}

	for (int i = 1; i < n; ++i) {
		g.addE(1 + i, 1 + (i + 1), INF, 1);
		g.addE(1 + i, 1 + (i - 1), INF, 1);
	}

	return g.min_cost();
}


int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}