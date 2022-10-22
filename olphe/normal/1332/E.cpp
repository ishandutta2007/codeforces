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
constexpr long double EPS = 1e-12;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

vector<vector<long long int>>matrix_product(vector<vector<long long int>>v, vector<vector<long long int>>w) {
	vector<vector<long long int>>ret(v.size(), vector<long long int>(w.front().size()));
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			for (int k = 0; k < w.size(); k++) {
				ret[i][j] += v[i][k] * w[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> L >> R;
	if (H*W % 2 == 1) {
		cout << power(R - L + 1, H*W, MOD) << endl;
		return 0;
	}
	vector<vector<long long int>>ans(2, vector<long long int>(1));
	ans[1][0] = 1;
	int odd = (R + 1) / 2 - (L / 2);
	int even = (R / 2) - (L - 1) / 2;
	vector<vector<long long int>>ret(2, vector<long long int>(2));
	ret[0][0] = ret[1][1] = 1;
	vector<vector<long long int>>by(2, vector<long long int>(2));
	by[0][0] = by[1][1] = even;
	by[0][1] = by[1][0] = odd;
	K = H * W;
	for (int i = 0; i <= 60; i++) {
		if ((K >> i) & 1)ret = matrix_product(ret, by);
		by = matrix_product(by, by);
	}
	ans = matrix_product(ret, ans);
	cout << ans[1][0] << endl;
}