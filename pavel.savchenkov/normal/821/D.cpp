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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int INF = 1e9;

int n, m, k;
vi r;
vi c;

bool read() {
	if  (scanf("%d%d%d", &n, &m, &k) < 3) {
		return 0;
	}
	r.resize(k);
	c.resize(k);
	forn(i, k) {
		scanf("%d%d", &r[i], &c[i]);
		--r[i];
		--c[i];
	}
	return 1;
}

vector<vii> g;
map<pii, int> id_of;

void addE(int a, int b, int w) {
	g[a].pb(mp(b, w));
	g[b].pb(mp(a, w));
}

int getDist(int s, int t) {
	vi dist(sz(g), INF);
	dist[s] = 0;

	priority_queue<pii, vii> Q;
	Q.push(mp(-dist[s], s));
	while (!Q.empty()) {
		int d, v;
		tie(d, v) = Q.top();
		d = -d;
		Q.pop();

		if  (d != dist[v]) {
			continue;
		}

		for (const auto& e : g[v]) {
			int to, w;
			tie(to, w) = e;
			if (dist[to] > dist[v] + w) {
				dist[to] = dist[v] + w;
				Q.push(mp(-dist[to], to));
			}
		}
	}

	forn(i, sz(g)) {
		eprintf("i = %d, dist = %d\n", i, dist[i]);
	}

	return dist[t];
} 

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

int solve() {
	g.clear();
	g.resize(k + n + m + 1);

	id_of.clear();
	forn(it, k) {
		id_of[mp(r[it], c[it])] = it;
	}

	forn(it, k) {
		int i = r[it];
		int j = c[it];

		addE(it, k + i, 1);
		if  (i > 0) {
			addE(it, k + i - 1, 1);
		}
		if  (i + 1 < n) {
			addE(it, k + i + 1, 1);
		}

		addE(it, k + n + j, 1);
		if  (j > 0) {
			addE(it, k + n + j - 1, 1);
		}
		if  (j + 1 < m) {
			addE(it, k + n + j + 1, 1);
		}

		forn(d, 4) {
			int ni = i + di[d];
			int nj = j + dj[d];

			pii to(ni, nj);
			auto iter = id_of.find(to);
			if  (iter == id_of.end()) {
				continue;
			}
			int id = iter->snd;
			addE(it, id, 0);
		}
	}

	int t = -1;
	if  (id_of.count(mp(n - 1, m - 1))) {
		t = id_of[mp(n - 1, m - 1)];
	} else {
		addE(k + n + m, k + (n - 1), 1);
		addE(k + n + m, k + n + (m - 1), 1);
		t = k + n + m;
	}

	eprintf("t = %d\n", t);

	int dist = getDist(id_of.at(mp(0, 0)), t);
	eprintf("dist = %d\n", dist);
	if  (dist >= INF) {
		return -1;
	}
	dist = (dist + 1) / 2;
	return dist;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}