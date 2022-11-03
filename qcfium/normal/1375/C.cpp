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
		int a[n];
		for (auto &i : a) i = ri();
		puts(a[n - 1] > a[0] ? "YES" : "NO");
	}
	return 0;
}