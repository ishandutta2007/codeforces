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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	vector<vector<int>>w(H, vector<int>(W));
	vector<pair<int, int>>ans;
	for (auto &i : v)for (auto &j : i)cin >> j;
	for (int i = 0; i < H - 1; i++) {
		for (int j = 0; j < W - 1; j++) {
			if (v[i][j] && v[i][j + 1] && v[i + 1][j] && v[i + 1][j + 1]) {
				w[i][j] = w[i][j + 1] = w[i + 1][j] = w[i + 1][j + 1] = 1;
				ans.push_back({ i + 1,j + 1 });
			}
		}
	}
	if (v != w) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i.first << " " << i.second << endl;
}