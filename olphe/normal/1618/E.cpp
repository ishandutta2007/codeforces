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

long long func(vector<long long>ans) {
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		long long by = N + 1 - i;
		if (by > N)by -= N;
		ret += ans[i] * by;
	}
	return ret;
}

void Solve() {
	cin >> N;
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	vector<long long>dif(N);
	for (int i = 0; i < N; i++) {
		dif[i] = v[i] - v[(i + N - 1) % N];
	}
	long long mx = *max_element(dif.begin(), dif.end());
	vector<long long>ans(N);
	for (int i = 0; i < N; i++) {
		if ((mx - dif[i]) % N) {
			cout << "NO\n";
			return;
		}
		ans[i] = (mx - dif[i]) / N;
	}
	auto ret = func(ans);
	long long d = N * (N + 1) / 2;
	if (v[0] <= ret) {
		cout << "NO\n";
		return;
	}
	if ((v[0] - ret) % d) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		cout << ans[i] + (v[0] - ret) / d << " ";
	}
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