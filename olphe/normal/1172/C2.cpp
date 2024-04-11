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

//const long long int MOD = 1000000007;
//const long long int MOD = 1000003;
//const int MOD = 998244353;
const long long int MOD = 998244353;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

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

	cin >> N >> M;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	int sum0 = 0, sum1 = 0;
	vector<vector<long long int>>p(M + 1, vector<long long int>(M + 1));
	for (int i = 0; i < N; i++) {
		if (v[i])sum1 += w[i];
		else sum0 += w[i];
	}
	sum0 %= MOD;
	sum1 %= MOD;
	long long int revsum0 = power(sum0, MOD - 2, MOD);
	long long int revsum1 = power(sum1, MOD - 2, MOD);
	p[0][0] = 1;
	vector<long long int>rev(10000);
	for (int i = -3200; i <= 3200; i++) {
		long long int box = sum0 + sum1 + i;
		box %= MOD;
		rev[i + 5000] = power(box, MOD - 2, MOD);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j <= i; j++) {
			//	cout << i << " " << j << endl;
			int x = j, y = i - j;
			long long int sum;
			long long int by;
			if (x) {
				sum = sum0 + MOD - x + 1 + sum1 + y;
				sum %= MOD;
				by = (((sum0 + MOD - (x - 1)) % MOD)*rev[(5000 + sum - sum0 - sum1) % MOD]);
				by%=MOD;
				by *= p[x - 1][y];
				by %= MOD;
				p[x][y] += by;
				p[x][y] %= MOD;
			}
			if (y) {
				sum = sum0 + MOD - x + sum1 + y - 1;
				sum %= MOD;
				by = (((sum1 + y - 1) % MOD)*rev[(5000 + sum - sum0 - sum1) % MOD]);
				by %= MOD;
				by *= p[x][y - 1];
				by %= MOD;
				p[x][y] += by;
				p[x][y] %= MOD;
			}
		}
	}

	long long int lsum0 = 0, lsum1 = 0;
	for (int i = 0; i <= M; i++) {
		lsum0 += (sum0 + MOD - i) * p[i][M - i];
		lsum0 %= MOD;
		lsum1 += (sum1 + M - i) * p[i][M - i];
		lsum1 %= MOD;
	}
	for (int i = 0; i < N; i++) {
		if (v[i]) {
			long long int ret = lsum1;
			ret *= w[i];
			ret %= MOD;
			ret *= revsum1;
			ret %= MOD;
			cout << ret << "\n";
		}
		else {
			long long int ret = lsum0;
			ret *= w[i];
			ret %= MOD;
			ret *= revsum0;
			ret %= MOD;
			cout << ret << "\n";
		}
	}
}