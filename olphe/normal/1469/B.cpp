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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	cin >> M;
	vector<int>w(M);
	for (auto& i : w)cin >> i;
	v.insert(v.begin(), 0);
	w.insert(w.begin(), 0);
	for (int i = 1; i <= N; i++) {
		v[i] += v[i - 1];
	}
	for (int i = 1; i <= M; i++) {
		w[i] += w[i - 1];
	}
	N++, M++;
	vector<vector<int>>dp(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i)dp[i][j] = max({ dp[i][j],dp[i - 1][j], v[i] + w[j] });
			if (j)dp[i][j] = max({ dp[i][j],dp[i][j - 1], v[i] + w[j] });
		}
	}
	cout << dp.back().back() << endl;
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