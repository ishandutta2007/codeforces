#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

struct UnionFind {
	int n;
	vector<int> p, r;
	UnionFind() : n() {}
	UnionFind(int n) : n(n), p(n), r(n) {
		iota(p.begin(), p.end(), 0);
	}

	size_t size() const {
		return n;
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
		}
		else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		n--;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(k);
	for (auto& aa : a) cin >> aa, --aa;

	if (k == n) {
		cout << "-1\n";
		return 0;
	}

	sort(a.begin(), a.end());

	UnionFind f(n);
	vector<pair<int, int>> ans;
	for (int i = 2; i < a.size(); i++) {
		if (i & 1) {
			ans.emplace_back(a[1], a[i]);
			f.merge(a[1], a[i]);
		} else {
			ans.emplace_back(a[0], a[i]);
			f.merge(a[0], a[i]);
		}
	}

	vector<pair<int, int>> potential;
	for (int i = 0; i < n; i++) {
		if (!binary_search(a.begin(), a.end(), i)) {
			if (f.find(a[0]) != f.find(a[1])) {
				f.merge(a[0], i);
				f.merge(a[1], i);
				ans.emplace_back(a[0], i);
				ans.emplace_back(a[1], i);
			} else {
				potential.emplace_back(a[0], i);
				potential.emplace_back(a[1], i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == a[0] || i == a[1] || j == a[0] || j == a[1]) continue;
			potential.emplace_back(i, j);
		}
	}

	vector<pair<int, int>> extra;
	for (auto&[u, v] : potential) {
		if (f.merge(u, v)) {
			ans.emplace_back(u, v);
		} else {
			extra.emplace_back(u, v);
		}
	}

	m -= n - 1;

	if (m > extra.size()) {
		cout << "-1\n";
		return 0;
	}

	for (int i = 0; i < m; i++) {
		ans.push_back(extra[i]);
	}

	for (auto&[u, v] : ans) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
	return 0;
}