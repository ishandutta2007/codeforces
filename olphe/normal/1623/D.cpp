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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x % M;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

void Solve() {
	cin >> H >> W;
	int sy, sx, gy, gx, p;
	cin >> sy >> sx >> gy >> gx;
	cin >> p;
	vector<long long>q((H*2-2) * (W*2-2) + 1);
	q[0] = 1;
	int cy = sy, cx = sx;
	int dy = 1, dx = 1;
	long long add = 1;
	long long inv = power(100, MOD - 2, MOD);
	vector<int>ok((H*2-2) * (W*2-2));
	if (sy == gy || sx == gx) {
		add *= (100 - p) * inv % MOD;
		add %= MOD;
	}
	for (int i = 1; i <= (H*2-2) * (W*2-2); i++) {
		if (cx == gx || cy == gy) {
			ok[i - 1] = 1;
		}
		if (cy + dy<1 || cy + dy>H)dy *= -1;
		if (cx + dx<1 || cx + dx>W)dx *= -1;
		cx += dx;
		cy += dy;
		q[i] = add;
		if (cy == gy || cx == gx) {
			add *= (100 - p) * inv % MOD;
			add %= MOD;
		}
	}
	long long by = q.back();
	long long ans = 0;
//	cout << by << endl;
	for (int i = 0; i < (H * 2 - 2) * (W * 2 - 2); i++) {
		if (ok[i]) {
			add = i * q[i] % MOD;
			add += (H * 2 - 2) * (W * 2 - 2) % MOD * q[i] % MOD * by % MOD * power(MOD + 1 - by, MOD - 2, MOD);
			add %= MOD;
			add *= power(MOD + 1 - by, MOD - 2, MOD);
			ans += add;
			ans %= MOD;
		}
	}
	ans *= p;
	ans %= MOD;
	ans *= inv;
	ans %= MOD;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}