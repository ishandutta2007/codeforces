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


void Solve() {
	cin >> N >> M;
	string s;
	cin >> s;
	vector<int>sum(N + 1);
	vector<vector<int>>p(2 * N + 1);
	p[N].push_back(0);
	sum[0] = N;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i];
		if (s[i] == '+'^(i&1))sum[i + 1]++;
		else sum[i + 1]--;
		p[sum[i + 1]].push_back(i + 1);
	}
	while (M--) {
		cin >> L >> R;
		if (sum[R] == sum[L - 1]) {
			cout << 0 << "\n";
		}
		else if (abs(sum[R] - sum[L - 1]) & 1) {
			if (sum[L - 1] < sum[R]) {
				cout << 1 << "\n";
				int idx = sum[L - 1] + (sum[R] - sum[L - 1]) / 2 + 1;
				cout << *lower_bound(p[idx].begin(), p[idx].end(), L) << "\n";
			}
			else {
				cout << 1 << "\n";
				int idx = sum[R] + (sum[L - 1] - sum[R]) / 2;
				cout << *lower_bound(p[idx].begin(), p[idx].end(), L) << "\n";
			}
		}
		else {
			cout << 2 << "\n";
			R--;
			if (sum[L - 1] < sum[R]) {
				int idx = sum[L - 1] + (sum[R] - sum[L - 1]) / 2 + 1;
				cout << *lower_bound(p[idx].begin(), p[idx].end(), L) << " " << R + 1 << "\n";
			}
			else {
				int idx = sum[R] + (sum[L - 1] - sum[R]) / 2;
				cout << *lower_bound(p[idx].begin(), p[idx].end(), L) << " " << R + 1 << "\n";
			}
		}
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