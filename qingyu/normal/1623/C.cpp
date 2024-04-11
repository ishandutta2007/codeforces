#include <bits/stdc++.h>

void solve() {
	int n;
	scanf("%d", &n);
	std::vector<int> h(n);
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
	int l = *std::min_element(h.begin(), h.end());
	int r = *std::max_element(h.begin(), h.end());
	int ans = l;
	std::function<bool(int)> check = [&](int mid) -> bool {
		std::vector<int> cur = h;
		for (int i = cur.size() - 1; i >= 0; --i) {
			int delta = std::min(h[i], cur[i] - mid);
			if (delta < 0) return false;
			if (i >= 2) {
				delta /= 3;
				cur[i - 2] += delta * 2;
				cur[i - 1] += delta;
			}
		}
		return true;
	};
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}