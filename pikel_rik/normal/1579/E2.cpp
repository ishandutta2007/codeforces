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

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> b = a;
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		int sz = (int) b.size();

		for (auto &x : a) {
			x = lower_bound(b.begin(), b.end(), x) - b.begin();
		}

		fenwick_tree<int> ft(sz);

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int less = (a[i] == 0 ? 0 : ft.query(a[i] - 1));
			int equal = ft.query(a[i]) - less;
			int greater = i - less - equal;
			ans += min(less, greater);
			ft.add(a[i], 1);
		}

		cout << ans << '\n';
	}
	return 0;
}