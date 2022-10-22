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
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	while (1) {
		bool flag = true;
		for (auto i : v) {
			if (i & 1)flag = false;
		}
		if (flag) {
			for (auto& i : v) {
				i /= 2;
			}
		}
		else {
			break;
		}
	}
	int sum = accumulate(v.begin(), v.end(), 0);
	vector<int>dp(sum + 1);
	dp[0] = 1;
	for (auto i : v) {
		for (int j = sum; j >= i; j--) {
			dp[j] |= dp[j - i];
		}
	}
	if (sum%2==0&&dp[sum / 2]) {
		cout << 1 << endl;
		for (int i = 0; i < N; i++) {
			if (v[i] & 1) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	else cout << 0 << endl;
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