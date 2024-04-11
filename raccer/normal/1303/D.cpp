#include <bits/stdc++.h>
using namespace std;

int cnt[50];
int a[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		long long n; int m; scanf("%I64d%d", &n, &m);
		long long sum = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
			int tmp = 0;
			while (a[i] > 1) tmp++, a[i] >>= 1;
			cnt[tmp]++;
		}
		if (sum < n) {
			printf("-1\n");
			continue;
		}
		int ans = 0, now = 0;
		while (n) {
			if (n & 1) {
				int i = now;
				while (!cnt[i]) i++;
				cnt[i]--;
				for (int j = now; j < i; j++) {
					cnt[j]++;
				}
				ans += i - now;
			}
			cnt[now + 1] += cnt[now] >> 1;
			n >>= 1, now++;
		}
		printf("%d\n", ans);
	}
	return 0;
}