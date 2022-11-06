#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, q;
int a[maxn + 10], cnt[maxn + 10];
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 1) {
			--cnt[a[y]];
			a[y] = 1 - a[y];
			++cnt[a[y]];
		} else {
			printf("%d\n", y <= cnt[1]);
		}
	}
}