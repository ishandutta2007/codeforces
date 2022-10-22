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
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;
	while (M--) {
		cin >> N >> L >> R >> K;
		if (L%K == R % K) {
			cout << abs(L - R) / K << endl;
			continue;
		}
		long long int ans = MOD * 10;
		if (1 % K == R % K) {
			ans = min((R - 1) / K + (L - 2 + K) / K, ans);
		}
		if (N%K == R % K) {
			ans = min((N - R) / K + (N - L + K - 1) / K, ans);
		}
		if (ans == MOD * 10)cout << -1 << endl;
		else cout << ans << endl;
	}
}