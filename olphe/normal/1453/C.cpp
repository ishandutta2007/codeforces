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
//constexpr double EPS = 1e-12;

int N, M, K, T, H, W, L, R;
//long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<string>s(N);
		for (auto &i : s)cin >> i;
		vector<vector<vector<int>>>yp(10, vector<vector<int>>(N));
		vector<vector<vector<int>>>xp(10, vector<vector<int>>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				yp[s[i][j] - '0'][i].push_back(j);
				xp[s[i][j] - '0'][j].push_back(i);
			}
		}
		for (int i = 0; i < 10; i++) {
			int ans = 0;
			int mx = 0, mn = N;
			for (int j = 0; j < N; j++) {
				if (yp[i][j].size()) {
					mx = max(mx, j);
					mn = min(mn, j);
				}
			}
			for (int j = 0; j < N; j++) {
				if (yp[i][j].size()) {
					if (yp[i][j].size() > 1) {
						ans = max(ans, max(j, N - 1 - j)*(yp[i][j].back() - yp[i][j].front()));
					}
					ans = max(ans, max(yp[i][j].back(), N - 1 - yp[i][j][0])*max(mx - j, j - mn));
					ans = max(ans, max(N-1-yp[i][j].front(), N - 1 - yp[i][j][0])*max(mx - j, j - mn));
				}
			}
			mx = 0, mn = N;
			for (int j = 0; j < N; j++) {
				if (xp[i][j].size()) {
					mx = max(mx, j);
					mn = min(mn, j);
				}
			}
			for (int j = 0; j < N; j++) {
				if (xp[i][j].size()) {
					if (xp[i][j].size() > 1) {
						ans = max(ans, max(j, N - 1 - j)*(xp[i][j].back() - xp[i][j].front()));
					}
					ans = max(ans, max(xp[i][j].back(), N - 1 - xp[i][j][0])*max(mx - j, j - mn));
					ans = max(ans, max(N-1-xp[i][j].front(), N - 1 - xp[i][j][0])*max(mx - j, j - mn));
				}
			}
			cout << ans << " ";
		}
		cout << endl;
	}
}