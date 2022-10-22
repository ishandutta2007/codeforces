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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

long long int lcm(long long int a, long long int b) {
	long long int ret = a * b;
	while (b) {
		a %= b;
		swap(a, b);
	}
	ret /= a;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	long long int ans = N;
	for (long long int i = 1; i*i <= N; i++) {
		if (N%i)continue;
		if (lcm(i, N / i) != N)continue;
		if (ans > N/i) {
			ans = N/i;
		}
	}
	cout << ans << " " << N / ans << endl;
}