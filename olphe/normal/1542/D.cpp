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
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<char>c(N);
	vector<int>v(N);
	long long ans = 0;
	for (int loop = 0; loop < N; loop++) {
		char cc;
		cin >> cc;
		if (cc == '-') {

		}
		else {
			cin >> K;
		}
		c[loop] = cc;
		v[loop] = K;
	}
	for (int i = 0; i < N; i++) {
		vector<long long>dp(N + 1);
		dp[1] = 1;
		if (c[i] == '-')continue;
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			vector<long long>nx(N + 1);
			if (c[j] == '-') {
				for (int k = 1; k <= N; k++) {
					nx[k] += dp[k];
					nx[k] %= MOD;
					if (j < i) {
						nx[max(1, k - 1)] += dp[k];
						nx[max(1, k - 1)] %= MOD;
					}
					else {
						nx[max(0, k - 1)] += dp[k];
						nx[max(0, k - 1)] %= MOD;
					}
				}
			}
			else {
				for (int k = 1; k < N; k++) {
					nx[k] += dp[k];
					nx[k] %= MOD;
					int add = 0;
					if (v[i] > v[j])add = 1;
					else if (v[i]==v[j]&&i > j)add = 1;
					nx[k + add] += dp[k];
					nx[k + add] %= MOD;
				}
			}
			dp = nx;
		}
		for (int j = 1; j <= N; j++) {
			ans += dp[j] * v[i] % MOD;
			ans %= MOD;
		}
	}
	cout << ans << endl;
}