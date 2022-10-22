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

//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<int>flag(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		flag[R] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (flag[i])continue;
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			cout << i << " " << j << endl;
		}
		return;
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