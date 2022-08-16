#include <bits/stdc++.h>
using namespace std;

template<typename T, typename L = T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<L> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() { }

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
		build(v, 1, 0, n - 1);
	}

	template<typename U>
	void build(const std::vector<U> &v, int i, int l, int r) {
		if (l == r) {
			t[i] = T(v[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x]) {
			int mid = (l + r) >> 1;
			t[x << 1] = (mid - l + 1) * lazy[x];
			t[x << 1 | 1] = (r - mid) * lazy[x];
			lazy[x << 1] = lazy[x];
			lazy[x << 1 | 1] = lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int idx, const U &val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, const U &val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int ql, int qr, const U &val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, const U &val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] = (r - l + 1ll) * val;
			lazy[i] = val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		push(i, l, r);
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;
	cin >> n >> q >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<segment_tree<long long>> st(k);
	for (int i = 0; i < k; i++) {
		int sz = n / k + (i + 1 <= n % k);
		st[i] = segment_tree<long long>(vector<int>(sz), sz, 0, [](long long x, long long y) {
			return x + y;
		});
	}

	vector<vector<pair<int, int>>> queries(n);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r, --l, --r;
		if (r % k < l % k) {
			r -= r % k;
			r -= k - l % k;
		} else if (r % k > l % k) {
			r -= r % k - l % k;
		}
		queries[l].emplace_back(r, i);
	}

	vector<long long> ans(q);

	deque<int> mn;
	vector<vector<pair<int, int>>> mn_q(k);

	for (int l = n - 1; l >= 0; l--) {
		while (!mn.empty() && a[mn.back()] >= a[l]) {
			mn.pop_back();
		}
		if (!mn.empty() && mn.front() == l + k + 1) {
			mn.pop_front();
		}
		mn.push_back(l);

		int now_mn = a[mn.front()];

		st[l % k].update(l / k, a[l]);

		if (l + k < n) {
			while (!mn_q[l % k].empty() && mn_q[l % k].back().second >= now_mn) {
				mn_q[l % k].pop_back();
			}
			if (mn_q[l % k].empty()) {
				st[l % k].update(l / k + 1, st[l % k].n - 1, now_mn);
			} else {
				st[l % k].update(l / k + 1, mn_q[l % k].back().first - 1, now_mn);
			}
			mn_q[l % k].emplace_back(l / k + 1, now_mn);
		}

		for (auto [r, i] : queries[l]) {
			ans[i] = st[l % k].query(l / k, r / k);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}