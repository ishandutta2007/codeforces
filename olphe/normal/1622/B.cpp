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

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	string s;
	vector<int>ok(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == '1') {
			ok[v[i]] = 1;
		}
	}
	vector<int>ans(N + 1);
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		if (ok[i] == 0) {
			ans[i] = cnt++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (ok[i] == 1) {
			ans[i] = cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[v[i]] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}