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
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<int>>dp(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++)dp[i][i] = v[i];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j + i < N; j++) {
			for (int k = 0; k < i; k++) {
				if (dp[j][j + k] > 0 && dp[j][j + k] == dp[j + k + 1][j + i]) {
					dp[j][j + i] = dp[j][j + k] + 1;
				}
			}
		}
	}
	vector<int>ans(N + 1, MOD);
	ans[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (dp[i][j] > 0)ans[j + 1] = min(ans[j + 1], ans[i] + 1);
		}
	}
	cout << ans.back() << endl;
}