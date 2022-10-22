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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>flag(N);
	for (int i = 1; i < N - 1; i++) {
		if (v[i] > v[i - 1] && v[i] > v[i + 1])flag[i] = 1;
		if (v[i] < v[i - 1] && v[i] < v[i + 1])flag[i] = 1;
	}
	int ans = 0;
	for (int i = 1; i < N - 1; i++) {
		int box = 0;
		if (i + 2 < N) {
			i++;
			if (v[i] > v[i - 2] && v[i] > v[i + 1])box = 1;
			if (v[i] < v[i - 2] && v[i] < v[i + 1])box = 1;
			i--;
		}
		ans = min(ans, box - (flag[i - 1] + flag[i] + flag[i + 1]));
		box = 0;
		if (i - 2 >= 0) {
			i--;
			if (v[i] > v[i - 1] && v[i] > v[i + 2])box = 1;
			if (v[i] < v[i - 1] && v[i] < v[i + 2])box = 1;
			i++;
		}
		ans = min(ans, box - (flag[i - 1] + flag[i] + flag[i + 1]));
	}
	ans+=accumulate(flag.begin(), flag.end(),0);
	cout << ans << endl;
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}