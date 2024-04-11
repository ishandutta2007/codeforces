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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (M%N) {
		cout << -1 << endl;
		return 0;
	}
	K = M / N;
	int ans = 0;
	while (K % 2==0) {
		ans++;
		K /= 2;
	}
	while (K % 3==0) {
		ans++;
		K /= 3;
	}
	if (K > 1) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}