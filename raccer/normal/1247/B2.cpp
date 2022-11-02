#include <bits/stdc++.h>
using namespace std;

int cnt[1000010];
int a[200010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k, d; scanf("%d%d%d", &n, &k, &d);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int totot = 0;
		for (int i = 0; i < d; i++) {
			cnt[a[i]]++;
			if (cnt[a[i]] == 1) totot++;
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n - d; i++) {
			ans = min(ans, totot);
			cnt[a[i]]--;
			if (cnt[a[i]] == 0) totot--;
			cnt[a[i + d]]++;
			if (cnt[a[i + d]] == 1) totot++;
		}
		ans = min(ans, totot);
		for (int i = n - d; i < n; i++) {
			cnt[a[i]]--;
		}
		printf("%d\n", ans);
	}
	return 0;
}