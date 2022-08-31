#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2)
			return false;
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		int ans = 0;
		union_find uf(n + 1);

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (x != y) {
				ans += 1 + !uf.merge(x, y);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}