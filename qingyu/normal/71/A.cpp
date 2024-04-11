#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	while (n--) {
		std::string s;
		std::cin >> s;
		if (s.length() <= 10) std::cout << s << '\n';
		else std::cout << s[0] << s.length() - 2 << s[s.length() - 1] << '\n';
	}
}