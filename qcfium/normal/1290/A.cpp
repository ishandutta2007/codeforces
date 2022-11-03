#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int t = ri();
	for (; t--; ) {
		int n = ri(), m = ri() - 1, k = ri();
		k = std::min(k, m);
		int a[n];
		for (auto &i : a) i = ri();
		int sub = (n - m - 1); // 
		int range = m - k; // up
		std::vector<int> all;
		for (int i = 0; i < n - sub; i++) all.push_back(std::max(a[i], a[i + sub]));
		int res = 0;
		for (int j = 0; j < (int) all.size() - range; j++) {
			int min = 1000000000;
			for (int k = j; k <= j + range; k++) {
				min = std::min(min, all[k]);
			}
			res = std::max(res, min);
		}
		printf("%d\n", res);
	}
	return 0;
}