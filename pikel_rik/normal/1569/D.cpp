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

	int t;
	cin >> t;

	constexpr int N = 1000 * 1000;

	fenwick_tree<int> ftx(N + 1), fty(N + 1);

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> x(n);
		for (int i = 0; i < n; i++) cin >> x[i];

		vector<int> y(m);
		for (int i = 0; i < m; i++) cin >> y[i];

		long long ans = 0;

		vector<int> px(k), py(k), ux(k), uy(k);
		vector<bool> fx(k), fy(k);

		for (int i = 0; i < k; i++) {
			cin >> px[i] >> py[i];
			fx[i] = binary_search(x.begin(), x.end(), px[i]);
			fy[i] = binary_search(y.begin(), y.end(), py[i]);
			if (!fy[i]) {
				int j = upper_bound(y.begin(), y.end(), py[i]) - y.begin();
				ans += fty.query(y[j]) - fty.query(y[j - 1]);
				fty.add(py[i], 1), uy[i] = j;
			} else if (!fx[i]) {
				int j = upper_bound(x.begin(), x.end(), px[i]) - x.begin();
				ans += ftx.query(x[j]) - ftx.query(x[j - 1]);
				ftx.add(px[i], 1), ux[i] = j;
			}
		}

		vector<int> ind(k);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return px[i] < px[j] || (px[i] == px[j] && py[i] < py[j]);
		});

		auto sq = [&](long long x) -> long long {
			return (x * x - x) / 2;
		};

		int len = !fy[ind[0]];
		for (int i = 1; i < k; i++) {
			if (px[ind[i]] == px[ind[i - 1]] && uy[ind[i]] == uy[ind[i - 1]]) {
				len += !fy[ind[i]];
			} else {
				ans -= sq(len);
				len = !fy[ind[i]];
			}
		}
		ans -= sq(len);

		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return py[i] < py[j] || (py[i] == py[j] && px[i] < px[j]);
		});

		len = !fx[ind[0]];
		for (int i = 1; i < k; i++) {
			if (py[ind[i]] == py[ind[i - 1]] && ux[ind[i]] == ux[ind[i - 1]]) {
				len += !fx[ind[i]];
			} else {
				ans -= sq(len);
				len = !fx[ind[i]];
			}
		}
		ans -= sq(len);

		cout << ans << '\n';
		for (int i = 0; i < k; i++) {
			if (!fx[i]) {
				ftx.add(px[i], -1);
			} else if (!fy[i]) {
				fty.add(py[i], -1);
			}
		}
	}
	return 0;
}