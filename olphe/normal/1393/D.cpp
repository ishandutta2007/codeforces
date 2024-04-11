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

int wa[4010][4010];
int sa[4010][4010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	for (int i = 0; i < H; i++) {
		wa[i + W - 1][W - 1] = W - 1;
		sa[i - (W - 1) + 2000][W - 1] = W - 1;
	}
	for (int i = W - 2; i >= 0; i--) {
		for (int j = 0; j < H; j++) {
			if (j) {
				if (s[j][i] == s[j - 1][i + 1]) {
					wa[i + j][i] = wa[i + j][i + 1];
				}
				else {
					wa[i + j][i] = i;
				}
			}
			else {
				wa[i + j][i] = i;
			}
			if (j + 1 < H) {
				if (s[j][i] == s[j + 1][i + 1]) {
					sa[j - i + 2000][i] = sa[j - i + 2000][i + 1];
				}
				else {
					sa[j - i + 2000][i] = i;
				}
			}
			else {
				sa[j - i + 2000][i] = i;
			}
		}
	}
	long long int ans = 0;
	vector<vector<int>>field(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		field[i][0] = 1;
		ans++;
		for (int j = 1; j < W; j++) {
			field[i][j] = field[i][j - 1] - 1;
			if (field[i][j] < 1)field[i][j] = 1;
			while (i + field[i][j] < H&&j + field[i][j] < W&&i - field[i][j] >= 0 && j - field[i][j] >= 0) {
				bool flag = true;
				flag &= s[i][j] == s[i - field[i][j]][j];
				flag &= s[i][j] == s[i + field[i][j]][j];
				flag &= s[i][j] == s[i][j + field[i][j]];
				flag &= s[i][j] == s[i][j - field[i][j]];
			//	cout << "i j " << i << " " << j << " " << flag << endl;
				flag &= wa[i + j - field[i][j]][j - field[i][j]] >= j;
				flag &= wa[i + j + field[i][j]][j] >= j + field[i][j];
			//	cout << "i j " << i << " " << j << " " << flag << endl;
				flag &= sa[i - (j - field[i][j]) + 2000][j - field[i][j]] >= j;
				flag &= sa[i - (j + field[i][j]) + 2000][j] >= j + field[i][j];
				if (!flag)break;
				field[i][j]++;
			}
			ans += field[i][j];
		//	cout << i << " " << j << " " << field[i][j] << endl;
		}
	}
	cout << ans << endl;
}