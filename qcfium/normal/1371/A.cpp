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
		printf("%d\n", (n + 1) / 2);
	}
	return 0;
}