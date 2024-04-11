#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, K = 20;
int dp[N][K];

int main() {
	for (int x = 1; x < N; x++) {
		for (int k = 0; k < K; k++) {
			dp[x][k] = dp[x-1][k] + !!(x & (1 << k));
		}
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		a--;
		int res = 1e9;
		for (int k = 0; k < K; k++) {
			res = min(res, (b-a) - (dp[b][k]-dp[a][k]));
		}
		cout << res << '\n';
	}
}