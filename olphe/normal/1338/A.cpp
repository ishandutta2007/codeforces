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
		cin >> N;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		long long int m = MOD * MOD;
		long long int ans = 0;
		for (int i = N - 1; i >= 0; i--) {
			ans = max(ans, v[i] - m);
			m = min(m, v[i]);
		}
		int ret = 0;
		while (ans) {
			ans >>= 1;
			ret++;
		}
		cout << ret << endl;
	}
}