#include <bits/stdc++.h>
using namespace std;

long long pre[100010];
int c[100010], a[100010], b[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		pre[0] = -0x3f3f3f3f3f3f3f3f;
		long long ans = -0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i < n; i++) {
			int l = a[i + 1], r = b[i + 1];
			if (l > r) swap(l, r);
			int len = r - l + 1;
			if (l == r) pre[i] = 1;
			else pre[i] = max(pre[i - 1] + c[i] - len + 2, (long long)len);
			ans = max(ans, pre[i] + c[i + 1]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}