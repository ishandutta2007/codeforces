#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	const pair<int, int> e = {INT_MAX, INT_MAX};
	vector<vector<pair<int, int>>> tree(9, vector<pair<int, int>>(4 * n, e));

	auto combine = [&](const pair<int, int> &p, const pair<int, int> &q) -> pair<int, int> {
		pair<int, int> r = e;
		for (auto val : {p.first, p.second, q.first, q.second}) {
			if (val < r.first) {
				r.second = r.first;
				r.first = val;
			} else if (val < r.second) {
				r.second = val;
			}
		}
		return r;
	};

	auto update = [&](int pos, int idx, int x) -> void {
		auto recurse = [&](int i, int l, int r, const auto &self) -> void {
			if (l == r) {
				tree[pos][i].first = x;
				tree[pos][i].second = INT_MAX;
			} else {
				int mid = (l + r) >> 1;
				if (idx <= mid) {
					self(i << 1, l, mid, self);
				} else {
					self(i << 1 | 1, mid + 1, r, self);
				}
				tree[pos][i] = combine(tree[pos][i << 1], tree[pos][i << 1 | 1]);
			}
		};
		recurse(1, 0, n - 1, recurse);
	};

	auto query = [&](int pos, int ql, int qr) -> pair<int, int> {
		pair<int, int> res = e;
		auto recurse = [&](int i, int l, int r, const auto &self) -> void {
			if (r < ql || qr < l) {

			} else if (ql <= l && r <= qr) {
				res = combine(res, tree[pos][i]);
			} else {
				int mid = (l + r) >> 1;
				self(i << 1, l, mid, self);
				self(i << 1 | 1, mid + 1, r, self);
			}
		};
		recurse(1, 0, n - 1, recurse);
		return res;
	};
	for (int i = 0; i < n; i++) {
		int temp = a[i];
		for (int j = 0; j < 9; j++) {
			if (temp % 10 != 0) {
				update(j, i, a[i]);
			}
			temp /= 10;
		}
	}

	while (m--) {
		int t;
		cin >> t;

		if (t == 1) {
			int i, x;
			cin >> i >> x, --i;

			int temp = x;
			for (int j = 0; j < 9; j++) {
				if (temp % 10 != 0) {
					update(j, i, x);
				} else {
					update(j, i, INT_MAX);
				}
				temp /= 10;
			}
		} else {
			int l, r;
			cin >> l >> r, --l, --r;

			int best = -1;
			for (int j = 0; j < 9; j++) {
				auto [mx1, mx2] = query(j, l, r);
				if (mx2 != INT_MAX && (best == -1 || mx1 + mx2 < best)) {
					best = mx1 + mx2;
				}
			}
			cout << best << '\n';
		}
	}
	return 0;
}