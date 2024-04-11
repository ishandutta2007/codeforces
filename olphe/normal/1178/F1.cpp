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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(M+2);
	for (int i = 1; i <= M; i++) {
		cin >> v[i];
		//v[i] = (i * 37) % M;
	}
	vector<vector<long long int>>dp(M+2, vector<long long int>(M+2,1));
	for (int i = 1; i < M; i++) {
		for (int j = 1; j + i <= M; j++) {
			dp[j][j + i] = 0;
			int mindex = j;
			for (int k = j; k <= j + i; k++) {
				if (v[mindex] > v[k])mindex = k;
			}
			long long int a, b;
			a = b = 0;
			for (int l = j; l <= mindex; l++) {
				a += dp[j][l - 1] * dp[l][mindex - 1];
				a %= MOD;
			}
			for (int r = mindex; r <= i + j; r++) {

				b += (dp[mindex + 1][r] * dp[r + 1][j + i]) % MOD;
				b %= MOD;
			}
			dp[j][j + i] += a * b;
			dp[j][j + i] %= MOD;
		}
	}
	cout << dp[1][M] << endl;
}