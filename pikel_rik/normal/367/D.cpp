#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct sparse_table {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<std::vector<T>> mat;
	F f;
	sparse_table() : n(), f() {}

	template<typename U>
	sparse_table(const U& arr, int n, F f): n(n), f(f), mat((int) log2(n) + 1) {
		mat[0].resize(n);
		for (int i = 0; i < n; i++)
			mat[0][i] = T(arr[i]);
		for (int j = 1; j < mat.size(); j++) {
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i + (1 << j) <= n; i++) {
				mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T query(int l, int r) {
		int j = 32 - __builtin_clz(r - l + 1) - 1;
		return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, d;
	cin >> n >> m >> d;

	vector<int> id(n);
	for (int i = 0, s; i < m; i++) {
		cin >> s;
		for (int j = 0, x; j < s; j++) {
			cin >> x;
			id[--x] = 1 << i;
		}
	}

	sparse_table<int> st(id, n, [&](int x, int y) {
		return x | y;
	});

	vector<bool> is_bad(1 << m);

	auto dfs = [&](int mask, const auto &self) -> void {
		if (is_bad[mask])
			return;
		is_bad[mask] = true;
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) {
				self(mask ^ (1 << i), self);
			}
		}
	};

	int all = (1 << m) - 1;
	for (int i = 0; i + d <= n; i++) {
		int subarray_or = st.query(i, i + d - 1);
		dfs(all ^ subarray_or, dfs);
	}

	int ans = m;
	for (int mask = 0; mask < (1 << m); mask++) {
		if (!is_bad[mask]) {
			ans = min(ans, __builtin_popcount(mask));
		}
	}
	cout << ans << '\n';
	return 0;
}