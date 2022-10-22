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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>a(N);
	vector<int>b(N);
	int sum = 0;
	vector<vector<long double>>dp(N + 1, vector<long double>(10001));
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		sum += b[i];
		for (int j = i + 1; j > 0; j--) {
			deque<pair<int, long double>>q;
			for (int k = 0; k <= 10000; k++) {
				while (q.size() && q.back().second + ((long double)k - q.back().first) / 2 <= dp[j - 1][k]) {
					q.pop_back();
				}
				q.push_back({ k,dp[j - 1][k] });
				while (q.front().first < k - b[i] - (a[i] - b[i]) * 2) {
					q.pop_front();
				}
				if (k >= b[i]) {
					dp[j][k] = max(dp[j][k], q.front().second + b[i] + ((long double)k - b[i] - q.front().first) / 2);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		//for (int j = 0; j <= sum; j++) {
		//	cout << fixed << setprecision(20) << dp[i][j] << " ";
		//}
		//cout << endl;
		cout << fixed << setprecision(20) << dp[i][sum] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//	cin >> T;
	while (T--) {
		Solve();
	}
}