#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int k, n, maxb, t, b[N], mx, per[N], f[N];
pair <int,int> a[N];

void solve() {
	mx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[i] = make_pair(b[i], i);
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i].first != a[i - 1].first) mx++;
		b[a[i].second] = mx;
	}
	memset(f, 0x3f, sizeof f), f[0] = 0;
	memset(per, 0, sizeof per);
	int cnt = 0, st = 1;
	for (int i = 1; i <= t && i <= mx; i++)
		for (int j = 1; j <= n; j++) {
			int tmp = b[j];
			while (f[per[tmp]] < tmp)
				per[tmp]++;
			f[per[tmp]] = tmp;
		}
	int ans = 0;
	for (int i = 1; i <= mx; i++)
		ans = max(ans, per[i]);
	printf("%d\n", ans);
}

int main() {
	scanf("%d%d%d%d", &k, &n, &maxb, &t);
	for (int i = 1; i <= k; i++) solve();
	return 0;
}