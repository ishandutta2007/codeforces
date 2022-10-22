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

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	cin >> L >> R >> H;
	long long int box = gcd(K, H);
	if (N > L) {
		swap(N, L);
		swap(M, R);
		swap(K, H);
	}
	long long int dif = L - N;
	dif %= box;
	long long int ddif = dif - box;
	long long int ans = min(M, R - L + N + dif) - (N + dif) + 1;
	ans = max(ans, min(M, R - L + N + ddif) - N + 1);
	long long int a = N;
	N = K - 1 - M;
	M = K - 1 - a;
	a = L;
	L = H - 1 - R;
	R = H - 1 - a;
	if (N > L) {
		swap(N, L);
		swap(M, R);
		swap(K, H);
	}
	dif = L - N;
	dif %= box;
	ddif = dif - box;
	ans = max(ans,min(M, R - L + N + dif) - (N + dif) + 1);
	ans = max(ans, min(M, R - L + N + ddif) - N + 1);
	ans = max(ans, 0LL);
	cout << ans << endl;
	return 0;
}