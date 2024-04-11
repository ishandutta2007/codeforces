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
		for (int i = 0; i < n; i++) printf("%d ", (i & 1) ? -std::abs(ri()) : std::abs(ri()));
		puts("");
	}
	return 0;
}