#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		pair<int, int> a[n], b[n];
		for (int i = 0; i < n; i++) scanf("%d", &a[i].first), a[i].second = i;
		sort(a, a + n);
		if (n == 2 || m < n) {
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < n; i++)
			if (i % 2 == 0) b[i] = a[n - (i / 2) - 1];
			else b[i] = a[(i - 1) / 2];
		int tc = a[0].first + a[n - 1].first, minc = a[0].first + a[n - 1].first;
		for (int i = 0; i < n - 1; i++)
			tc += a[i].first + a[i + 1].first, minc = min(minc, a[i].first + a[i + 1].first);
		tc += minc * (m - n);
		printf("%d\n%d %d\n", tc, a[0].second + 1, a[n - 1].second + 1);
		for (int i = 0; i < n - 1; i++) {
			printf("%d %d\n", a[i].second + 1, a[i + 1].second + 1);
			if (a[i].first + a[i + 1].first == minc) {
				for (int j = 0; j < m - n; j++) printf("%d %d\n", a[i].second + 1, a[i + 1].second + 1);
				minc = 1e9;
			}
		}
	}
}