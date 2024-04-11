#include <cstdio>
#include <cmath>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int Inv2 = (Mod + 1) / 2;
const int Inv6 = (Mod + 1) / 6;
const int MN = 55, MS = 1255;

int N, K;
int px[MN], py[MN];
int key[MS], cnt;

int Chebyshev(int a, int b) {
	return std::max(std::abs(px[a] - px[b]), std::abs(py[a] - py[b]));
}

LL getArea(int t) {
	static int x[MN * 2], y[MN * 2];
	int cx = 0, cy = 0;
	for (int i = 1; i <= N; ++i)
		x[++cx] = px[i] - t + 1,
		x[++cx] = px[i] + t,
		y[++cy] = py[i] - t + 1,
		y[++cy] = py[i] + t;
	std::sort(x + 1, x + cx + 1);
	cx = (int)(std::unique(x + 1, x + cx + 1) - x - 1);
	std::sort(y + 1, y + cy + 1);
	cy = (int)(std::unique(y + 1, y + cy + 1) - y - 1);
	static int cover[MN * 2][MN * 2];
	for (int i = 1; i <= cx; ++i)
		for (int j = 1; j <= cy; ++j)
			cover[i][j] = 0;
	for (int i = 1; i <= N; ++i) {
		int lx = (int)(std::lower_bound(x + 1, x + cx + 1, px[i] - t + 1) - x);
		int rx = (int)(std::lower_bound(x + 1, x + cx + 1, px[i] + t) - x);
		int ly = (int)(std::lower_bound(y + 1, y + cy + 1, py[i] - t + 1) - y);
		int ry = (int)(std::lower_bound(y + 1, y + cy + 1, py[i] + t) - y);
		++cover[lx][ly];
		--cover[lx][ry];
		--cover[rx][ly];
		++cover[rx][ry];
	}
	LL area = 0;
	for (int i = 1; i <= cx; ++i)
		for (int j = 1; j <= cy; ++j) {
			cover[i][j] += cover[i - 1][j] + cover[i][j - 1] - cover[i - 1][j - 1];
			if (cover[i][j]) area += (LL)(x[i + 1] - x[i]) * (y[j + 1] - y[j]);
		}
	return area;
}

int main() {
	scanf("%d%d", &N, &K), ++K;
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &px[i], &py[i]);
	key[cnt = 1] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			key[++cnt] = (Chebyshev(i, j) + 1) / 2;
	key[++cnt] = K;
	std::sort(key + 1, key + cnt + 1);
	cnt = (int)(std::unique(key + 1, key + cnt + 1) - key - 1);
	while (key[cnt] > K) --cnt;
//	for (int i = 1; i <= cnt; ++i) fprintf(stderr, "%d%s", key[i], i < cnt ? ", " : "\n");
	int answer = 0;
	for (int i = 2; i <= cnt; ++i) {
		int len = key[i] - key[i - 1];
		int area0 = (int)(getArea(key[i]) % Mod);
		if (i == cnt) answer = (int)((answer + (LL)area0 * (K/* + 1*/)) % Mod);
		if (len <= 3) {
			answer = (answer - area0 + Mod) % Mod;
			for (int t = key[i] - 1; t > key[i - 1]; --t)
				answer = (int)((answer - getArea(t) % Mod + Mod) % Mod);
		} else {
			int area1 = (int)(getArea(key[i] - 1) % Mod);
			int area2 = (int)(getArea(key[i] - 2) % Mod);
			// f(z) = a z^2 + b z + c
			// c = area0
			// a + b + c = area1
			// 4 a + 2 b + c = area2
			int c = area0;
			int b = (int)(((4ll * area1 - area2 - 3ll * area0) * Inv2 % Mod + Mod) % Mod);
			int a = (int)(((area2 - 2ll * area1 + area0) * Inv2 % Mod + Mod) % Mod);
			int sums = (int)((6ll * len % Mod * c + 3ll * len * (len - 1) % Mod * b + (LL)len * (len - 1) % Mod * (2 * len - 1) % Mod * a) % Mod * Inv6 % Mod);
			answer = (int)((answer - sums + Mod) % Mod);
		}
	}
	printf("%d\n", answer);
	return 0;
}