#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

int64_t gcd(int64_t a, int64_t b) {
	while (a && b) {
		if (a >= b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main() {
	int n = ri(), k = ri();
	std::string s[n];
	for (int i = 0; i < n; i++) std::cin >> s[i];
	
	int diff[n + 1][n + 1];
	memset(diff, 0, sizeof(diff));
	
	for (int i = 0; i < n; i++) {
		int min = n;
		int max = -1;
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'B') min = std::min(min, j), max = std::max(max, j);
		}
		if (max == -1) diff[0][0]++, diff[n][0]--, diff[0][n]--, diff[n][n]++;
		else if (max < min + k) {
			int x1 = std::max(0, i - k + 1);
			int x2 = i + 1;
			int y1 = std::max(0, max - k + 1);
			int y2 = min + 1;
			diff[x1][y1]++;
			diff[x1][y2]--;
			diff[x2][y1]--;
			diff[x2][y2]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int min = n;
		int max = -1;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == 'B') min = std::min(min, j), max = std::max(max, j);
		}
		if (max == -1) diff[0][0]++, diff[n][0]--, diff[0][n]--, diff[n][n]++;
		else if (max < min + k) {
			int x1 = std::max(0, i - k + 1);
			int x2 = i + 1;
			int y1 = std::max(0, max - k + 1);
			int y2 = min + 1;
			diff[y1][x1]++;
			diff[y2][x1]--;
			diff[y1][x2]--;
			diff[y2][x2]++;
		}
	}
	
	int res = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j < n; j++) diff[i][j + 1] += diff[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j <= n; j++) diff[i + 1][j] += diff[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) res = std::max(res, diff[i][j]);
	std::cout << res << std::endl;
	return 0;
}