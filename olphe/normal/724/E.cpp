#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	vector<long long int>dp(N + 1, MOD*MOD);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = N; j > 0; j--) {
			dp[j] = min(dp[j] + v[i]+j*K, dp[j - 1] + w[i]);
		}
		dp[0] = dp[0] + v[i];
	}
	long long int ans = MOD * MOD;
	for (int i = 0; i <= N; i++) {
		ans = min(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}