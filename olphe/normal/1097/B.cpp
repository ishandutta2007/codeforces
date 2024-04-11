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

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>dp(N + 1, vector<int>(360));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		for (int j = 0; j < 360; j++) {
			dp[i][j] = dp[i - 1][(j + M) % 360] | dp[i - 1][(j - M + 360) % 360];
		}
	}
	if (dp.back()[0])cout << "YES\n";
	else cout << "NO\n";
	return 0;
}