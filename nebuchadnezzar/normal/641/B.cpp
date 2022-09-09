#include <cstdio>
#include <algorithm>

int const N = 111;
int const Q = 11111;

int t[Q], r[Q], c[Q], x[Q];
int a[N][N];

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", t + i);
		if (t[i] == 1) {
			scanf("%d", r + i);
			--r[i];
		}
		if (t[i] == 2) {
			scanf("%d", c + i);
			--c[i];
		}
		if (t[i] == 3) {
			scanf("%d%d%d", r + i, c + i, x + i);
			--r[i], --c[i];
		}
	}
	for (int it = q - 1; it >= 0; --it) {
		if (t[it] == 3) {
			a[r[it]][c[it]] = x[it];
			continue;
		}
		if (t[it] == 1) {
			int i = r[it];
			std::rotate(a[i], a[i] + m - 1, a[i] + m);
			continue;
		}
		int j = c[it];
		int last = a[n - 1][j];
		for (int i = n - 2; i >= 0; --i) {
			a[i + 1][j] = a[i][j];
		}
		a[0][j] = last;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) printf("%d ", a[i][j]);
		puts("");
	}
}