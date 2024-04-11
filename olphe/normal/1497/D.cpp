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
	vector<int>tag(N);
	for (auto& i : tag)cin >> i;
	vector<int>score(N);
	for (auto& i : score)cin >> i;
	vector<long long int>dp(N);
	for (int i = 1; i < N; i++) {
		for (int j = i-1; j >=0; j--) {
			if (tag[i] != tag[j]) {
				long long int a = dp[j] + abs(score[i] - score[j]);
				long long int b = dp[i] + abs(score[i] - score[j]);
				dp[i] = max(dp[i], a);
				dp[j] = max(dp[j], b);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}