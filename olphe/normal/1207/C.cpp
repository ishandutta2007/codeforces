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
#include "cassert"
#include "functional"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> L >> R;
		string s;
		cin >> s;
		long long int ans = L * N + (N + 1)*R;
		vector<vector<long long int>>dp(N+1,vector<long long int>(2,MOD*MOD));
		dp[0][0] = 0;
		for (int i = 1; i < N; i++) {
			if (s[i]=='1'||s[i-1] == '1') {
				dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + L) + R;
			}
			else {
				dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + L) + R;
				dp[i][0] = min(dp[i - 1][1] + L, dp[i - 1][0]);
			}
			//cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		}
		dp[N][0] = min(dp[N - 1][1] + L, dp[N - 1][0]);
	//	cout << ans << endl;
		cout << ans + dp.back()[0] << endl;
	}
}