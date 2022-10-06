#include <cstdio>
#include <cstring>
#include <algorithm>

void Solve();
int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--)
		Solve();
	return 0;
}

typedef long long LL;

const LL Infll = 0x3f3f3f3f3f3f3f3f;

void chkmn(LL &x, LL y) {
	x = std::min(x, y);
}

const int MN = 5005;

int N, x, y;
int A[MN];
int p[MN], m;

void Solve() {
	scanf("%d%d%d", &N, &x, &y);
	for (int i = 1; i <= N; ++i)
		scanf("%1d", &A[i]);
	m = 0;
	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%1d", &x);
		if (A[i] ^ x)
			p[++m] = i;
	}
	if (m & 1)
		return puts("-1"), void();
	if (!m)
		return puts("0"), void();
	if (y <= x) {
		if (m == 2 && p[2] - p[1] == 1)
			printf("%d\n", std::min(x, 2 * y));
		else
			printf("%lld\n", m / 2ll * y);
		return ;
	}
	static LL f[3][MN];
	std::memset(f, 0x3f, sizeof f);
	int o = 0;
	f[o][0] = 0;
	for (int i = 1; i <= m; ++i) {
		++o %= 3;
		for (int j = 0; j <= i; ++j) {
			f[o][j] = Infll;
			if (j >= 1)
				chkmn(f[o][j], f[(o - 1 + 3) % 3][j - 1]);
			if (i >= 2)
				chkmn(f[o][j], f[(o - 2 + 3) % 3][j] + (LL)x * (p[i] - p[i - 1]));
			chkmn(f[o][j], f[(o - 1 + 3) % 3][j + 1] + y);
		}
	}
	printf("%lld\n", f[o][0]);
}