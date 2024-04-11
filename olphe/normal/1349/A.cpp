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

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	if (N == 2) {
		cin >> M >> K;
		cout << (M * K / gcd(M, K)) << endl;
		return 0;
	}
	vector<int>a(200001,MOD);
	vector<int>b(200001,MOD);
	vector<int>num(200001,0);
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 2; j*j <= M; j++) {
			int box = 0;
			while (M%j == 0) {
				box++;
				M /= j;
			}
			if (!box)continue;
			num[j]++;
			if (box < a[j]) {
				b[j] = a[j];
				a[j] = box;
			}
			else if (box < b[j]) {
				b[j] = box;
			}
		}
		if (M > 1) {
			num[M]++;
			int box = 1;
			if (box < a[M]) {
				b[M] = a[M];
				a[M] = box;
			}
			if (box < b[M]) {
				b[M] = box;
			}
		}
	}
	long long int ans = 1;
	for (int i = 1; i <= 200000; i++) {
		if (num[i] < N - 1)continue;
		if (num[i] == N - 1) {
			for (int j = 0; j < a[i]; j++) {
				ans *= i;
			}
		}
		else {
			for (int j = 0; j < b[i]; j++) {
				ans *= i;
			}
		}
	}
	cout << ans << endl;
};