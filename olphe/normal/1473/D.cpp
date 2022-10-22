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
	cin >> N >> K;
	vector<int>lmn(N + 1);
	vector<int>lmx(N + 1);
	vector<int>lsum(N + 1);
	vector<int>rmn(N + 1);
	vector<int>rmx(N + 1);
	vector<int>rsum(N + 1);
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		int add = 1;
		if (s[i] == '-')add = -1;
		lsum[i + 1] = lsum[i] + add;
		lmn[i + 1] = min(lmn[i], lsum[i + 1]);
		lmx[i + 1] = max(lmx[i], lsum[i + 1]);
	}
	rmx[N] = rmn[N] = lsum[N];
	for (int i = N - 1; i > 0; i--) {
		rmx[i] = max(rmx[i + 1], lsum[i]);
		rmn[i] = min(rmn[i + 1], lsum[i]);
	}
	while (K--) {
		cin >> L >> R;
		int mx = 0, mn = 0;
		mn = min(mn, lmn[L - 1]);
		mx = max(mx, lmx[L - 1]);
		mn = min(mn, lsum[L - 1] + rmn[R] - lsum[R]);
		mx = max(mx, lsum[L - 1] + rmx[R] - lsum[R]);
		cout << mx - mn + 1 << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}