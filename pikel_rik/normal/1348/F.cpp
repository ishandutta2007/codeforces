#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

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

int n, ans[N], inv[N];
vector<int> add[N];
pair<int, int> a[N];

struct comp {
	bool operator()(int i, int j) const {
		return a[i].second < a[j].second || (a[i].second == a[j].second && i < j);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		--a[i].first; --a[i].second;
		add[a[i].first].push_back(i);
	}

	set<int, comp> s;
	for (int i = 0; i < n; i++) {
		for (int j : add[i]) {
			s.insert(j);
		}
		int x = *s.begin();
		s.erase(s.begin());
		ans[x] = i;
		inv[i] = x;
	}

	vector<int> indices(n);
	iota(indices.begin(), indices.end(), 0);

	SparseTable<int> rmin(indices, n, [&] (int i, int j) {
		return a[inv[i]].first < a[inv[j]].first ? i : j;
	});

	SparseTable<int> rmax(indices, n, [&] (int i, int j) {
		return a[inv[i]].second > a[inv[j]].second ? i : j;
	});

	int d1 = -1, d2 = -1;
	for (int i = 0; i < n; i++) {
		if (ans[i] != a[i].first) {
			int x = rmax.query(a[i].first, ans[i] - 1);
			if (a[inv[x]].second >= ans[i]) {
				d1 = i, d2 = inv[x];
				break;
			}
		}
		if (ans[i] != a[i].second) {
			int x = rmin.query(ans[i] + 1, a[i].second);
			if (a[inv[x]].first <= ans[i]) {
				d1 = i, d2 = inv[x];
				break;
			}
		}
	}

	if (d1 == -1) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' '; cout << '\n';
	} else {
		cout << "NO\n";
		for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' '; cout << '\n';
		swap(ans[d1], ans[d2]);
		for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' '; cout << '\n';
	}
	return 0;
}