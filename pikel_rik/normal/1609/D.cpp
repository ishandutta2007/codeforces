#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p, r, e;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1), e(n) {
		std::iota(p.begin(), p.end(), 0);
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
		if (l1 == l2) {
			e[l1] += 1;
			return false;
		}
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			e[l1] += e[l2] + 1;
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
			e[l2] += e[l1] + 1;
		}
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;

	vector<int> x(d), y(d);
	for (int i = 0; i < d; i++) {
		cin >> x[i] >> y[i], --x[i], --y[i];
	}

	union_find uf(n);
	for (int i = 0; i < d; i++) {
		uf.merge(x[i], y[i]);

		int ans = 0, extra = 0, isolated = 0;

		vector<int> szs;
		for (int u = 0; u < n; u++) {
			if (u == uf.p[u]) {
				extra += uf.e[u] - (uf.r[u] - 1);
				szs.push_back(uf.r[u]);
				isolated |= uf.r[u] == 1;
			}
		}

		sort(szs.rbegin(), szs.rend());
		for (int j = 0; j < min((int) szs.size(), extra); j++) {
			ans += szs[j];
		}

		if (extra < (int) szs.size()) {
			ans += szs[extra] - 1;
		} else if (!isolated) {
			ans -= 1;
		}

		ans = max(ans, szs[0] - 1);
		cout << ans << '\n';
	}
	return 0;
}