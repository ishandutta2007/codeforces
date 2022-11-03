#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) {
		int n = ri();
		int k = ri();
		std::string s;
		std::cin >> s;
		int weight[(k + 1) / 2][26];
		memset(weight, 0, sizeof(weight));
		for (int j = 0; j < n; j++) {
			int pos = std::min(j % k, k - 1 - j % k);
			weight[pos][s[j] - 'a']++;
		}
		int res = 0;
		for (int j = 0; j < (k + 1) / 2; j++)
			res += std::accumulate(weight[j], weight[j] + 26, 0) - *std::max_element(weight[j], weight[j] + 26);
		printf("%d\n", res);
	}
	return 0;
}