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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N == 0 && M == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (N == M) {
		cout << 1 << endl;
		cout << M << endl;
		return 0;
	}
	if (N > M || (N & 1) != (M & 1)) {
		cout << -1 << endl;
		return 0;
	}
	K = (M - N) / 2;
	if ((N^K) == N + K) {
		cout << 2 << endl;
		cout << N + K << " " << K << endl;
	}
	else {
		cout << 3 << endl;
		cout << N << " " << K << " " << K << endl;
	}
}