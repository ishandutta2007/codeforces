#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

template< typename T, T(*mergeF)(T&, T&) >
struct seg_tree {
	int n;
	vector<T> tree;
	void fix(int x) {
		tree[x] = mergeF(tree[2 * x], tree[2 * x + 1]);
	}
	seg_tree() {};
	seg_tree(int size, T val) {
		n = size, tree.resize(2 * n);
		for (int i = n; i < 2 * n; i++) tree[i] = val;
		for (int i = n - 1; i; i--) fix(i);
	}

	seg_tree(vector<T> &a, int indexing) {
		n = a.size(), tree.resize(2 * n);
		for (int i = n; i < 2 * n; i++) tree[i] = a[i - n + indexing];
		for (int i = n - 1; i; i--) fix(i);
	}

	void update(int at, T val) {
		at += n - 1;
		tree[at] = val;
		for (at >>= 1; at; at >>= 1) fix(at);
	}

	T query(int l, int r) {
		l += n - 1, r += n - 1;
		T rtn = tree[l];
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) rtn = mergeF(rtn, tree[l++]);
			if (!(r & 1)) rtn = mergeF(rtn, tree[r--]);
		}
		if (l == r) rtn = mergeF(rtn, tree[l]);
		return rtn;
	}
};

int mini(int& a, int& b) {
	if (a < b) return a;
	return b;
}

struct wavelet {
	int lo, hi;
	vector<int> b, val;
	seg_tree<int, mini> seg;
	wavelet *l = 0, *r = 0;
	wavelet(vector<pair<int, int>>::iterator pl, vector<pair<int, int>>::iterator pr, int x, int y) {
		lo = x, hi = y;
		if (lo > hi || pl >= pr) return;
		if (lo == hi) {
			b.reserve(pr - pl + 1);
			b.push_back(0);
			for (auto it = pl; it != pr; it++)
				b.push_back(b.back() + 1), val.push_back(it->second);
			seg = seg_tree<int, mini>(val, 0);
			return;
		}
		int mid = lo + (hi - lo) / 2;
		auto f = [mid](pair<int, int> x) {
			return x.first <= mid;
		};
		b.reserve(pr - pl + 1);
		b.push_back(0);
		for (auto it = pl; it != pr; it++)
			b.push_back(b.back() + f(*it)), val.push_back(it->second);
		seg = seg_tree<int, mini>(val, 0);
		auto it = stable_partition(pl, pr, f);
		l = new wavelet(pl, it, lo, mid), r = new wavelet(it, pr, mid + 1, hi);
	}

	int calc(int loval, int hival, int l, int r) {
		if (l > r || lo > hival || hi < loval) return 2e9;
		if (lo >= loval && hi <= hival) return seg.query(l, r);
		int le = b[l - 1], ri = b[r];
		return min(this->l->calc(loval, hival, le + 1, ri), this->r->calc(loval, hival, l - le, r - ri));
	}

	~wavelet() {
		delete l;
		delete r;
	}
};

int n, q, r;
vector<vector<int>> g, at;
vector<int> a, depth;
vector<pair<int, int>> tour; // tour will be <depth, value>

void euler(int v, int dep = 0, int prev = -1) {
	depth[v] = dep;
	at[v].push_back(tour.size());
	tour.push_back({ dep, a[v] });
	for (auto &i : g[v]) {
		if (i != prev) {
			euler(i, dep + 1, v);
			tour.push_back({ dep, a[v] });
		}
	}
	at[v].push_back((int)tour.size() - 1);
}

int main() {
	fast;
	cin >> n >> r, r--;
	g.resize(n), a.resize(n), at.resize(n), depth.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	euler(r);
	wavelet tree = wavelet(tour.begin(), tour.end(), 0, n);

	cin >> q;
	int p1, p2, x, k, last = 0;
	while (q--) {
		cin >> p1 >> p2;
		x = (p1 + last) % n, k = (p2 + last) % n + 1;
		last = tree.calc(depth[x], depth[x] + k - 1, at[x][0] + 1, at[x][1] + 1);
		cout << last << endl;
	}
}