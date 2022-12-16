#include <bits/stdc++.h>

int N, M;
std::vector <std::pair <int, int>> vec;

void print (int x, int y) {
	printf ("%d %d\n", x, y);
	vec.push_back (std::make_pair (x, y));
}

void construct (int n, int m, int ox, int oy) {
	if (n <= 0 || m <= 0) return;
	if (n == 1) {
		for (int i = 0; i < m; ++i) if (i & 1)
			print (ox, oy + m - 1 - i / 2);
		else
			print (ox, oy + i / 2);
		return;
	}
	if (m == 1) {
		for (int i = 0; i < n; ++i) if (i & 1)
			print (ox + n - 1 - i / 2, oy);
		else
			print (ox + i / 2, oy);
		return;
	}
	for (int i = 0; i < n; ++i) {
		print (ox + i, oy);
		print (ox + n - 1 - i, oy + m - 1);
	}
/*
	for (int i = 1; i < m - 1; ++i) {
		printf ("%d %d\n", ox + n - 1, oy + i);
		printf ("%d %d\n", ox, oy + m - 1 - i);
	}
*/
	construct (n, m - 2, ox, oy + 1);
}

int main () {
	scanf ("%d%d", &N, &M);
	construct (N, M, 1, 1);
/*
	if (vec.size () != N * M) printf ("Size error.\n");
	for (int i = 1; i < N * M; ++i) for (int j = i + 1; j < N * M; ++j)
	 	if (vec[i + 1].first - vec[i].first == vec[j + 1].first - vec[j].first &&
	 		vec[i + 1].second - vec[i].second == vec[j + 1].second - vec[j].second)
			printf ("%d and %d conflicts.\n", i, j);
*/
}