#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		int cnt[10] = { 0 }, sum = 0;
		for (auto c : s) cnt[c - '0']++, sum += c - '0';
		const char *res;
		if (!cnt[0]) res = "cyan";
		else {
			cnt[0]--;
			if ((!cnt[0] && !cnt[2] && !cnt[4] && !cnt[6] && !cnt[8]) || sum % 3) res = "cyan";
			else res = "red";
		}
		std::cout << res << std::endl;
	}
	
	return 0;
}