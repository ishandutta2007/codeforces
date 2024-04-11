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

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	sparse_table<int> st(a, n, [&](int x, int y) {
		return x & y;
	});

	constexpr int lg = 20;

	int ans = 0;
	for (int bits = lg - 1; bits >= 0; bits--) {
		vector<int> ptr(1 << (lg - bits));
		vector<vector<int>> seen(1 << (lg - bits));
		seen[0].push_back(-1);

		int xor_sum = 0;
		for (int i = 0, j = 0; i < n; i++) {
			xor_sum ^= a[i] >> bits;
			int cur_and = st.query(j, i);
			while (cur_and < (1 << bits) && j < i) {
				j += 1;
				cur_and = st.query(j, i);
			}
			if (cur_and >= (1 << bits)) {
				while (ptr[xor_sum] < seen[xor_sum].size() && seen[xor_sum][ptr[xor_sum]] < j - 1) {
					ptr[xor_sum] += 1;
				}
				if (ptr[xor_sum] < seen[xor_sum].size()) {
					ans = max(ans, i - seen[xor_sum][ptr[xor_sum]]);
				}
			}
			seen[xor_sum].push_back(i);
		}
	}

	cout << ans << '\n';
	return 0;
}