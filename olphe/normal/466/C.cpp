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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>sum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
	}
	for (int i = 1; i <= N; i++) {
		sum[i] += sum[i - 1];
	}
	vector<long long int>ans(N + 1);
	if (sum.back() % 3) {
		cout << 0 << endl;
		return 0;
	}
	M = sum.back() / 3;
	for (int i = N - 1; i > 1; i--) {
		if (sum[i] == M * 2) {
			ans[i]++;
		}
	}
	for (int i = N - 1; i > 0; i--) {
		long long int box = ans[i];
		ans[i] = 0;
		if (sum[i] == M) {
			ans[i] = K;
		}
		K += box;
	}
	K = 0;
	for (int i = 1; i <= N; i++) {
		K += ans[i];
	}
	cout << K << endl;
	return 0;
}