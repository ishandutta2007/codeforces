#include <cstdio>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MN = 105;

int n, a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	int ans = 0;
	F(i, 1, n)
		ans += (a[i] ? 1 : 2) * i * (n - i + 1);
	printf("%d\n", ans);
}