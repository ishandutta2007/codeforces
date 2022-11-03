#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	int64_t cost = 0;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		a[i] = ri();
		if (!a[i]) zero = true;
		if (a[i] <= 0) cost += std::abs(a[i] + 1), a[i] = -1;
		else cost += std::abs(a[i] - 1), a[i] = 1;
	}
	int all = 1;
	for (int i = 0; i < n; i++) all *= a[i];
	if (all == -1 && !zero) cost += 2;
	std::cout << cost << std::endl;
	return 0;
}