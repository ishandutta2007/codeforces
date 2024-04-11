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

vector<int> Prime(int num) {
	vector<int>ret;
	ret.push_back(2);
	ret.push_back(3);
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (int j = 2; j < ret.size(); j++) {
			if (ret[j] * ret[j] > i)break;
			if (i % ret[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)ret.push_back(i);
		flag = true;
		for (int j = 2; j < ret.size(); j++) {
			if (ret[j] * ret[j] > i + 2)break;
			if ((i + 2) % ret[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag)ret.push_back(i + 2);
	}
	return ret;
}

void Solve() {
	auto P = Prime(4444);
	cin >> N >> M;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<int>used(111111);
	vector<vector<int>>tapi(21, vector<int>(N, N));
	vector<vector<int>>vp(N);
	for (int i = 0; i < N; i++) {
		for (auto j : P) {
			if (v[i] % j == 0) {
				vp[i].push_back(j);
				while (v[i] % j == 0) {
					v[i] /= j;
				}
			}
		}
		if (v[i] > 1) {
			vp[i].push_back(v[i]);
		}
	}
	int r = 0;
	for (int i = 0; i < N; i++) {
		while (r < N) {
			bool flag = true;
			for (auto j : vp[r]) {
				if (used[j])flag = false;
			}
			if (flag) {
				for (auto j : vp[r]) {
					used[j] = 1;
				}
				r++;
			}
			else {
				break;
			}
		}
		tapi[0][i] = r;
	//	cout << i << " " << r << endl;
		for (auto j : vp[i]) {
			used[j] = 0;
		}
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < N; j++) {
			if (tapi[i - 1][j] != N) {
				tapi[i][j] = tapi[i - 1][tapi[i - 1][j]];
			}
		}
	}
	while (M--) {
		cin >> L >> R;
		L--;
		int ans = 0;
		for (int i = 19; i >= 0; i--) {
			if (tapi[i][L] < R) {
				ans += 1 << i;
				L = tapi[i][L];
			}
		}
		cout << ans + 1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}