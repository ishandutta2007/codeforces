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
			t[x << 1] += lazy[x];
			t[x << 1 | 1] += lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
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
			t[i] += val;
			lazy[i] += val;
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

	constexpr long long inf = (long long)1e15;

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	vector<long long> dp(n);

	vector<int> last(n, -1);
	last[a[0]] = 0;

	for (int i = 1; i < n; i++) {
		if (last[a[i]] == -1) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = dp[i - 1] + i - last[a[i]];
		}
		last[a[i]] = i;
	}

	for (int i = 1; i < k; i++) {
		segment_tree<long long> st(dp, n, inf, [&](const auto &x, const auto &y) {
			return x < y ? x : y;
		});

		fill(last.begin(), last.end(), -1);

		long long sum = 0;
		for (int j = 0; j < n; j++) {
			if (last[a[j]] != -1) {
				sum -= last[a[j]];
				st.update(last[a[j]], n - 1, last[a[j]] - j);
			} else {
				st.update(last[a[j]], n - 1, -j);
			}
			sum += j;
			last[a[j]] = j;
			if (i <= j) {
				dp[j] = sum + st.query(0, j - 1);
			} else {
				dp[j] = inf;
			}
		}
	}

	cout << dp.back() << '\n';
	return 0;
}