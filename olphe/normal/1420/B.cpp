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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v(N);
		vector<int>num(N);
		vector<int>sum(31);
		for (auto &i : v)cin >> i;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 30; j++) {
				v[i] >>= 1;
				if (v[i]) {
					num[i] = j+1;
				}
			}
			sum[num[i]]++;
		}
		long long int ans = 0;
		for (int i = 0; i < 30; i++) {
			ans += 1LL * (sum[i] - 1)*(sum[i]) / 2;
		}
		cout << ans << endl;

	}
}