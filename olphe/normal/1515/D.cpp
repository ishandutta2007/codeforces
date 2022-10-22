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
	cin >> N >> L >> R;
	vector<int>numL(N + 1);
	vector<int>numR(N + 1);
	for (int i = 0; i < L; i++) {
		cin >> K;
		numL[K]++;
	}
	for (int i = 0; i < R; i++) {
		cin >> K;
		numR[K]++;
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		while (L < R && numL[i]+1 < numR[i]) {
			L++;
			R--;
			ans++;
			numL[i]++;
			numR[i]--;
		}
		while (L > R && numL[i] > numR[i]+1) {
			L--;
			R++;
			ans++;
			numL[i]--;
			numR[i]++;
		}
	}
	for (int i = 0; i <= N; i++) {
		while (L < R && numL[i] < numR[i]) {
			L++;
			R--;
			ans++;
			numL[i]++;
			numR[i]--;
		}
		while (L > R && numL[i] > numR[i]) {
			L--;
			R++;
			ans++;
			numL[i]--;
			numR[i]++;
		}
	}
	for (int i = 0; i <= N; i++) {
		ans += max(0, numL[i] - numR[i]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}