#include <cstdio>
#include <algorithm>

const int MN = 205;

int R, G, B;
int r[MN], g[MN], b[MN];
int f[MN][MN][MN];

int DP(int x, int y, int z) {
	if ((!x) + (!y) + (!z) >= 2) return 0;
	int &v = f[x][y][z];
	if (v) return v;
	if (x && y) v = std::max(v, DP(x - 1, y - 1, z) + r[x] * g[y]);
	if (x && z) v = std::max(v, DP(x - 1, y, z - 1) + r[x] * b[z]);
	if (y && z) v = std::max(v, DP(x, y - 1, z - 1) + g[y] * b[z]);
	return v;
}

int main() {
	scanf("%d%d%d", &R, &G, &B);
	for (int i = 1; i <= R; ++i) scanf("%d", &r[i]);
	for (int i = 1; i <= G; ++i) scanf("%d", &g[i]);
	for (int i = 1; i <= B; ++i) scanf("%d", &b[i]);
	std::sort(r + 1, r + R + 1);
	std::sort(g + 1, g + G + 1);
	std::sort(b + 1, b + B + 1);
	printf("%d\n", DP(R, G, B));
	return 0;
}