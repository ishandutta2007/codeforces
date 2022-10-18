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

const int MAXN = 1e3 + 10;
const ll INF = 1e18 + 10;

struct Edge {
	int v, to, w;
	bool erased;
};

vector<Edge> es;
vi g[MAXN];
int n, m, L, s, t;

bool read() {
	if  (scanf("%d%d%d%d%d", &n, &m, &L, &s, &t) < 5) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a].pb(sz(es));
		es.pb(Edge{a, b, w, w == 0});
		g[b].pb(sz(es));
		es.pb(Edge{b, a, w, w == 0});
	}
	return true;
}

vll calc_dist(int s) {
	vll dist(n, INF);
	dist[s] = 0;
	set<pair<ll, int>> S;
	S.insert(mp(dist[s], s));
	while (!S.empty()) {
		int v = S.begin()->snd;
		S.erase(S.begin());
		for (int id : g[v]) {
			const auto& e = es[id];
			if  (dist[e.to] > dist[v] + e.w) {
				S.erase(mp(dist[e.to], e.to));
				dist[e.to] = dist[v] + e.w;
				S.insert(mp(dist[e.to], e.to));
			}
		}
	}
	return dist;
}

bool solve() {
	for (auto& e : es) if  (e.erased) e.w = 1;

	auto d_t = calc_dist(t);
	if  (d_t[s] > L) {
		return false;
	}
	set<pair<ll, int>> S;
	vll dist(n, INF);
	dist[s] = 0;
	S.insert(mp(dist[s], s));
	while (!S.empty()) {
		int v = S.begin()->snd;
		S.erase(S.begin());
		for (int id : g[v]) {
			auto& e = es[id];
			if  (e.erased) {
				// printf("dist[%d] = %lld\n", v, dist[v]);
				int aux = max(0LL, L - (dist[v] + e.w + d_t[e.to]));
				e.w += aux;
				es[id ^ 1].w += aux;
				// printf("(%d, %d) += %lld\n", e.v, e.to, L - (dist[v] + e.w + d_t[e.to]));
			}
			if  (dist[e.to] > dist[v] + e.w) {
				S.erase(mp(dist[e.to], e.to));
				dist[e.to] = dist[v] + e.w;
				S.insert(mp(dist[e.to], e.to));
			}
		}
	}
	d_t = calc_dist(t);
	// printf("d_t[%d] = %lld\n", s, d_t[s]);
	if  (d_t[s] != L) {
		return false;
	}
	puts("YES");
	for (int i = 0; i < sz(es); i += 2) {
		const auto& e = es[i];
		printf("%d %d %d\n", e.v, e.to, e.w);
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("NO");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}