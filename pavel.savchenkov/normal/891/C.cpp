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
#define image(c) sort(all(c)), c.resize(unique(all(c)) - c.begin())

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

struct Edge {
	int a, b, w;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d%d", &a, &b, &w);
		--a;
		--b;
	}	

	bool operator < (const Edge& e) const {
		return w < e.w;
	}

	void print() const {
		printf("(%d, %d) w=%d, id=%d\n", a, b, w, id);
	}
};

int n, m;
vector<Edge> es;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	es.resize(m);
	forn(i, m) {
		es[i].read(i);
	}
	return 1;
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return 0;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		return 1;
	}
};

int get_pos(const vi& a, int x) {
	int pos = lower_bound(all(a), x) - a.begin();
	assert(pos < sz(a) && a[pos] == x);
	return pos;
}

struct Block {
	vi vers;
	DSU dsu;

	Block() {}

	Block(DSU& big_dsu, const vector<Edge>& edges) {
		for (const auto& e : edges) {
			vers.pb(e.a);
			vers.pb(e.b);
		}
		image(vers);

		dsu = DSU(sz(vers));

		map<int, int> last_with_root;
		forn(i, sz(vers)) {
			const int v = vers[i];
			const int root = big_dsu.get(v);
			auto it = last_with_root.find(root);
			if  (it == last_with_root.end()) {
				last_with_root[root] = i;
			} else {
				dsu.unite(it->snd, i);
			}
		}
	}

	bool can(const vector<Edge>& es) {
		// printf("IN can:\n");
		// print();
		// {
		// 	for (const auto& e : es) {
		// 		e.print();
		// 	}
		// 	printf("\n");
		// }

		vi cur_vers;
		for (const auto& e : es) {
			cur_vers.pb(e.a);
			cur_vers.pb(e.b);
		}

		image(cur_vers);

		DSU cur_dsu(sz(cur_vers));

		map<int, int> last_with_root;
		forn(i, sz(cur_vers)) {
			const int pos_vers = get_pos(vers, cur_vers[i]);
			const int root = dsu.get(pos_vers);
			auto it = last_with_root.find(root);
			if  (it == last_with_root.end()) {
				last_with_root[root] = i;
			} else {
				cur_dsu.unite(it->snd, i);
			}
		}

		for (const auto& e : es) {
			int aa = get_pos(cur_vers, e.a);
			int bb = get_pos(cur_vers, e.b);
			if  (!cur_dsu.unite(aa, bb)) {
				return 0;
			}		
		}

		return 1;
	}

	void print() {
		printf("vers:\n");
		for (int v : vers) {
			printf("%d ", v);
		}
		printf("\n");
		printf("DSU:\n");
		forn(i, sz(vers)) {
			printf("%d ", dsu.get(i));
		}
		printf("\n\n");
	}
};

void solve() {
	vector<Block> blocks;
	vi id_block(m, -1);

	sort(all(es));

	vi pos_id(m);
	forn(i, m) {
		pos_id[es[i].id] = i;
	}

	DSU dsu(n);
	for (int i = 0, j = 0; i < sz(es); i = j) {
		while (j < sz(es) && es[i].w == es[j].w) {
			++j;
		}

		vector<Edge> cur_es(es.begin() + i, es.begin() + j);
		assert(sz(cur_es) == j - i);
		Block block(dsu, cur_es);

		for (const auto& e : cur_es) {
			dsu.unite(e.a, e.b);
		} 

		for (int k = i; k < j; ++k) {
			id_block[es[k].id] = sz(blocks);
		}

		blocks.pb(block);
	}

	// for (auto& block : blocks) {
	// 	block.print();	
	// }

	// forn(i, m) {
	// 	printf("%d ", id_block[i]);
	// }
	// printf("\n");

	int q;
	scanf("%d", &q);
	forn(it, q) {
		int cnt;
		scanf("%d", &cnt);
		vi ids(cnt);
		forn(i, cnt) {
			scanf("%d", &ids[i]);
			--ids[i];
		}

		sort(all(ids), [&](int i, int j) { return id_block[i] < id_block[j]; });

		bool ok = 1;
		for (int i = 0, j = 0; i < sz(ids); i = j) {
			while (j < sz(ids) && id_block[ids[i]] == id_block[ids[j]]) {
				++j;
			}

			// printf("id_block = %d\n", id_block[ids[i]]);
			// printf("ids:\n");
			// for (int k = i; k < j; ++k) {
			// 	printf("%d ", ids[k]);
			// }
			// printf("\n");

			vector<Edge> cur_es;
			for (int k = i; k < j; ++k) {
				cur_es.pb(es[pos_id[ids[k]]]);
			}

			const int id_b = id_block[ids[i]];
			ok &= blocks.at(id_b).can(cur_es);
		}

		puts(ok ? "YES" : "NO");
	}

}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}