#include <bits/stdc++.h>
using namespace std;
int main () {
	int n, m; scanf("%d%d", &n, &m);
	vector <int> v(m), ll(m), len(m), ans(m);
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
	}
	int now = 1;
	for (int i = m - 1; i >= 0; i--) {
		ans[i] = max(1, now - v[i] + 1);
		now = max(now, ans[i] + v[i]);
		len[i] = now;
	}
	if (now - 1 > n) {
		printf("-1\n");
		return 0;
	}
	if (len[0] - 1 == n) goto END;
	now = n;
	for (int i = 0; i < m; i++) {
		if (len[i] >= now + 1) goto END;
		ans[i] = now - v[i] + 1;
		now = now - v[i];
	}
	printf("-1\n");
	return 0;
	END:;
	for (int i = 0; i < m; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}