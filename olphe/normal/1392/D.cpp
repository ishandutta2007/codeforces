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

	cin >> T;
	while (T--) {
		cin >> N;
		string s;
		cin >> s;
		int ans = N;
		K = 4;
		while (K--) {
			vector<int>dp(N + 1, MOD);
			dp[0] = 0;
			for (int i = 0; i + 2 <= N; i++) {
				if (i + 2 <= N) {
					dp[i + 2] = min(dp[i] + (s[i] != 'R') + (s[i + 1] != 'L'), dp[i + 2]);
				}
				if (i + 3 <= N) {
					dp[i + 3] = min(dp[i] + (s[i] != 'R') + (s[i + 2] != 'L'), dp[i + 3]);
				}
				if (i + 4 <= N) {
					dp[i + 4] = min(dp[i] + (s[i] != 'R') + (s[i + 1] != 'R') + (s[i + 2] != 'L') + (s[i + 3] != 'L'), dp[i + 4]);
				}
			}
			ans = min(ans, dp.back());
			s.push_back(s.front());
			s.erase(s.begin());
		}
		cout << ans << endl;
	}
}