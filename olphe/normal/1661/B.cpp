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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>dp(32768,MOD);
	dp[0] = 0;
	queue<int>Q;
	Q.push(0);
	while (!Q.empty()) {
		int c = Q.front();
		Q.pop();
		if (c) {
			if (dp[c - 1] > dp[c] + 1) {
				dp[c - 1] = dp[c] + 1;
				Q.push(c - 1);
			}
		}
		else {
			if (dp.back() > dp.front() + 1) {
				dp.back() = dp.front() + 1;
				Q.push(dp.size() - 1);
			}
		}
		if (c % 2 == 0) {
			if (dp[c / 2] > dp[c] + 1) {
				dp[c / 2] = dp[c] + 1;
				Q.push(c / 2);
			}
			if (dp[c / 2 + 16384] > dp[c] + 1) {
				dp[c / 2 + 16384] = dp[c] + 1;
				Q.push(c / 2 + 16384);
			}
		}
	}
	while (N--) {
		cin >> K;
		cout << dp[K] << " ";
	}
	cout << endl;
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