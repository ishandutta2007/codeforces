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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= 60; i++) {
		M = N - K * i;
		int num = 0;
		if (M <= 0)continue;
		while (M) {
			num += M & 1;
			M >>= 1;
		}
		if (i >= num&&i<=N-K*i) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}