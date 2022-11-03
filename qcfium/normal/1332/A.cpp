#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) {
		int a = ri();
		int b = ri();
		int c = ri();
		int d = ri();
		int x = ri();
		int y = ri();
		int x0 = ri();
		int y0 = ri();
		int x1 = ri();
		int y1 = ri();
		if (x0 == x1 && (a || b)) puts("NO");
		else if (y0 == y1 && (c || d)) puts("NO");
		else if (x - x0 >= a - b && x1 - x >= b - a &&
			y - y0 >= c - d && y1 - y >= d - c) {
			puts("YES");
		} else puts("NO");
	}
	return 0;
}