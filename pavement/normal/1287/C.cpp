#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, evcnt, oddcnt, arr[105], mem[105][105][105][2];
bool h[105];

int dp(int n, int a, int b, bool p) {
	if (a < 0 || b < 0) return 1e9;
	if (n == N) return 0;
	if (mem[n][a][b][p] != -1) return mem[n][a][b][p];
	int r;
	if (arr[n] && n) r = dp(n + 1, a, b, arr[n] & 1) + ((arr[n] & 1) != p);
	else if (arr[n] && !n) r = dp(n + 1, a, b, arr[n] & 1);
	else if (n) r = min(dp(n + 1, a - 1, b, 0) + p, dp(n + 1, a, b - 1, 1) + !p);
	else r = min(dp(n + 1, a - 1, b, 0), dp(n + 1, a, b - 1, 1));
	return mem[n][a][b][p] = r;
}

main() {
	memset(mem, -1, sizeof mem);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i], h[arr[i]] = 1;
	for (int i = 1; i <= N; i++) {
		if (!h[i]) {
			if (i & 1) oddcnt++;
			else evcnt++;
		}
	}
	cout << dp(0, evcnt, oddcnt, 0);
}