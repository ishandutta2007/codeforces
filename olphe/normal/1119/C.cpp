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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	vector<vector<int>>w(H, vector<int>(W));
	for (auto &i : v)for (auto &j : i)cin >> j;
	for (auto &i : w)for (auto &j : i)cin >> j;
	vector<int>difh(H);
	vector<int>difw(W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (v[i][j] != w[i][j]) {
				difh[i]++;
				difw[j]++;
			}
		}
	}
	//cout << accumulate(difh.begin(), difh.end(), 0) << endl;
	for (auto i : difh) {
		if (i & 1) {
			cout << "No\n";
			return 0;
		}
	}
	for (auto i : difw) {
		if (i & 1) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}