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

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

int v[1234567][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	v[1][1] = 1;
	v[2][1] = 1;
	v[4][1] = 1;
	v[5][1] = 1;
	v[9][1] = 1;
	v[10][1] = 1;
	L = 9;
	R = 10;
	for (int i = 16; i <= N; i *= 2) {
		H = MOD;
		W = 0;
		for (int j = L * 2 + 1; j <= L * 2 + 100; j++) {
			for (int k = L; k <= R; k++) {
				if (j - k - 1 < L || j - k - 1 > R)continue;
				v[j][!(((k & 1) ^ 1) ^ (j & 1))] += v[k][1] * v[j - k - 1][!(((j & 1) ^ 1) ^ (k & 1))];
				v[j][!(((k & 1) ^ 1) ^ (j & 1))] %= MOD;
			}
			//v[j][0] %= MOD;
			//v[j][1] %= MOD;
			if (v[j][0] || v[j][1]) {
				H = min((int)H, j);
				W = max((int)W, j);
			}
		}
		L = H;
		R = W;
	}
	cout << (v[N][0] + v[N][1]) % MOD << endl;
}