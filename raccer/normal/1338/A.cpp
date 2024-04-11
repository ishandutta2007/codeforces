#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int now = a[0];
		int ans = -1;
		for (int i = 1; i < n; i++) {
			if (now <= a[i]) {
				now = a[i];
				continue;
			}
			int tmp = now - a[i];
			int cnt = 0;
			while (tmp) tmp >>= 1, cnt++;
			ans = max(ans, cnt - 1);
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}