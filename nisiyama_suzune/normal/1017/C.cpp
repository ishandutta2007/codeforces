#include <bits/stdc++.h>

int N;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	int val = 2E9, ans = 0;
	for (int i = 1; i <= 1000; ++i) {
		int lis = i, lds = N / i + (N % i > 0);
		if (val > lis + lds) val = lis + lds, ans = i;
	}
	for (int i = N; i >= 0; i -= ans)
		for (int j = std::max (1, i - ans + 1); j <= i; ++j)
			std::cout << j << " ";
}