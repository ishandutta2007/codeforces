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

	string s;
	cin >> s;

	vector<vector<int>> len(2, vector<int>(n));
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			len[0][i] = 1 + (i == 0 ? 0 : len[0][i - 1]);
			len[1][i] = 1 + (i == 0 ? 0 : len[1][i - 1]);
		} else if (s[i] == '1') {
			len[1][i] = 1 + (i == 0 ? 0 : len[1][i - 1]);
		} else {
			len[0][i] = 1 + (i == 0 ? 0 : len[0][i - 1]);
		}
	}

	vector<int> lens(n);
	for (int i = 0; i < n; i++) {
		lens[i] = max(len[0][i], len[1][i]);
	}

	vector<int> p(n, n), st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && lens[st.back()] <= lens[i]) {
			st.pop_back();
		}
		if (!st.empty()) {
			p[i] = st.back();
		}
		st.push_back(i);
	}

	for (int x = 1; x <= n; x++) {
		auto find = [&](int i, const auto &self) -> int {
			return (i == n || lens[i] >= x ? i : p[i] = self(p[i], self));
		};

		int ans = 0;
		for (int i = 0; i + x <= n;) {
			int j = find(i + x - 1, find);
			if (j == n) {
				break;
			} else {
				ans += 1;
				i = j + 1;
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}