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

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int m;
int p[MAXN];
int t[MAXN];
int x[MAXN];

bool read() {
	if  (scanf("%d", &m) < 1) {
		return 0;
	}
	forn(i, m) {
		scanf("%d%d", &p[i], &t[i]);
		--p[i];
		if  (t[i] == 1) {
			scanf("%d", &x[i]);
		}
	}
	return 1;
}

const int K = 400;

int type[MAXN];
int push[MAXN];

struct Block {
	int l, r;
	vi who;
	int rem;

	Block() {}

	Block(int l, int r) : l(l), r(r) {
		rem = 0;
	}

	void add(int pos) {
		assert(l <= pos && pos <= r);
		rem = 0;
		who.clear();
		for (int i = l; i <= r; ++i) {
			if  (type[i] != -1) {
				if  (type[i] == 0) {
					if  (who.empty()) {
						++rem;
					} else {
						who.pop_back();
					}
				} else {
					who.pb(push[i]);
				}
			}
		}

		// printf("add pos=%d\n", pos);
		// for (int x : who) {
		// 	printf("%d ", x);
		// }
		// puts("");
	}
};

vector<Block> blocks;

struct Seg {
	int l, r;
	int id;

	int len() const {
		return r - l + 1;
	}
};

int calc() {	
	vector<Seg> segs;
	forn(id, sz(blocks)) {
		const auto& block = blocks[id];
		int rem = block.rem;
		while (!segs.empty() && rem > 0) {
			if  (rem >= segs.back().len()) {
				rem -= segs.back().len();
				segs.pop_back();
			} else {
				segs.back().r -= rem;
				rem = 0;
				break;
			}
		}
		if  (rem > 0) {
			assert(segs.empty());
		}

		if  (!block.who.empty()) {
			segs.pb(Seg{0, sz(block.who) - 1, id});
		}
	}

	if  (segs.empty()) {
		return -1;
	}

	Seg last = segs.back();

	// printf("segs = %d, last.r=%d\n", sz(segs), last.r);

	return blocks[last.id].who[last.r];
}

void solve() {	
	blocks.clear();
	for (int i = 0; i < m; i += K) {
		blocks.pb(Block(i, min(m - 1, i + K - 1)));
	}

	memset (type, -1, sizeof type);
	forn(i, m) {
		type[p[i]] = t[i];
		if  (t[i] == 1) {
			push[p[i]] = x[i];
		}

		for (auto& block : blocks) {
			if  (block.l <= p[i] && p[i] <= block.r) {
				block.add(p[i]);
			}
		}

		printf("%d\n", calc());
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