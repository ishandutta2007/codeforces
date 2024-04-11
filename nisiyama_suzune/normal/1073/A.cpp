#include <bits/stdc++.h>

std::string str;

int main () {
	std::ios::sync_with_stdio (0);
	int N;
	std::cin >> N >> str;
	for (int i = 0; i + 1 < str.size (); ++i) {
		if (str[i] != str[i + 1]) {
			std::cout << "YES\n" << str[i] << str[i + 1] << "\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}