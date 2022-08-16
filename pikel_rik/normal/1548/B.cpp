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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<long long> a(n);
		for (auto &x : a) cin >> x;

		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}

		vector<long long> diff(n - 1);
		for (int i = 1; i < n; i++) {
			diff[i - 1] = abs(a[i] - a[i - 1]);
		}

		sparse_table<long long> st(diff, n, [&](const auto &x, const auto &y) {
			return __gcd(x, y);
		});

		int ans = 1;
		for (int i = 0, j = 0; i < n - 1; i++) {
			while (j <= i && st.query(j, i) == 1) {
				j += 1;
			}
			ans = max(ans, i - j + 2);
		}
		cout << ans << '\n';
	}
	return 0;
}