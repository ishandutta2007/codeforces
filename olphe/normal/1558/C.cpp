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
	cin >> N;
	vector<int>v(N);
	for (auto& i : v) {
		cin >> i;
		i--;
	}
	for (int i = 0; i < N; i++) {
		if (abs(i - v[i]) & 1) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int>ans;
	while (N > 1 && ans.size() <= (int)v.size() * 5 / 2) {
		if (v[N - 1] == N - 1 && v[N - 2] == N - 2) {
			N -= 2;
			continue;
		}
		int a = -1, b = -1;
		for (int i = 0; i < N; i++) {
			if (v[i] == N - 2)a = i;
			if (v[i] == N - 1)b = i;
		}
		if (a + 1 < b) {
			ans.push_back(b + 1);
			reverse(v.begin(), v.begin() + b + 1);
			continue;
		}
		if (b + 1 < a) {
			if (b == 0) {
				ans.push_back(a);
				reverse(v.begin(), v.begin() + a);
				continue;
			}
			else {
				ans.push_back(b + 1);
				reverse(v.begin(), v.begin() + b + 1);
				continue;
			}
		}
		if (b + 1 == a) {
			if (b == 0) {
				ans.push_back(N);
				reverse(v.begin(), v.begin() + N);
				continue;
			}
			else {
				ans.push_back(a + 2);
				reverse(v.begin(), v.begin() + a + 2);
				continue;
			}
		}
		if (a + 1 == b) {
			ans.push_back(a + 2);
			reverse(v.begin(), v.begin() + a + 2);
			continue;
		}
	}
	if (ans.size() > (int)v.size() * 5 / 2) {
		cout << -1 << endl;
		return;
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
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