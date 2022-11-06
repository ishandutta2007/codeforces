#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, mem[1005][2005][2][2];
const int M = 998244353;

int dp(int n, int k, bool a, bool b) {
	if (k < 0) return 0;
	if (n == 0) return k == 0;
	if (mem[n][k][a][b] != -1) return mem[n][k][a][b];
	int r = 0;
	if (n == N) {
		r = dp(n - 1, k - 1, 0, 0) + dp(n - 1, k - 2, 1, 0) + dp(n - 1, k - 2, 0, 1) + dp(n - 1, k - 1, 1, 1);
	} else if (a && b) {
		r = dp(n - 1, k - 1, 0, 0) + dp(n - 1, k - 1, 1, 0) + dp(n - 1, k - 1, 0, 1) + dp(n - 1, k, 1, 1);
	} else if (a) {
		r = dp(n - 1, k, 0, 0) + dp(n - 1, k, 1, 0) + dp(n - 1, k - 2, 0, 1) + dp(n - 1, k, 1, 1);
	} else if (b) {
		r = dp(n - 1, k, 0, 0) + dp(n - 1, k - 2, 1, 0) + dp(n - 1, k, 0, 1) + dp(n - 1, k, 1, 1);
	} else {
		r = dp(n - 1, k, 0, 0) + dp(n - 1, k - 1, 1, 0) + dp(n - 1, k - 1, 0, 1) + dp(n - 1, k - 1, 1, 1);
	}
	return mem[n][k][a][b] = r % M;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	cout << dp(N, K, 0, 0) << '\n';
}