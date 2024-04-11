#include <bits/stdc++.h>

int N, M;
std::vector <std::pair <int, char>> edge[110];
int mem[110][110][26][2];

int search (int a, int b, char c, int v) {
	int &res = mem[a][b][c - 'a'][v];
	if (res >= 0) return res;
	if (v == 0) {
		res = 0;
		for (auto d : edge[a])
			if (d.second >= c) res = std::max (res, search (d.first, b, d.second, 1));
	} else {
		res = 1;
		for (auto d : edge[b])
			if (d.second >= c) res = std::min (res, search (a, d.first, d.second, 0));
	}
	return res;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v; char c;
		std::cin >> u >> v >> c;
		edge[u].push_back ({v, c});
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			for (int k = 0; k < 26; ++k)
				mem[i][j][k][0] = mem[i][j][k][1] = -1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			std::cout << (char) ('B' - search (i, j, 'a', 0));
		std::cout << std::endl;
	}
}