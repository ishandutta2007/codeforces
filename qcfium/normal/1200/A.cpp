#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	bool used[10] = { 0 };
	std::string s;
	std::cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			for (int i = 0; i < 10; i++) {
				if (!used[i]) {
					used[i] = true;
					break;
				}
			}
		} else if (s[i] == 'R') {
			for (int i = 9; i >= 0; i--) {
				if (!used[i]) {
					used[i] = true;
					break;
				}
			}
		} else {
			used[s[i] - '0'] = false;
		}
	}
	for (int i = 0; i < 10; i++) putchar(used[i] + '0');
	return 0;
}