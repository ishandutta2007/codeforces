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

int p[1000001] = {};

void Solve() {
	cin >> N >> K;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<int>num(N);
	vector<int>l(N);
	vector<int>r(N);
	for (int i = 0; i < K; i++) {
		l[i] = i - K;
		r[N - i - 1] = N - i - 1 + K;
	}
	for (int i = K; i < N; i++) {
		if (v[i - K] != 1) {
			l[i] = i - K;
		}
		else {
			l[i] = l[i - K];
		}
		int p = N - i - 1;
		if (v[p + K] != 1) {
			r[p] = p + K;
		}
		else {
			r[p] = r[p + K];
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (p[v[i]] == v[i]) {
			ans += (1LL * (i - l[i]) / K * (r[i] - i) / K - 1);
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 1000000; i++) {
		if (p[i])continue;
		p[i] = i;
		for (int j = i * 2; j <= 1000000; j += i)p[j] = i;
	}
	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}