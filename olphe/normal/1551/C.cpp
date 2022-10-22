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

void Solve() {
	cin >> N;
	vector<vector<int>>v;
	vector<int>sum(5);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vector<int>w(5);
		for (auto j : s) {
			w[j - 'a']++;
			sum[j - 'a']++;
		}
		v.push_back(w);
	}
	int ans = 0;
	for (int idx = 0; idx < 5; idx++) {
		vector<int>box;
		for (int i = 0; i < N; i++) {
			box.push_back(v[i][idx] * 2 - accumulate(v[i].begin(), v[i].end(), 0));
		}
		sort(box.rbegin(), box.rend());
		int num = 0;
		int cnt = 0;
		for (auto j : box) {
			cnt++;
			num += j;
			if (num > 0) {
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}