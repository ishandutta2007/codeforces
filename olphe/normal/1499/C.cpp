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

void Solve() {
	cin >> N;
	vector<long long int>v(N);
	for (auto& i : v)cin >> i;
	long long int ans = (v[0] + v[1]) * N;
	long long int oddsum = v[1], oddmn = v[1], evensum = v[0], evenmn = v[0];
	long long int oddamari = N - 1, evenamari = N - 1;
	for (int i = 2; i < N; i++) {
		if (i & 1) {
			oddamari--;
			oddsum += v[i];
			oddmn = min(oddmn, v[i]);
		}
		else {
			evenamari--;
			evensum += v[i];
			evenmn = min(evenmn, v[i]);
		}
		ans = min(ans, oddsum + oddamari * oddmn + evensum + evenamari * evenmn);
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