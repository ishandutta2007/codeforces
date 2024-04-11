#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 50;
const int M = 6e5 + 50;

inline int lowbit(int x) { return x & -x; }

map<int, int> gg;
int a[N], b[N], ans[N];
int64_t val[M];
vector<tuple<int, int, int>> ops;

struct fenwick_t {
	int64_t t[N];
	void clear() {
		memset(t, 0, sizeof t);
	}
	void add(int p, int64_t v) {
		for (; p < N; p += lowbit(p))
			t[p] += v;
	}
	int64_t query(int p) {
		int64_t r = 1;
		for (; p; p -= lowbit(p))
			r += t[p];
		return r;
	}
} T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q, tot = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!gg.count(a[i])) {
			gg[a[i]] = ++tot;
		}
		a[i] = gg[a[i]];
		b[i] = a[i];
	}
	for (int i = 0; i < q; ++i) {
		int op, l, r, x;
		cin >> op;
		if (op == 1) {
			ans[i] = -1;
			cin >> r >> x;
			if (!gg.count(x))
				gg[x] = ++tot;
			x = gg[x];
			ops.emplace_back(-1, r, x);
		}		
		else {
			ans[i] = 1;
			cin >> l >> r >> x;
			ops.emplace_back(l, r, x);
		}
	}
	for (int _ = 0; _ < 40; ++_) {
		for (int i = 1; i <= tot; ++i)
			val[i] = rng();
		T.clear();
		for (int i = 1; i <= n; ++i) {
			a[i] = b[i];
		}
		for (int i = 1; i <= n; ++i) {
			T.add(i, val[a[i]]);
		}
		for (int i = 0; i < q; ++i) {
			auto [l, r, x] = ops[i];
			if (l == -1) {
				T.add(r, -val[a[r]]);
				a[r] = x;
				T.add(r, val[a[r]]);
			}
			else if (ans[i] == 1) {
				int64_t sum = T.query(r) - T.query(l - 1);
				if (sum % x != 0) {
					ans[i] = 0;
				}
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		if (ans[i] == 0) {
			cout << "NO\n";
		}
		else if (ans[i] == 1) {
			cout << "YES\n";
		}
	}
	return 0;
}