#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<typename T>
struct SparseTable {
	using F = function<T(const T&, const T&)>;

	int n;
	vector<vector<T>> mat;
	F f;
	SparseTable() : n(), f() {}

	template<typename U>
	SparseTable(const U& arr, int n, F f): n(n), f(f), mat((int) log2(n) + 1) {
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

		vector<int> a(n);
		for (auto& item : a) cin >> item;

		SparseTable<int> rmin(a, n, [&] (int x, int y) {
			return x < y ? x : y;
		});

		SparseTable<int> rmax(a, n, [&] (int x, int y) {
			return x > y ? x : y;
		});

		array<int, 3> ans = {-1, -1, -1};

		int cur = 0;
		for (int i = 0; i < n - 2; i++) {
			cur = max(cur, a[i]);
			int lo = i + 1, hi = n - 2;
			while (lo < hi) {
				int mid = lo + (hi - lo + 1) / 2;
				if (rmin.query(i + 1, mid) >= cur)
					lo = mid;
				else hi = mid - 1;
			}

			if (rmin.query(i + 1, lo) != cur) continue;
			if (rmax.query(lo + 1, n - 1) > cur) continue;

			if (rmax.query(lo + 1, n - 1) == cur) {
				ans = {i, lo, n - 1};
				break;
			} else if (lo != i + 1 && a[lo] == cur && rmin.query(i + 1, lo - 1) == cur) {
				ans = {i, lo - 1, n - 1};
				break;
			}
		}

		if (ans[0] == -1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << ans[0] + 1 << ' ' << (ans[1] - ans[0]) << ' ' << (ans[2] - ans[1]) << '\n';
		}
	}
	return 0;
}