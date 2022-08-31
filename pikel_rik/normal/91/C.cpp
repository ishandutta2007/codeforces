#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 9;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

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

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	int ans = 1;
	UnionFind f(n);

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v; --u; --v;
		if (!f.merge(u, v)) {
			ans = 2 * ans % mod;
		}
		cout << (ans + mod - 1) % mod << '\n';
	}
	return 0;
}