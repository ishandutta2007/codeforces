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

const int MAXN = 5e4 + 10;

int n;
int y[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &y[i]);
	}
	return true;
}

inline bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

struct Node {
	Node* to[2];
	int cnt;
	int dp;

	Node() {
		memset (to, 0, sizeof to);
		cnt = 0;
		dp = -1;
	}
};

void add(Node*& v, const vi& val, int pos) {
	if  (pos == sz(val)) {
		++v->cnt;
		return;
	}
	int bb = val[pos];
	if  (!v->to[bb]) {
		v->to[bb] = new Node();
	}
	add(v->to[bb], val, pos + 1);
}

vi get_bits(int value) {
	vi bits;
	while (value) {
		bits.pb(value & 1);
		value >>= 1;
	}
	reverse(all(bits));
	return bits;
}

Node* root;

void build(const vi& y) {
	root = new Node();
	forn(i, n) {
		add(root, get_bits(y[i]), 0);
	}
}

int calc_dp(Node* v) {
	int sum_dp = 0;
	forn(b, 2) {
		if  (v->to[b]) {
			sum_dp += calc_dp(v->to[b]);
		}
	}
	sum_dp += v->cnt;
	if  (v != root) {
		sum_dp = max(0, sum_dp - 1);
	}
	v->dp = sum_dp;
	// printf("dp=%d\n", sum_dp);
	return v->dp;
}

bool can(int upper) {
	vi ny(n);
	forn(i, n) {
		ny[i] = y[i];
		while (ny[i] > upper && ny[i]) {
			ny[i] /= 2;
		}
		if  (ny[i] > upper) {
			return false;
		}
	}
	build(ny);
	return calc_dp(root) == 0;
}

void restore(Node* v, int num, vi& x) {
	int sum_dp = 0;
	forn(b, 2) {
		if  (v->to[b]) {
			restore(v->to[b], num * 2 + b, x);
			sum_dp += v->to[b]->dp;
		}
	}
	sum_dp += v->cnt;
	if  (sum_dp > 0) {
		x.pb(num);
	}
	if  (v != root) {
		sum_dp = max(0, sum_dp - 1);
	}
	assert(v->dp == sum_dp);
}

vi restore(int upper) {
	vi ny(n);
	forn(i, n) {
		ny[i] = y[i];
		while (ny[i] > upper && ny[i]) {
			ny[i] /= 2;
		}
		assert(ny[i] <= upper);
	}
	build(ny);

	vi x;
	calc_dp(root);
	restore(root, 0, x);
	return x;
}

void solve() {
	sort(y, y + n);

	int L = 0;
	int R = 1e9 + 10;
	while (L != R - 1) {
		int M = (L + R) >> 1;
		if  (can(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	// printf("R=%d\n", R);
	vi x = restore(R);
	sort(all(x));
	assert(sz(x) == n);
	forn(i, n) {
		printf("%d ", x[i]);
	}
	puts("");
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