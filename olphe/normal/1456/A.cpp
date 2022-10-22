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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		M--;
		string s;
		cin >> s;
		vector<long long int>sum(N);
		cin >> L >> R;
		for (int i = N - 1; i >= 0; i--) {
			if (s[i] == '0')sum[i]++;
			if (i + K < N)sum[i] += sum[i + K];
		}
		long long int ans = MOD * MOD;
		for (int i = M; i < N; i++) {
			ans = min(ans, (i - M)*R + sum[i]*L);
		}
		cout << ans << endl;
	}
}