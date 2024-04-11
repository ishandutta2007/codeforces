#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> cache[10005];

int Solve(int n, int count) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return count == 0;
	}
	if (count == 0) {
		return 0;
	}
	auto it = cache[count].find(n);
	if (it != cache[count].end()) {
		return it->second;
	}
	for (int bits = n % 2; bits <= count && bits <= n; bits += 2) {
		if (Solve((n - bits) / 2, count - bits)) {
			return cache[count][n] = 1;
		}
	}
	return cache[count][n] = 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for (int count = 1; count <= 256; ++count) {
		if (Solve(n - p * count, count)) {
			printf("%d\n", count);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}