#include <bits/stdc++.h>

int N;
std::pair <int, int> sc[11000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int u, v, w, x;
		std::cin >> u >> v >> w >> x;
		sc[i].first = -(u + v + w + x);
		sc[i].second = i;
	}
	std::sort (sc, sc + N);
	for (int i = 0; i < N; ++i) {
		if (sc[i].second == 0) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}