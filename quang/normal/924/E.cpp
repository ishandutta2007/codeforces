#include <bits/stdc++.h>

using namespace std;

const int N = 10010, INF = 1e9;

int n, l, r;
pair<int, int> a[N];
int dp[N];

bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.second != v.second) {
		return u.second < v.second;
	}
	return u.first > v.first;
}

int main() {
	scanf("%d %d %d", &n, &l, &r);
	int h = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first);
		h += a[i].first;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].second);
	}
	tie(l, r) = pair<int, int>(h - r, h - l);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 0; i <= r; i++) {
		dp[i] = -INF;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = r - a[i].first; j >= 0; j--) {
			dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second * (j + a[i].first >= l));
		}
	}
	cout << *max_element(dp, dp + r + 1) << endl;
	return 0;
}