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
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int p[11111];

void Solve() {
	cin >> N;
	string s;
	cin >> s;
	int idx = -1;
	for (int i = 0; i < N; i++) {
		if (s[i] == '0') {
			idx = i;
		}
	}
	if (idx >= N / 2) {
		cout << 1 << " " << idx+1 << " " << 1 << " " << idx << endl;
	}
	else if (idx >= 0) {
		cout << idx + 1 << " " << N << " " << idx + 2 << " " << N << endl;
	}
	else {
		cout << 1 << " " << N - 1 << " " << 2 << " " << N << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}