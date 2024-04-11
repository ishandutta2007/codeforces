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

	constexpr int N = 300000;

	vector<vector<int>> div(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			div[j].push_back(i);
		}
	}

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> pos(N + 1, -1);
	for (int i = 0; i < n; i++) {
		pos[a[i]] = i;
	}

	vector<long long> ans(n);

	/* considering all a[i] < a[j], i < j */ {
		fenwick_tree<long long> ft(n);

		int total_inc = 0;
		for (int x = 1; x <= N; x++) {
			total_inc += 1;
			for (int d : div[x]) {
				if (pos[d] != -1) {
					ft.add(pos[d], -d);
				}
			}
			if (pos[x] != -1) {
				int i = pos[x];
				ans[i] = (long long) (i + 1) * total_inc + ft.query(i);
			}
		}
	}

	/* considering all a[i] > a[j], i < j */ {
		fenwick_tree<int> sum(N + 1);
		fenwick_tree<long long> isum(N + 1);

		auto query = [&](int l, int r) -> long long {
			long long ans = 0;
			ans += isum.query(r);
			ans -= isum.query(l - 1);
			ans -= (long long)l * sum.query(r);
			ans += (long long)l * sum.query(l - 1);
			return ans;
		};

		for (int i = 0; i < n; i++) {
			int x = a[i];
			for (int j = 0; j <= N; j += x) {
				ans[i] += query(j, min(N, j + x - 1));
			}
			sum.add(x, 1);
			isum.add(x, x);
		}
	}

	partial_sum(ans.begin(), ans.end(), ans.begin());

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}