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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>dp(N + 1, vector<int>(M + 1));
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
			if(s[i]==t[j])dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
		}
	}
	int ans = 0;
	for (auto i : dp)for (auto j : i)ans = max(ans, j);
	cout << ans << endl;
}