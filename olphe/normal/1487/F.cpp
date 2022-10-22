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

constexpr int mx = 280;

int used[51][61];
int dp[51][61][mx][mx / 10];

vector<int>dig;

void func(int idx, int ad) {
	if (used[idx][ad + 30])return;
	used[idx][ad + 30] = 1;
	int add = (1000 - (dig[idx] + ad));
	add %= 10;
	add += 10000;
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < mx / 10; j++) {
			add += i;
			if (idx == 0) {
				int num = dig[idx] + ad - (i - (j * 10 + (add % 10)));
				if (num == 0) {
					dp[idx][ad + 30][i][j] = min(dp[idx][ad + 30][i][j], i + j * 10 + (add % 10));
				}
			}
			else {
				int num = (dig[idx] + ad) - (i - (j * 10 + (add % 10)));
				func(idx - 1, num / 10);
				int nadd = (1000 - (dig[idx - 1] + num / 10));
				nadd += 10000;
				for (int ni = i; ni >= max(i - 9, 0); ni--) {
					nadd += ni;
					int nj = j;
					if (nadd % 10 > add % 10)nj--;
					if (nj >= 0)dp[idx][ad + 30][i][j] = min(dp[idx][ad + 30][i][j], dp[idx - 1][num / 10 + 30][ni][nj] + i + j * 10 + (add % 10));
					nadd -= ni;
				}
			}
			add -= i;
		}
	}
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < mx / 10; j++) {
			if (j) {
				dp[idx][ad + 30][i][j] = min(dp[idx][ad + 30][i][j], dp[idx][ad + 30][i][j - 1]);
			}
		}
	}
	return;
}

void Solve(int a) {
	string s;
	cin >> s;
	dig.push_back(0);
	for (auto i : s)dig.push_back(i - '0');
	func(dig.size() - 1, 0);
	int ans = MOD;
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < mx / 10; j++) {
			ans = min(ans, dp[dig.size() - 1][30][i][j]);
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 61; j++) {
			for (int k = 0; k < mx; k++) {
				for (int l = 0; l < mx / 10; l++) {
					dp[i][j][k][l] = MOD;
				}
			}
		}
	}
	//cin >> T;
	while (T--) {
		Solve(T);
	}
}