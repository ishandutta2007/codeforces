#include <bits/stdc++.h>

const int N = 1e5 + 50;
int n, a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		std::vector<std::vector<int>> vec(n + 1, std::vector<int>());
		int l = 0, r = 0;
		while (l < n) {
			r = l;
			while (r + 1 < n && a[r] == a[r + 1]) ++r;
			vec[r - l + 1].push_back(a[l]);
			l = r + 1;
		}
		std::vector<int> pts;
		for (int i = 0; i <= n; ++i)
			if (!vec[i].empty()) {
				pts.push_back(i);
				std::sort(vec[i].begin(), vec[i].end(), std::greater<int>());
			}
		long long ans = 0;
		std::set<std::pair<int, int>> set;
		for (int i = 0; i < m; ++i) {
			int x, y;
			std::cin >> x >> y;
			set.emplace(x, y);
			set.emplace(y, x);
		}
		for (int i = 0; i < pts.size(); ++i) {
			for (int x : vec[pts[i]]) {
				for (int j = 0; j <= i; ++j) {
					for (int t : vec[pts[j]])
						if (t != x && !set.count(std::make_pair(t, x))) {
							ans = std::max(ans, 1ll * (pts[i] + pts[j]) * (t + x));
							break;
						}
				}
			}
		}
		std::cout << ans << '\n';
	}
}