#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, a[N], cnt[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i], ++cnt[a[i]];
	int l = 0, r = 0, pl = -1, pr = -1, ans = 0, cur = 0;
	auto update = [&]() {
		if (ans < cur) {
			ans = cur;
			pl = l, pr = r;
		}
		cur = l = r = 0;
	};
	for (int i = 1; i <= 200'001; ++i) {
		if (!l) {
			if (cnt[i] > 0) {
				l = r = i, cur = cnt[i];
			}
		}
		else if (cnt[i] == 0) {
			r = i - 1;
			update();
		}
		else if (cnt[i] == 1) {
			r = i; cur += cnt[i];
			update();
			--i;
		}
		else {
			cur += cnt[i];
		}
	}
	std::cout << ans << '\n';
	for (int i = pl; i <= pr; ++i)
		for (int _ = 1; _ < cnt[i]; ++_)
			std::cout << i << " ";
	for (int i = pr; i >= pl; --i)
		std::cout << i << " ";
	std::cout << '\n';
	return 0;
}