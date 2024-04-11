#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	std::string s;
	std::cin >> s;
	int q = ri();
	for (int i = 0; i < q; i++) {
		int l = ri() - 1;
		int r = ri();
		int k = ri() % (r - l);
		std::rotate(s.begin() + l, s.begin() + r - k, s.begin() + r);
	}
	std::cout << s << std::endl;
	return 0;
}