#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p, r, st;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		std::iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2) {
			st.push_back(-1);
			return false;
		}
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
			st.push_back(l2);
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
			st.push_back(l1);
		}
		c -= 1;
		return true;
	}

	bool roll_back() {
		int l = st.back();
		st.pop_back();
		if (l == -1) {
			return false;
		}
		r[p[l]] -= r[l];
		p[l] = l;
		c += 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;
	cin >> n >> q >> k;

	vector<int> count_query(q, -1);
	vector<vector<pair<int, int>>> queries(4 * q);

	auto add_edge = [&](int u, int v, int ql, int qr) -> void {
		auto recurse = [&](int i, int l, int r, const auto &self) -> void {
			if (r < ql || qr < l) {

			} else if (ql <= l && r <= qr) {
				queries[i].emplace_back(u, v);
			} else {
				int mid = (l + r) >> 1;
				self(i << 1, l, mid, self);
				self(i << 1 | 1, mid + 1, r, self);
			}
		};
		recurse(1, 0, q - 1, recurse);
	};

	int day = 0;
	vector<vector<tuple<int, int, int>>> days(1);

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int u, v;
			cin >> u >> v, --u, --v;
			if (u > v) {
				swap(u, v);
			}
			days[day].emplace_back(u, v, i);
		} else if (type == 2) {
			int z;
			cin >> z, --z;
			count_query[i] = z;
		} else {
			day += 1;
			if (day >= k) {
				for (auto &[u, v, j] : days[day - k]) {
					add_edge(u, v, j, i);
				}
			}
			days.emplace_back();
		}
	}

	for (int i = max(0, day - k + 1); i <= day; i++) {
		for (auto &[u, v, j] : days[i]) {
			add_edge(u, v, j, q - 1);
		}
	}

	union_find uf(n);
	auto dfs = [&](int i, int l, int r, const auto &self) -> void {
		for (auto &edge : queries[i]) {
			uf.merge(edge.first, edge.second);
		}
		if (l == r) {
			if (count_query[l] != -1) {
				cout << uf.r[uf.find(count_query[l])] << '\n';
			}
		} else {
			int mid = (l + r) >> 1;
			self(i << 1, l, mid, self);
			self(i << 1 | 1, mid + 1, r, self);
		}
		for (auto &edge : queries[i]) {
			uf.roll_back();
		}
	};

	dfs(1, 0, q - 1, dfs);
	return 0;
}