#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	std::string s;
	std::cin >> s;
	int level = 0;
	int res = 0;
	int last0 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') level++;
		else level--;
		if (level == 0) {
			if (s[i] == '(') res += i + 1 - last0;
			last0 = i + 1;
		}
	}
	if (level != 0) puts("-1");
	else printf("%d\n", res);
	return 0;
}