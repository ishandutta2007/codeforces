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

	long long int a, b, c;
	cin >> N >> a >> b >> c >> K;
	vector<long long int>dp(N + 1, MOD*MOD);
	long long int ans = MOD * MOD;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	dp[1] = v[0] * a + c;
	dp[2] = 3 * K + min(b, a*v[0] + a) + a + min(min(b, a*v[1] + a) + a, a*v[1] + c);
	if (N == 2) {
		ans = 2 * K + a * v[1] + c + min(b, a*v[0]) + a;
	}
	for (int i = 1; i < N; i++) {
		if (i + 2 <= N) {
			dp[i + 2] = min(dp[i + 2], dp[i] + K * 4 + min(b, a*v[i] + a) + a + min(min(b, a*v[i + 1] + a) + a, a*v[i + 1] + c));
			if (i + 2 == N) {
				ans = min(ans, dp[i] + 3 * K + min(b, a*v[i] + a) + a + a * v[i + 1] + c);
			}
		}
		dp[i + 1] = min(dp[i + 1], dp[i] + min(c + v[i] * a + K, K * 3 + min(b, a*v[i] + a) + a));
	}
//	for (auto i : dp)cout << i << endl;
	cout << min(ans, dp.back()) << endl;
}