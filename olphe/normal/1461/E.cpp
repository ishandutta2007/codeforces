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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> L >> R >> T;
	long long int sub, add;
	cin >> sub >> add;
	if (sub == add) {
		if (N + add <= R || L <= N - add) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		return;
	}
	if (sub > add) {
		if (N + add > R) {
			N -= add;
		}
		if ((N - L) / T >= (sub - add)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		return;
	}
	vector<long long int>turn(sub, MOD*MOD);
	long long cnt = N;
	long long int cturn = 0;
	while (1) {
		long long int dif = cnt - L;
		dif /= sub;
		cturn += dif;
		cnt -= dif * sub;
		if (turn[cnt - L] > cturn) {
			turn[cnt - L] = cturn;
			cnt += add;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < sub; i++) {
		if (turn[i] < T && L + i + add > R) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cin >> T;
	//while (T--) {
		Solve();
	//}
}