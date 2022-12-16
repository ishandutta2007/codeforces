#include <bits/stdc++.h>

int N;
std::vector <std::pair <int, int>> edge[110];

void dfs (int x, int f, double len) {
	double step = 2. / (edge[x].size ());
	double cur = len;
	for (int i = 0; i < edge[x].size (); ++i) {
		if (edge[x][i].first == f) continue;
		printf ("1 %d ", edge[x][i].second + 1);
		cur += step;
		if (cur > 1.) cur -= 2.;
		if (cur >= 0.) {
			printf ("%d %d %.10lf\n", x, edge[x][i].first, cur);
		} else {
			printf ("%d %d %.10lf\n", edge[x][i].first, x, 1 + cur);
		}
		dfs (edge[x][i].first, x, cur >= 0. ? cur - 1. : cur + 1.);
	}
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back (std::make_pair (v, i));
		edge[v].push_back (std::make_pair (u, i));
	}
	printf ("%d\n", N - 1);
	dfs (1, -1, 0.0);
}