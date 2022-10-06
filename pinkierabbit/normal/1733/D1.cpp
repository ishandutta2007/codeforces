#include <cstdio>
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

const int MN = 3005;

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
	if (m == 2 && p[2] - p[1] == 1)
		return printf("%d\n", std::min(x, 2 * y)), void();
	printf("%lld\n", m / 2ll * y);
}