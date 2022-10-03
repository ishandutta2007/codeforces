#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int Inv2 = (Mod + 1) / 2;
const int Inv8 = (Mod + 1) / 8;
const int Inv24 = (Mod + 1) / 24;

int g[6][6];
inline int f1(int x) {
	int ret = 0;
	if (x < 3) ret = 0;
	else if (x & 1) ret = ((3ll * x * x % Mod * x + 2ll * x * x - 3ll * x - 18) % Mod + Mod) * Inv8 % Mod;
	else ret = ((3ll * x * x % Mod * x + 2ll * x * x - 4ll * x - 16) % Mod + Mod) * Inv8 % Mod;
	return ret;
}
inline int fk(int x, int y) {
	int z = x + y, ret = 0;
	int w = z / 3;
	if (z % 3 == 1) ++w, ret = ((3ll * w * w % Mod * w - 3ll * w * w + 2ll * w) % Mod + Mod) * Inv2 % Mod;
	if (z % 3 == 0) ret = ((3ll * w * w % Mod * w + 3ll * w * w + 2ll * w) % Mod + Mod) * Inv2 % Mod;
	if (z % 3 == 2) ret = ((3ll * w * w % Mod * w + 9ll * w % Mod * w + 10ll * w + 4) % Mod + Mod) * Inv2 % Mod;
	return ret;
}
int f2(int x, int y) {
	if (x > y) std::swap(x, y);
	if (x < 3) return 0;
	if (y <= 5) return g[x][y];
	int ret = (f1(x / 2) + f1(y / 2)) % Mod;
	ret = (ret - f2(x / 2, y / 2) + Mod) % Mod;
	ret = (ret + fk(x, y)) % Mod;
	ret = (ret - fk(y / 2, y) + Mod) % Mod;
	ret = (ret - fk(x, x / 2) + Mod) % Mod;
	ret = (ret + fk(y / 2, x / 2)) % Mod;
	return ret;
}
inline int f3(int y) {
	int d = 0;
	if (~y & 1) ++y, d = 1;
	int ret = ((2ll * y * y % Mod * y - 9ll * y % Mod * y - 26ll * y + 105) % Mod + Mod) * Inv24 % Mod;
	if (d) {
		int q = (LL)((y - 2) / 4) * ((y + 1) / 2) % Mod;
		q = (q + (LL)((y - 4) / 4) * (y / 2)) % Mod;
		ret = (ret - q + Mod) % Mod;
	}
	return ret;
}
inline int f4(int x, int y) {
	int ret = f3(y);
	int z = y - (x - 2) * 2;
	int q = f3(z);
	int d = 0;
	if (~z & 1) ++z, d = 1;
	int q2 = (LL)(z / 2 - 1) * (z / 2 - 2) % Mod;
	if (d) q2 = (q2 - (z - 5) / 2 + Mod) % Mod;
	q = (q + (LL)q2 * (x - 2)) % Mod;
	ret = (ret - q + Mod) % Mod;
	return ret;
}
inline int f(int x, int y) {
	if (x > y) std::swap(x, y);
	if (x < 3) return 0;
	if (x * 2 <= y) return ((LL)f1(x) + f4(x, y) + f3(x)) % Mod;
	else return ((LL)f2(x, y) + f3(y) + f3(x)) % Mod;
}

int main() {
	g[3][3] = 4;
	g[3][4] = 7;
	g[3][5] = 9;
	g[4][4] = 12;
	g[4][5] = 17;
	g[5][5] = 26;
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		int X, Y, N, M;
		scanf("%d%d%d%d", &X, &Y, &N, &M);
		int Ans = f(N, M);
		Ans = (Ans - f(X - 1, M) + Mod) % Mod;
		Ans = (Ans - f(N, Y - 1) + Mod) % Mod;
		Ans = (Ans + f(X - 1, Y - 1)) % Mod;
		printf("%d\n", Ans);
	}
	return 0;
}