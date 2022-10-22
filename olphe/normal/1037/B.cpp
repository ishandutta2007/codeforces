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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long int ans = 0;
	if (v[N / 2] == K) {
		cout << 0 << endl;
		return 0;
	}
	if (v[N / 2] < K) {
		for (int i = N / 2; i < N; i++) {
			if (v[i] < K)ans += K - v[i];
		}
	}
	else {
		for (int i = N / 2; i >= 0; i--) {
			if (v[i] > K)ans += v[i] - K;
		}
	}
	cout << ans << endl;
	return 0;
}