#include <bits/stdc++.h>

int N, M;
char map[60][60];
long long bt[60];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			std::cin >> map[i][j];
			if (map[i][j] == '#') bt[i] |= (1ll << j);
		}
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			if (((bt[i] & bt[j]) != 0ll) && (bt[i] != bt[j])) {
				std::cout << "No\n";
				return 0;
			}
	std::cout << "Yes\n";
}