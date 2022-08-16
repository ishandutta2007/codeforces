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

	int n, T;
	cin >> n >> T;

	vector<int> t(4 * n, -1);
	auto query = [&](int i, int l, int r) -> int {
		if (t[i] == -1) {
			cout << "? " << l + 1 << ' ' << r + 1 << endl;
			cin >> t[i];
		}
		return t[i];
	};

	auto find_kth = [&](int k) -> int {
		query(1, 0, n - 1);
		auto recurse = [&](int i, int l, int r, const auto &self) -> int {
			if (l == r)
				return l;
			int mid = (l + r) >> 1;
			t[i << 1 | 1] = t[i] - query(i << 1, l, mid);
			if ((mid - l + 1) - t[i << 1] >= k)
				return self(i << 1, l, mid, self);
			k -= (mid - l + 1) - t[i << 1];
			return self(i << 1 | 1, mid + 1, r, self);
		};
		return recurse(1, 0, n - 1, recurse);
	};

	auto update = [&](int idx) -> void {
		auto recurse = [&](int i, int l, int r, const auto &self) -> void {
			if (l == r)
				return;
			t[i] += 1;
			int mid = (l + r) >> 1;
			if (idx <= mid)
				self(i << 1, l, mid, self);
			else self(i << 1 | 1, mid + 1, r, self);
		};
		recurse(1, 0, n - 1, recurse);
	};

	while (T--) {
		int k;
		cin >> k;

		int pos = find_kth(k);
		cout << "! " << pos + 1 << endl;
		update(pos);
	}
	return 0;
}