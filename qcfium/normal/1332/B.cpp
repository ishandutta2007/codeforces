#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 31};
	int t = ri();
	for (int i = 0; i < t; i++) {
		int n = ri();
		int a[n];
		for (auto &i : a) i = ri();
		std::vector<int> res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 11; j++) if (a[i] % primes[j] == 0) {
				res[i] = j + 1;
				break;
			}
		}
		std::map<int, int> all;
		for (auto i : res) all[i];
		int cnt = 0;
		for (auto &i : all) i.second = cnt++;
		printf("%d\n", cnt);
		for (auto j : res) printf("%d ", all[j] + 1);
		puts("");
	}
	return 0;
}