#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, -1), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = -1;
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

		vector<int> l(n, -1);

		for (int rot = 0; rot < 2; rot++) {
			vector<int> b = a;
			sort(b.begin(), b.end());
			b.erase(unique(b.begin(), b.end()), b.end());
			int sz = (int) b.size();

			for (auto &x : a) {
				x = lower_bound(b.begin(), b.end(), x) - b.begin();
			}

			fenwick_tree<int> max_ind(sz, [&](auto x, auto y) {
				return x > y ? x : y;
			});

			fenwick_tree<int> max_pair(sz, [&](auto x, auto y) {
				return x > y ? x : y;
			});

			for (int i = 0; i < n; i++) {
				l[i] = max(l[i], max_pair.query(a[i]));
				int j = max_ind.query(a[i]);
				max_pair.add(a[i], j);
				max_ind.add(a[i], i);
			}

			for (auto &x : a) {
				x = -x;
			}
		}

		set<int> s;

		long long ans = 0;
		for (int i = 0, j = 0; i < n; i++) {
			s.insert(l[i]);
			while (j <= *s.rbegin()) {
				j += 1;
			}
			while (!s.empty() && *s.rbegin() < j) {
				s.erase(*s.rbegin());
			}
			ans += i - j + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}