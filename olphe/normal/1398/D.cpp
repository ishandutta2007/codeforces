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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>r(N);
	vector<long long int>g(M);
	vector<long long int>b(K);
	for (auto &i : r)cin >> i;
	for (auto &i : g)cin >> i;
	for (auto &i : b)cin >> i;
	sort(r.rbegin(), r.rend());
	sort(g.rbegin(), g.rend());
	sort(b.rbegin(), b.rend());
	vector<vector<vector<long long int>>>dp(r.size() + 1, vector<vector<long long int>>(g.size() + 1, vector<long long int>(b.size() + 1)));
	for (int i = 0; i <= r.size(); i++) {
		for (int j = 0; j <= g.size(); j++) {
			for (int k = 0; k <= b.size(); k++) {
				if (i < r.size() && j < g.size()) {
					dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
				}
				if (i < r.size() && k < b.size()) {
					dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
				}
				if (j < g.size() && k < b.size()) {
					dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
				}
			}
		}
	}
	long long int ans = 0;
	for (auto i : dp)for (auto j : i)for (auto k : j)ans = max(ans, k);
	cout << ans << endl;
}