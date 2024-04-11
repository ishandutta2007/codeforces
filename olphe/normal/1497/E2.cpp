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
	cin >> N >> K;
	vector<int>v(N);
	for (auto& i : v) {
		cin >> i;
		for (int j = 2; j * j <= i; j++) {
			while (i % (j * j) == 0) {
				i /= j * j;
			}
		}
	}
	vector<int>nx(N, N);
	vector<vector<int>>ok(N, vector<int>(K + 1, N));
	map<int, int>mp;
	for (int i = N - 1; i >= 0; i--) {
		if (mp.find(v[i]) == mp.end()) {

		}
		else {
			nx[i] = mp[v[i]];
		}
		mp[v[i]] = i;
	}
	multiset<int>ms;
	for (int i = N - 1; i >= 0; i--) {
		ms.insert(nx[i]);
		if (ms.size() > K + 1) {
			ms.erase(prev(ms.end()));
		}
		int cnt = 0;
		for (auto j : ms) {
			ok[i][cnt++] = j;
		}
	}
	vector<vector<int>>dp(N + 1, vector<int>(K + 1, MOD));
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = j; k <= K; k++) {
				int use = k - j;
				dp[ok[i][use]][k] = min(dp[ok[i][use]][k], dp[i][j] + 1);
			}
		}
	}
	int ans = dp[N][K];
	cout << ans << endl;
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