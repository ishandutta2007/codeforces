#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p;
	std::vector<std::vector<int>> v;

	union_find(): n(), c() {}
	union_find(int n): n(n), c(n), p(n), v(n) {
		for (int i = 0; i < n; i++) p[i] = i, v[i] = {i};
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return p[x];
	}

	bool merge(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 == s2)
			return false;
		if (v[s2].size() > v[s1].size())
			std::swap(s1, s2);
		for (int i : v[s2]) {
			v[s1].push_back(i);
			p[i] = s1;
		}
		v[s2].clear();
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	union_find uf(n * m);
	for (int i = 0; i < n; i++) {
		map<int, int> last;
		for (int j = 0; j < m; j++) {
			auto &pos = last[a[i][j]];
			if (pos != 0 || (pos == 0 && a[i][0] == a[i][j])) {
				uf.merge(i * m + pos, i * m + j);
			}
			pos = j;
		}
	}

	for (int j = 0; j < m; j++) {
		map<int, int> last;
		for (int i = 0; i < n; i++){
			auto &pos = last[a[i][j]];
			if (pos != 0 || (pos == 0 && a[0][j] == a[i][j])) {
				uf.merge(pos * m + j, i * m + j);
			}
			pos = i;
		}
	}

	vector<int> v;
	v.reserve(n * m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (uf.p[i * m + j] == i * m + j) {
				v.push_back(i * m + j);
			}
		}
	}

	sort(v.begin(), v.end(), [&](int i, int j) {
		return a[i / m][i % m] < a[j / m][j % m];
	});

	vector<int> row(n), col(m);
	vector<vector<int>> ans(n, vector<int>(m));

	for (int l : v) {
		int mx = 0;
		for (int x : uf.v[l]) {
			int i = x / m, j = x % m;
			mx = max({mx, row[i], col[j]});
		}
		for (int x : uf.v[l]) {
			int i = x / m, j = x % m;
			ans[i][j] = 1 + mx;
			row[i] = col[j] = 1 + mx;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}