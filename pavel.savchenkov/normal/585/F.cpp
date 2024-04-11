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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
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
const int MAXD = 50 + 10;
const int A = 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct Node {
	Node* to[A];
	Node* link;
	Node* go[A];
	int depth;

	Node() {
		memset (to, 0, sizeof to);
		memset (go, 0, sizeof go);
		link = nullptr;
		depth = 0;
	}

	void* operator new(size_t);
};

Node pool[(int) 5e5];
int ptr_pool;

void* Node::operator new(size_t) {
	pool[ptr_pool] = Node();
	return pool + ptr_pool++;
}

int id_node(Node* v) {
	return v - pool;
}

Node* node_by_id(int id) {
	if  (id >= ptr_pool) {
		return nullptr;
	}
	return pool + id;
}

void add_string(Node* root, const string& s) {
	Node* v = root;
	for (char c : s) {
		if  (!v->to[c - '0']) {
			v->to[c - '0'] = new Node();
		}
		v = v->to[c - '0'];
	}
}

void precalc_links(Node* root) {
	static Node* Q[(int) 5e5];
	int ql, qr;
	ql = qr = 0;

	root->link = nullptr;
	forn(c, A) {
		if  (root->to[c]) {
			root->go[c] = root->to[c];
			root->to[c]->link = root;
			root->to[c]->depth = 1;
			Q[qr++] = root->to[c];
		} else {
			root->go[c] = root;
		}
	}

	while (ql != qr) {
		Node* v = Q[ql++];

		// printf("v = %d\n", id_node(v));

		assert(v->link);
		assert(v->link->depth < v->depth);
		forn(c, A) {
			if  (v->to[c]) {
				v->go[c] = v->to[c];
			} else {
				v->go[c] = v->link->go[c];
			}
			assert(v->go[c]);
		}

		forn(c, A) {
			Node* to = v->to[c];
			if  (!to) {
				continue;
			}
			to->link = v->link->go[c];
			to->depth = v->depth + 1;
			// printf("v=%d -> to=%d, to->link=%d, c = %d, \n", id_node(v), id_node(to), id_node(to->link), c);
			Q[qr++] = to;
		}
	}
}

string s, x, y;
int n, d;

bool read() {
	getline(cin, s);
	n = sz(s);
	getline(cin, x);
	getline(cin, y);
	d = sz(x);
	assert(sz(y) == d);
	return true;
}

Node* root;

int dp[MAXD][2][2][MAXN * 30][2];

int solve() {
	root = new Node();
	forn(i, n) forn(len, d / 2 + 1) {
		if  (i + len - 1 >= n) {
			break;
		}
		add_string(root, s.substr(i, len));
	}

	precalc_links(root);

	const int nodes = ptr_pool;
	memset (dp, 0, sizeof dp);
	dp[0][1][1][0][0] = 1;
	forn(i, d) forn(eq_x, 2) forn(eq_y, 2) forn(id, nodes) forn(was, 2) {
		int cur_dp = dp[i][eq_x][eq_y][id][was];
		if  (!cur_dp) {
			continue;
		}

		if  (was) {
			assert(id == 0);
		}

		auto* node = node_by_id(id);
		assert(node);
		assert(node->depth < d / 2);
		forn(nxt, 10) {
			int new_eq_x = eq_x;
			if  (eq_x) {
				if  (nxt < x[i] - '0') {
					continue;
				}
				new_eq_x = nxt == x[i] - '0';
			}

			int new_eq_y = eq_y;
			if  (eq_y) {
				if  (nxt > y[i] - '0') {
					continue;
				}
				new_eq_y = nxt == y[i] - '0';
			}

			auto* new_node = node->go[nxt];
			assert(new_node);
			int new_was = was || new_node->depth >= d / 2;
			if  (new_was) {
				new_node = root;
			}
			int new_id = id_node(new_node);

			add(dp[i + 1][new_eq_x][new_eq_y][new_id][new_was], cur_dp);
		}
	}

	int ans = 0;
	forn(eq_x, 2) forn(eq_y, 2) forn(id, nodes) {
		int cur_dp = dp[d][eq_x][eq_y][id][1];
		if  (id != 0) assert(!cur_dp);
		add(ans, cur_dp);
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}