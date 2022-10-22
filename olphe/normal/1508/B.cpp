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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(vector<int>& bef, vector<int>& ans, int node) {
	if (ans[node] >= 0)return;
	if (bef[node] == -1) {
		ans[node] = 0;
		return;
	}
	func(bef, ans, bef[node]);
	ans[node] = ans[bef[node]] + 1;
	return;
}

void Solve() {
	cin >> N >> K;
	long long int box = 1;
	for (int i = 1; i < N; i++) {
		box *= 2;
		if (box > K)box = K + 1;
	}
	if (box < K) {
		cout << -1 << endl;
		return;
	}
	K--;
	vector<int>rev(N - 1);
	for (int i = 0; i < min(N - 1, 60LL); i++) {
		if (K >> i & 1) {
			rev[i] = 1;
		}
	}
	reverse(rev.begin(), rev.end());
	vector<int>ans(N, -1);
	vector<int>bef(N);
	int mx = -1;
	int nx = -1;
	for (int i = 0; i < N; i++) {
		if (!i || !rev[i - 1]) {
			nx = i;
		}
		if (i + 1 < N && rev[i]) {
			bef[i] = i + 1;
		}
		else {
			bef[i] = mx;
			mx = nx;
		}
	}
	for (int i = 0; i < N; i++) {
		func(bef, ans, i);
	}
	for (auto i : ans)cout << i + 1 << " ";
	cout << endl;
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