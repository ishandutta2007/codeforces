#include <cstdio>
#include <algorithm>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MN = 10005;

int n, a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	puts(std::is_sorted(a + 1, a + n + 1) ? "NO" : "YES");
}