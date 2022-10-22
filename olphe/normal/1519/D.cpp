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
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<long long int>a(N);
	vector<long long int>b(N);
	for (auto& i : a)cin >> i;
	for (auto& i : b)cin >> i;
	long long int ans = 0;
	vector<long long int>c(N + 1);
	for (int i = 0; i < N; i++) {
		c[i + 1] = a[i] * b[i];
		c[i + 1] += c[i];
	}
	for (int i = 2; i <= N * 2; i++) {
		vector<long long int>sum(N + 1);
		for (int j = 1; j <= N; j++) {
			if (i - j <= N && i - j >= 1) {
				sum[j] = a[j - 1] * b[i - j - 1];
			}
		}
		for (int j = 1; j <= N; j++) {
			sum[j] += sum[j - 1];
		}
		for (int j = 1; j <= N; j++) {
			if (i - j <= N && i - j >= 1&&j<=i-j) {
				ans = max(ans, c[j - 1] + c.back() - c[i - j] + sum[i - j] - sum[j - 1]);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}