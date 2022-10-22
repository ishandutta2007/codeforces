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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> L >> R;
		long long int p = 1;
		for (int i = 1; i < N; i++) {
			for (long long int j = max(L, p); j <= min(R, p + (N - i) * 2 - 1); j++) {
				if ((j - p) & 1)cout << (j - p + 1) / 2 + i << " ";
				else cout << i << " ";
			}
			p += (N - i) * 2;
		}
		if (R == N * (N - 1) + 1) {
			cout << 1;
		}
		cout << endl;
	}
}