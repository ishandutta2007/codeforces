#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100 * 1000 + 10;
LL cnt[maxn],
	dp[maxn],
	n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x] += x;
	}
	dp[1] = cnt[1];
	for (int i = 2; i < maxn; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i]);
	cout << dp[maxn - 1] << endl;
	return 0;
}