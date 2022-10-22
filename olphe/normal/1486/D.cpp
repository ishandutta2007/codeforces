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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> K;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	L = 1, R = N+1;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		vector<int>w;
		for (auto i : v) {
			w.push_back(2 * (i >= mid) - 1);
		}
		vector<int>score(N + 1);
		int mn = MOD;
		bool ok = false;
		for (int i = 0; i < N; i++) {
			score[i + 1] = score[i] + w[i];
		}
		for (int i = K; i <= N; i++) {
			mn = min(mn, score[i - K]);
			if (mn < score[i]) ok = true;
		}
		if (ok)L = mid;
		else R = mid;
	}
	cout << L << endl;
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