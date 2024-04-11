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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	M *= (N / M) + !!(N%M);
	K *= 2;
	L = N * 2;
	R = M - N;
	long double ans = K / (L + R)*M;
	K %= L + R;
	if (L >= K) {
		ans += (long double)K / 2;
	}
	else {
		ans += N;
		ans += K - L;
	}
	cout << setprecision(25) << ans << endl;

	return 0;
}