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

void Solve() {
	cin >> H >> W;
	vector<string>s(H);
	for (auto&i : s)cin >> i;
	int ans = 0;
	vector<vector<int>>ok(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i) {
				for (int k = 0; k < W; k++) {
					if (j - k >= 0 && j + k < W&&s[i][j - k] == '*'&&s[i][j + k] == '*') {
						ok[i][j]++;
					}
					else {
						break;
					}
				}
				ok[i][j] = min(ok[i][j], ok[i - 1][j] + 1);
				ans += ok[i][j];
			}
			else {
				if (s[i][j] == '*') {
					ok[i][j] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}