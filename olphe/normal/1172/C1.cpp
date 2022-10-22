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

using namespace std;

//const long long int MOD = 1000000007;
//const long long int MOD = 1000003;
//const int MOD = 998244353;
const long long int MOD = 998244353;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	vector<vector<vector<long long int>>>dp(2, vector<vector<long long int>>(M + 1, vector<long long int>(M + 1)));
	vector<vector<long long int>>p(M + 1, vector<long long int>(M + 1));
	for (int i = 0; i < N; i++) {
		if (v[i])dp[1][0][0] += w[i];
		else dp[0][0][0] += w[i];
	}
	dp[0][0][0] %= MOD;
	dp[1][0][0] %= MOD;
	p[0][0] = 1;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= i; j++) {
			//	cout << i << " " << j << endl;
			int x = j, y = i - j;
			long long int sum;
			long long int by;
			if (x) {
				sum = dp[0][0][0] + MOD - x + 1 + dp[1][0][0] + y;
				sum %= MOD;
				by = (((dp[0][0][0]+MOD-(x-1)) % MOD)*power(sum, MOD - 2, MOD)) % MOD;
				by *= p[x - 1][y];
				by %= MOD;
				p[x][y] += by;
				p[x][y] %= MOD;
			}
			if (y) {
				sum = dp[0][0][0] + MOD - x + dp[1][0][0] + y - 1;
				sum %= MOD;
				by = (((dp[1][0][0]+y-1) % MOD)*power(sum, MOD - 2, MOD)) % MOD;
				by *= p[x][y - 1];
				by %= MOD;
				p[x][y] += by;
				p[x][y] %= MOD;
			}
		}
	}

	long long int sum0 = 0, sum1 = 0;
	for (int i = 0; i <= M; i++) {
		sum0 += (dp[0][0][0] + MOD - i) * p[i][M - i];
		sum0 %= MOD;
		sum1 += (dp[1][0][0] + M - i) * p[i][M - i];
		sum1 %= MOD;
	}
	for (int i = 0; i < N; i++) {
		if (v[i]) {
			long long int ret = sum1;
			ret *= w[i];
			ret %= MOD;
			ret *= power(dp[1][0][0], MOD - 2, MOD);
			ret %= MOD;
			cout << ret << "\n";
		}
		else {
			long long int ret = sum0;
			ret *= w[i];
			ret %= MOD;
			ret *= power(dp[0][0][0], MOD - 2, MOD);
			ret %= MOD;
			cout << ret << "\n";
		}
	}
}