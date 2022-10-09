#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int cnt = 0;
		for (char ch : s) if (ch == 'N') ++cnt;
		puts(cnt != 1 ? "YES" : "NO");
	}
}