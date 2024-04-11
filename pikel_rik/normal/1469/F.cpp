#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<int> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = T(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x]) {
			int mid = (l + r) >> 1;
			t[x << 1] += (long long)lazy[x] * (mid - l + 1);
			t[x << 1 | 1] += (long long)lazy[x] * (r - mid);
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, U val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] += val * (r - l + 1);
			lazy[i] += val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	int kth_one(int k) {
		if (t[1] < k)
			return -1;
		return kth_one_helper(k, 1, 0, n - 1);
	}

	int kth_one_helper(int k, int i, int l, int r) {
		if (l == r)
			return l;
		int mid = (l + r) >> 1;
		push(i, l, r);
		if (t[i << 1] >= k)
			return kth_one_helper(k, i << 1, l, mid);
		return kth_one_helper(k - t[i << 1], i << 1 | 1, mid + 1, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];

//	int n = 200000, k = 1000000000;
//	vector<int> l(n, 200000);

	sort(l.begin(), l.end(), greater<>());

	const int N = 400000;
	segment_tree<long long> st(vector<int>(N), N, 0, [&](long long x, long long y) {
		return x + y;
	});

	st.update(0, 0, 1);

	int ans = N + 1;
	for (int i = 0; i < n; i++) {
		int one = st.kth_one(1);
		st.update(one, one, -1), st.update(one + 2, one + 1 + (l[i] - 1) / 2, 2);
		if (l[i] % 2 == 0) {
			st.update(one + 2 + (l[i] - 1) / 2, one + 2 + (l[i] - 1) / 2, 1);
		}
		int qq = st.kth_one(k);
		if (qq != -1) {
			ans = min(ans, qq);
		}
	}

	cout << (ans == N + 1 ? -1 : ans) << '\n';
	return 0;
}