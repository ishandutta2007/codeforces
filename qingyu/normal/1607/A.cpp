#include <bits/stdc++.h>

int pos[1 << 8];

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		std::string t, s;
		std::cin >> t >> s;
		int ans = 0;
		for (int i = 0; i < t.length(); ++i)
			pos[t[i]] = i;
		for (int i = 0; i + 1 < s.length(); ++i)
			ans += std::abs(pos[s[i]] - pos[s[i + 1]]);
		std::cout << ans << '\n';
	}
}