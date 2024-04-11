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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<long long int>dp(32);
		dp[0] = 1;
		for (int i = 1; i <= 30; i++) {
			if ((N >> (i - 1)) > 1) {
				for (int j = 0; j < i; j++) {
					dp[i] += dp[j] << (i - 1) % M;
					dp[i] %= M;
				}
			}
			else if ((N >> (i - 1)) == 1) {
				long long int by = N - (1LL << (i - 1)) + 1;
				for (int j = 0; j < i; j++) {
					dp[i] += dp[j] * by%M;
					dp[i] %= M;
				}
			}
		}
		dp[0] = 0;
		cout << accumulate(dp.begin(), dp.end(), 0LL) % M << endl;
	}
}