#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, x; scanf("%d%d", &n, &x);
		int sum = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
		sort(a, a + n);
		int cur = 0, flag = 1;
		for (int i = 0; i < n; i++) {
			cur += a[i];
			if (cur == x) {
				for (int j = i + 1; j < n; j++) {
					if (a[j] != a[i]) {
						swap(a[j], a[i]);
						goto END;
					}
				}
				if (i + 1 < n) {
					for (int j = 0; j <= i; j++) {
						if (a[j] != a[i + 1]) {
							int tmp = a[j];
							for (int k = j; k + 1 < n; k++) a[k] = a[k + 1];
							a[n - 1] = tmp;
							goto END;
						}
					}
				}
				flag = 0;
				break;
			}
		}
		if (!flag) {
			printf("NO\n");
			continue;
		}
		END:;
		printf("YES\n");
		for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
	}
	return 0;
}