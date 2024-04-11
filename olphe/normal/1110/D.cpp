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

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>num(M + 1);
	for (int i = 0; i < N; i++) {
		cin >> K;
		num[K]++;
	}
	vector<vector<int>>dp(M + 1, vector<int>(36, -MOD));
	for (int i = 0; i < 6; i++)if (num[1] >= i)dp[1][i] = (num[1] - i) / 3;
	if (M == 1) {
		cout << dp[1][0] << endl;
		return 0;
	}
	for (int i = 0; i<6; i++) {
		for (int j = 0; j < 6; j++) {
			if (num[2] >= i)dp[2][j * 6 + i] = (num[2] - i) / 3 + dp[1][j];
		}
	}
	if (M == 2) {
		cout << dp[2][0] << endl;
		return 0;
	}
	for (int i = 3; i <= M; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 36; k++) {
				int bb = k / 6;
				int b = k % 6;
				int minus = min({ bb,b,num[i] - j ,2 });
				if (minus >= 0 && num[i] >= minus + j)dp[i][(k % 6 - minus) * 6 + j] = max(dp[i][(k % 6 - minus) * 6 + j], (num[i] - minus - j) / 3 + dp[i - 1][k] + minus);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 36; i++)ans = max(ans, dp.back()[i]);
	cout << ans << endl;
}