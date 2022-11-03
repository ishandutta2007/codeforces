#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri(), m = ri();
	std::string s[n], t[m];
	for (auto &i : s) std::cin >> i;
	for (auto &i : t) std::cin >> i;
	int q = ri();
	for (int i = 0; i < q; i++) {
		int x = ri() - 1;
		std::cout << s[x % n] + t[x % m] << std::endl;
	}
	return 0;
}