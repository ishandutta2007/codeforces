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

int num[1000001] = {};
int tot[1000001] = {};

void Solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		num[K]++;
	}
	for (int i = 1000000; i > 0; i--) {
		int sum = 0;
		int mx = 0;
		for (int j = i; j <= 1000000; j += i) {
			sum += num[j];
			tot[i] += num[j];
			mx = max(mx, tot[j]);
		}
		if (sum > 1 && sum != mx) {
			tot[i] -= num[i];
			num[i] = 1;
			tot[i] += num[i];
		}
	}
	cout << accumulate(num, num + 1000001, 0)-N << endl;
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