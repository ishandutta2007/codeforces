#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::vector<std::vector<int>> pos(n + 1, std::vector<int>());
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			pos[a[i]].push_back(i);
		}
		int mp = n - 1, mq = 0, ans = 0;
		while (mp > 0 && a[mp - 1] <= a[mp]) --mp;
		auto erase = [&](int x) {
			if (pos[x].empty()) return;
			++ans;
			for (int y : pos[x]) {
				mq = std::max(mq, y);
				a[y] = 0;
			}
			pos[x].clear();
		};
		int p = 0;
		while (p < mp || p < mq) erase(a[p++]);
		std::cout << ans << '\n';
	}
	return 0;
}