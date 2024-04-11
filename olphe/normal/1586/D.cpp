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
	cin >> N;
	int idx = 0;
	vector<int>ans(N);
	ans.back() = N;
	for (int i = 2; i <= N; i++) {
		vector<int>v(N, 1);
		v.back() = i;
		cout << "?";
		for (auto j : v)cout << " " << j;
		cout << endl;
		cin >> K;
		if (K) {
			ans.back()--;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (ans.back() == i)continue;
		vector<int>v(N, 1000 + ans.back() - i);
		v.back() = 1000;
		int mn = *min_element(v.begin(), v.end());
		for (auto& j : v) {
			j -= mn - 1;
		}
		cout << "?";
		for (auto j : v)cout << " " << j;
		cout << endl;
		cin >> K;
		ans[K - 1] = i;
	}
	cout << "!";
	for (auto j : ans)cout << " " << j;
	cout << endl;
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