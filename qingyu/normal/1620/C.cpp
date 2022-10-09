#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, k; long long x;
		std::cin >> n >> k >> x;
		std::string s, t = "";
		std::cin >> s;
		std::vector<int> d, cnt;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '*') {
				if (i && s[i - 1] == '*') {
					d.back() += k;
				}
				else {
					d.push_back(k + 1);
					cnt.push_back(0);
					t += s[i];
				}
			}
			else {
				t += s[i];
			}
		}
		int m = d.size();
		--x;
		for (int i = m - 1; i >= 0; --i) {
			cnt[i] = x % d[i];
			x /= d[i];
			if (!x) break;
		}
		int p = 0;
		for (char ch : t) {
			if (ch == 'a') {
				putchar('a');
			}
			else {
				assert(p < cnt.size());
				for (int j = 0; j < cnt[p]; ++j) {
					putchar('b');
				}
				++p;
			}
		}
		putchar('\n');
	}
}