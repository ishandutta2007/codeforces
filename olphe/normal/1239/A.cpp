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
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<vector<long long int>>dp(W + 1, vector<long long int>(6));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 1; i < W; i++) {
		dp[i + 1][1] = dp[i][0];
		dp[i + 1][0] = dp[i][1];
		dp[i + 1][4] = dp[i][0] + dp[i][2];
		dp[i + 1][4] %= MOD;
		dp[i + 1][5] = dp[i][1] + dp[i][3];
		dp[i + 1][5] %= MOD;
		dp[i + 1][2] = dp[i][3] + dp[i][5];
		dp[i + 1][2] %= MOD;
		dp[i + 1][3] = dp[i][2] + dp[i][4];
		dp[i + 1][3] %= MOD;
	}
	long long int ans = dp.back()[2] + dp.back()[3] + dp.back()[4] + dp.back()[5];
	ans %= MOD;
	vector<vector<long long int>>box(H + 1, vector<long long int>(2));
	box[1][0] = dp.back()[0] + dp.back()[1];
	box[1][0] %= MOD;
	for (int i = 1; i < H; i++) {
		box[i + 1][0] = box[i][0] + box[i][1];
		box[i + 1][0] %= MOD;
		box[i + 1][1] = box[i][0];
	}
	//cout << ans << endl;
	ans += box.back()[0] + box.back()[1];
	ans %= MOD;
	cout << ans << endl;
	return 0;
}