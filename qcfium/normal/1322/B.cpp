#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int n = ri();
	std::vector<int> a(n);
	for (auto &i : a) i = ri();
	int res = 0;
	for (int i = 24; i >= 0; i--) {
		std::vector<int> b = a;
		for (auto &j : b) j &= (1 << (i + 1)) - 1;
		std::sort(b.begin(), b.end());
		auto lr = [&] (int l, int r, int upper) { return std::lower_bound(b.begin(), b.begin() + upper, r) - std::lower_bound(b.begin(), b.begin() + upper, l); };
		int cur = 0;
		for (int j = 0; j < n; j++) {
			cur += lr((1 << i) - b[j], (2 << i) - b[j], j);
			cur += lr((3 << i) - b[j], (4 << i) - b[j], j);
		}
		if (cur & 1) res |= 1 << i;
	}
	printf("%d\n", res);
	return 0;
}