#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, m, a[N], b[N], f[N];
long long sl[N], sr[N];
std::vector<std::pair<int, int>> edges;
bool vis[N];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i], a[i] -= b[i];
	auto find = [&](int x) {
		while (x != f[x])
			x = f[x] = f[f[x]];
		return x;
	};
	auto connect = [&](int x, int y) {
		x = find(x), y = find(y);
		if (x != y) {
			f[x] = y;
			sl[y] += sl[x];
			sr[y] += sr[x];
			sl[x] = sr[x] = 0;
		}
	};
	for (int i = 1; i <= n; ++i) {
		f[i] = i, f[i + n] = i + n;
		sl[i] = sr[i + n] = a[i];
		sl[i + n] = sr[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		connect(u, v + n);
		connect(u + n, v);
	}
	std::vector<long long> sets;
	bool ok = true;
	long long total = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		int x = find(i);
		if (!vis[x]) {
			vis[x] = true;
			if (sl[x] != sr[x]) ok = false;
			sets.push_back(sl[x]);
			total += sl[x];
		}
	}
	std::sort(sets.begin(), sets.end());
	if (*sets.begin() != sets.back()) ok = false;
	if (total % 2) ok = false;
	puts(ok ? "YES" : "NO");
	for (int i = 1; i <= 2 * n; ++i) vis[i] = false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) solve();
	return 0;
}