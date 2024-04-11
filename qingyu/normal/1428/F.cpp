#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::string s; int n;
	std::cin >> n >> s;
	long long ans = 0, delta = 0;
	std::vector<int> f(n + 1);
	int cur = 0;
	for (int i = 1; i <= n; ++i) f[i] = n;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '1') {
			++cur;
			delta += f[cur] - i;
		}
		else {
			while (cur) {
				f[cur] = i + cur;
				--cur;
			}
		}
		ans += delta;
	}
	std::cout << ans;
}