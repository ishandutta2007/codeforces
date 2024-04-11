#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = 0;
		for (++i; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = 1e6 + 1;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> add(N), rem(N);
	vector<vector<pair<int, int>>> queries(N);

	long long ans = 1;

	for (int i = 0; i < n; i++) {
		int y, lx, rx;
		cin >> y >> lx >> rx;

		add[lx].push_back(y);
		rem[rx].push_back(y);
		if (lx == 0 && rx + 1 == N) {
			ans += 1;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, ly, ry;
		cin >> x >> ly >> ry;

		queries[x].emplace_back(ly, ry);
		if (ly == 0 && ry + 1 == N) {
			ans += 1;
		}
	}

	fenwick_tree<int> ft(N);

	for (int x = 0; x < N; x++) {
		for (int y : add[x]) {
			ft.add(y, 1);
		}
		for (auto &[y1, y2] : queries[x]) {
			ans += ft.query(y2) - ft.query(y1 - 1);
		}
		for (int y : rem[x]) {
			ft.add(y, -1);
		}
	}

	cout << ans << '\n';
	return 0;
}