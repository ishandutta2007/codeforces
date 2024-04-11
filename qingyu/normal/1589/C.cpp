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
		std::vector<int> a(n), b(n), cnta(205), cntb(205);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			++cnta[a[i] + 100];
		}
		for (int i = 0; i < n; ++i) {
			std::cin >> b[i];
			++cntb[b[i] + 100];
		}
		bool ok = true;
		for (int i = 0; i <= 200; ++i) {
			if (i > 0 && cnta[i - 1] > 0) {
				int t = std::min(cnta[i - 1], cntb[i]);
				cnta[i - 1] -= t, cntb[i] -= t;
				if (cnta[i - 1] != 0) {
					ok = false;
					break;
				}
			}
			int t = std::min(cnta[i], cntb[i]);
			cnta[i] -= t, cntb[i] -= t;
			if (cntb[i] > 0) {
				ok = false;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
}