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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

constexpr int sz = 720720;

void Solve() {
	cin >> N;
	vector<long long>v(N);
	cin >> v[0];
	long long x, y;
	cin >> x >> y;
	cin >> K;
	cin >> M;
	for (int i = 1; i < N; i++) {
		v[i] = v[i - 1] * x + y;
		v[i] %= M;
	}
	long long ans = 0;
	vector<long long>by(K + 1, 1);
	for (int i = 1; i <= K; i++) {
		by[i] = by[i - 1] * N % MOD;
	}
	for (int i = 0; i < N; i++) {
		ans += K * v[i] % MOD * by[K - 1];
		ans %= MOD;
	}
	vector<vector<long long>>sum(K, vector<long long>(sz));
	for (int j = K - 1; j > 0; j--) {
		int mi = 0;
		for (int i = 0; i < sz; i++) {
			sum[j - 1][i] = sum[j][i] * (N - 1);
			if (mi) {
				sum[j - 1][i] += sum[j][i - mi] + by[K - j - 1] * (K - j) * mi;
			}
			else {
				sum[j - 1][i] += sum[j][i];
			}
			sum[j - 1][i] %= MOD;
			mi++;
			if (mi == j)mi = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		ans += MOD - sum[0][v[i] % sz];
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}