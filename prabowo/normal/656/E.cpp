#include <cstdio>
#include <algorithm>

const int N = 10;

int n;
int a[N][N];
int dist[N][N];

int inp (int x, int y) {
	return x < n ? y < n ? scanf ("%d", &a[x][y]) * inp(x, y + 1) : inp(x + 1, 0) : 0;
}

int floyd (int i, int j, int k) {
	return k < n ? i < n ? j < n ? (a[i][j] = std::min(a[i][j], a[i][k] + a[k][j])) * floyd(i, j + 1, k) : floyd(i + 1, 0, k) : floyd(0, 0, k + 1) : 0;
}

int solve (int i, int j) {
	return i < n ? j < n ? std::max(solve(i, j + 1), a[i][j]) : solve (i + 1, 0) : 0;
}

int main () {
	scanf ("%d", &n);
	inp(0, 0);
	floyd (0, 0, 0);
	printf ("%d\n", solve(0, 0));	
	return 0;
}