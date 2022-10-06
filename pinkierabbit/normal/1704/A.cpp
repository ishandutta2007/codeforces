#include <cstdio>
#include <cstring>
#include <algorithm>

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MN = 55;

int n, m;
char a[MN], b[MN];

void Solve() {
	scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
	int k = n - m + 1;
	if (strcmp(a + k + 1, b + 2))
		return puts("NO"), void();
	char mn = *std::min_element(a + 1, a + k + 1);
	char mx = *std::max_element(a + 1, a + k + 1);
	puts(mn <= b[1] && b[1] <= mx ? "YES" : "NO");
}