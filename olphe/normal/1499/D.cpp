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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int bef[20000001];

int add(int num) {
	int by = 1;
	int lst = 1;
	while (num > 1) {
		if (lst != bef[num]) {
			by <<= 1;
		}
		lst = bef[num];
		num /= lst;
	}
	return by;
}

void Solve() {
	cin >> N >> M >> K;
	int ans = 0;
	for (int i = 1; i * i <= K; i++) {
		if (K % i)continue;
		if ((M * i + K) % N == 0) {
			if ((M * i + K) / N % i == 0) {
				ans += add((M * i + K) / N / i);
			}
		}
		if (i * i != K) {
			i = K / i;
			if ((M * i + K) % N == 0) {
				if ((M * i + K) / N % i == 0) {
					ans += add((M * i + K) / N / i);
				}
			}
			i = K / i;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 20000000; i++) {
		if (bef[i])continue;
		bef[i] = i;
		for (int j = i * 2; j <= 20000000; j+=i) {
			bef[j] = i;
		}
	}
	cin >> T;
	while (T--) {
		Solve();
	}

}