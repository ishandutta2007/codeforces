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
//constexpr double EPS = 1e-12;

int N, M, K, T, H, W, L, R;
//long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		long long int ans = MOD * MOD;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		long long int sum = 0;
		for (int i = 1; i < N; i++) {
			sum += abs(v[i] - v[i - 1]);
		}
		for (int i = 0; i < N; i++) {
			long long int bef = 0;
			if (i)bef += abs(v[i] - v[i - 1]);
			if (i + 1 < N)bef += abs(v[i] - v[i + 1]);
			long long int aft = 0;
			if (i) {
				if (i + 1 < N) {
					aft = abs(v[i - 1] - v[i + 1]);
				}
			}
			ans = min(ans, sum - bef + aft);
		}
		cout << ans << endl;
	}
}