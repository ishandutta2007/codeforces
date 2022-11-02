#include <bits/stdc++.h>
using namespace std;

int a[200010], cnt[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, L, R; scanf("%d%d%d", &n, &L, &R);
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < L; i++) cnt[a[i]]++;
		for (int i = L; i < n; i++) cnt[a[i]]--;
		int ans = 0, lc = 0, rc = 0, ll = 0, rr = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] > 0) ll += cnt[i], lc += cnt[i] / 2;
			else rr += -cnt[i], rc += (-cnt[i]) / 2;
		}
		while (lc && ll > rr) lc--, ll -= 2, ans++;
		while (rc && ll < rr) rc--, rr -= 2, ans++;
		if (ll == rr) ans += ll;
		else ans += (abs(rr - ll) >> 1) + (ll + rr >> 1);
		printf("%d\n", ans);
	}
	return 0;
}