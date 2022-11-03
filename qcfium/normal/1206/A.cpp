#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	int m = ri();
	int b[m];
	for (int i = 0; i < m; i++) b[i] = ri();
	std::cout << *std::max_element(a, a + n) << " " << *std::max_element(b, b + m) << std::endl;
	return 0;
}