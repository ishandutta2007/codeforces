#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, k;
int v[N];
int dp[N];
int cnt[N];

int getCnt(int l, int r) {
	if (l <= 0) {
		return cnt[r];
	}
	return cnt[r] - cnt[l - 1];
}

bool check(int u) {
	dp[0] = 1;
	cnt[0] = 1;
	v[0] = -1e9 - 20;
	int cur = 0;
	// cerr << u << endl;
	for (int i = 1; i <= n; i++) {
		while (v[i] - v[cur + 1] > u) {
			cur++;
		}
		int pos = i - k;
		if (pos < cur) {
			dp[i] = 0;
			cnt[i] = cnt[i - 1];
			continue;
		}
		int foo = getCnt(cur, pos);
		// cerr << i << " " << cur << " " << foo << endl;
		if (foo >= 1) {
			dp[i] = 1;
			cnt[i] = cnt[i - 1] + 1;
		} else {
			dp[i] = 0;
			cnt[i] = cnt[i - 1];
		}

	}
	// for (int i = 1; i <= n; i++) {
	// 	cerr << dp[i] << endl;
	// }
	return dp[n] == 1;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", v + i);
	}
	sort(v + 1, v + n + 1);
	int low = -1, high = 1e9 + 10;
	while (high - low > 1) {
		int mid = (1ll * high + low) >> 1ll;
		if (check(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high << endl;
	return 0;
}