// 10703

#include <cstdio>
#include <algorithm>
using std::scanf;
using std::printf;

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int Inf = 0x3f3f3f3f;

const int MN = 200005;

int n, x;
int a[MN];

void Solve() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	int mn = -Inf, mx = Inf;
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		mn = std::min(mn, a[i]);
		mx = std::max(mx, a[i]);
		if (mx - mn <= 2 * x)
			continue;
		++ans;
		mn = mx = a[i];
	}
	printf("%d\n", ans);
}