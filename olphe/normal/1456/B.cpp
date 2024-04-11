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
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>num(N);
	for (auto &i : num)cin >> i;
	if (N > 70) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<int>>sum(N, vector<int>(N + 1));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = i; k < j; k++) {
				sum[i][j] ^= num[k];
			}
		}
	}
	int ans = MOD;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (sum[i][j] > sum[j][k]) {
					ans = min(ans, k - i - 2);
				}
			}
		}
	}
	if (ans == MOD)ans = -1;
	cout << ans << endl;
}