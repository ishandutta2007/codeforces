#include <cstdio>
#include <cmath>
#include <algorithm>

const int MN = 100005;

int N, X[MN], Y[MN];

void Solve() {
	scanf("%d", &N);
	int tx = 0, ty = 0;
	for (int i = 1; i <= 2 * N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (!x) Y[++ty] = std::abs(y);
		if (!y) X[++tx] = std::abs(x);
	}
	std::sort(X + 1, X + N + 1);
	std::sort(Y + 1, Y + N + 1);
	double Ans = 0;
	for (int i = 1; i <= N; ++i)
		Ans += std::hypot(X[i], Y[i]);
	printf("%.15f\n", Ans);
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) Solve();
	return 0;
}