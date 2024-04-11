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
constexpr double EPS = 1e-9;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

long long int dp[500];
long long int ndp[500];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	dp[0] = 0;
	for (int i = 1; i < M; i++)dp[i] = -MOD * MOD;
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		for (int j = 0; j < M; j++) {
			ndp[j] = -MOD * MOD;
		}
		long long int add = (L + R) / M;
		for (int j = 0; j < M; j++) {
			if (j > L)break;
			int k = (L + R - j) % M;
			if (k > R)continue;
			if (j + k >= M)add--;
			for (int l = 0; l < M; l++) {
				if (sum < l)continue;
				int m = (sum - l) % M;
				ndp[(l + j) % M] = max(ndp[(l + j) % M], dp[l] + add + ((l + j) >= M) + ((m + k) >= M));
			}
			if (j + k >= M)add++;
		}
		for (int j = 0; j < M; j++)dp[j] = ndp[j];
		sum += L + R;
	}
	long long int ans = 0;
	for (int i = 0; i < M; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}