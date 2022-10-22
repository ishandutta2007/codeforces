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
	vector<pair<int, int>>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.rbegin(), v.rend());
	vector<int>ans(N + 1);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += 2LL * v[i].first * ((i + 2) / 2);
		if (i & 1)ans[v[i].second] = -((i + 1) / 2);
		else ans[v[i].second] = (i / 2) + 1;
	}
	cout << sum << endl;
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