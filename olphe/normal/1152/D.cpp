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
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

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

	cin >> N;
	vector<vector<long long int>>box(N, vector<long long int>(N));
	vector<long long int>by(10000,1);
	vector<long long int>rev_by(10000,1);
	for (int i = 1; i < 10000; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
		rev_by[i] = power(by[i], MOD - 2, MOD);
	}
	box[0][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			box[i][j] = by[2 * i + 1];
			box[i][j] *= rev_by[i + 1];
			box[i][j] %= MOD;
			box[i][j] *= rev_by[i];
			box[i][j] %= MOD;
			long long int minus = by[2 * i + 1];
			minus *= rev_by[i - j - 1];
			minus %= MOD;
			minus *= rev_by[i + j + 2];
			minus %= MOD;
			box[i][j] += MOD - minus;
			box[i][j] %= MOD;
		}
		box[i][i] = 2 * (2 * i + 1)*box[i - 1][i - 1];
		box[i][i] %= MOD;
		box[i][i] *= power(i + 1, MOD - 2, MOD);
		box[i][i] %= MOD;
	}
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		//assert(min(i, max(0, (int)N - i - 1)) < N&&min(i, max(0, (int)N - i - 1)) >= 0);
		ans += box[i][min(i,max(0, (int)N - i - 1))];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}