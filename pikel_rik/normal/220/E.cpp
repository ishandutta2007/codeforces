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

int compress(vector<int> &a) {
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &x : a) x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	return temp.size();
}

long long inversions(const vector<int> &a) {
	int n = int(a.size());
	fenwick_tree<int> ft(n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ft.add(a[i], 1);
		ans += ft.query(n - 1) - ft.query(a[i]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; long long k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int sz = compress(a);

	fenwick_tree<int> left(sz), right(sz);

	long long total_inv = inversions(a), now_inv = total_inv;
	long long ans = total_inv <= k;

	left.add(a[0], 1);
	for (int i = 1; i < n; i++) right.add(a[i], 1);

	for (int l = 0, r = 2; r < n; r++) {
		right.add(a[r - 1], -1);
		now_inv -= left.query(sz - 1) - left.query(a[r - 1]);
		now_inv -= right.query(a[r - 1] - 1);

		while (l + 1 < r) {
			long long temp = 0;
			temp += left.query(sz - 1) - left.query(a[l + 1]);
			temp += right.query(a[l + 1] - 1);
			if (now_inv + temp <= k) {
				left.add(a[++l], 1);
				now_inv += temp;
			} else {
				break;
			}
		}

		if (now_inv <= k) {
			ans += l + 1;
		}
	}

	cout << ans << '\n';
	return 0;
}