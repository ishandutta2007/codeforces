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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x % M;
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

void Solve() {
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		while (v[i] % 2 == 0) {
			v[i] /= 2;
			w[i]++;
		}
	}
	vector<vector<long long>>dp(30, vector<long long>(2));
	for (auto i : w) {
		if (i == 0)continue;
		vector<vector<long long>>nxdp(30, vector<long long>(2));
		nxdp[i][1] = 1;
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k < 2; k++) {
				nxdp[j][k] += dp[j][k];
				nxdp[j][k] %= MOD;
				if (i < j) {
					nxdp[i][1] += dp[j][k];
					nxdp[i][1] %= MOD;
				}
				else if (i == j) {
					nxdp[j][k ^ 1] += dp[j][k];
					nxdp[j][k ^ 1] %= MOD;
				}
				else {
					nxdp[j][k] += dp[j][k];
					nxdp[j][k] %= MOD;
				}
			}
		}
		dp = nxdp;
	}
	long long ans = power(2, N, MOD) + MOD - 1;
	for (int i = 0; i < 30; i++) {
		ans += MOD - dp[i][1];
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}

}