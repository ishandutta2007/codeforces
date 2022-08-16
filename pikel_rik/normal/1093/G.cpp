#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree(): n(), t(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(2 * n), e(e), f(f) {
        for (int i = 0; i < n; i++)
            t[i + n] = T(arr[i]);
        for (int i = n - 1; i > 0; i--)
            t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    template <typename U>
    void update(int i, U val) {
        for (t[i += n] = T(val); i > 1; i >>= 1) {
            t[i >> 1] = f(t[i], t[i ^ 1]);
        }
    }

    T query(int l, int r) {
        T ans = e;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = f(ans, t[l++]);
            if (r & 1) ans = f(ans, t[--r]);
        }
        return ans;
    }
};

int n, k;
vector<vector<int>> a;

struct node {
	vector<int> mx, mn;
	node(): mx(), mn() {}
	node(int i): mx(1 << k), mn(1 << k) {
		for (int mask = 0; mask < (1 << k); mask++) {
			int dist = 0;
			for (int j = 0; j < k; j++) {
				if (mask & (1 << j)) {
					dist -= a[i][j];
				} else dist += a[i][j];
			}
			mx[mask] = mn[mask] = dist;
		}
	}
};

node combine(const node& x, const node& y) {
	if (x.mx.empty()) {
		return y;
	}
	if (y.mx.empty()) {
		return x;
	}
	node res;
	res.mx.resize(1 << k);
	res.mn.resize(1 << k);
	for (int mask = 0; mask < (1 << k); mask++) {
		res.mx[mask] = max(x.mx[mask], y.mx[mask]);
		res.mn[mask] = min(x.mn[mask], y.mn[mask]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	a.assign(n, vector<int>(k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	SegmentTree<node> st(ind, n, node(), combine);

	int q;
	cin >> q;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int i;
			cin >> i; --i;
			for (int& x : a[i]) cin >> x;
			st.update(i, i);
		} else {
			int l, r;
			cin >> l >> r; --l; --r;
			node res = st.query(l, r);
			int dist = 0;
			for (int mask = 0; mask < (1 << k); mask++) {
				dist = max(dist, res.mx[mask] - res.mn[mask]);
			}
			cout << dist << '\n';
		}
	}
	return 0;
}