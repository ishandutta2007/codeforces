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
	cin >> N >> K;
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	long long ans = max(0LL, accumulate(v.begin(), v.end(), 0LL) - K);
	sort(v.begin(), v.end());
	long long sum = accumulate(v.begin(), v.end(), 0LL) - v[0];
	long long add = v[0];
	int num = 1;
	for (int i = N - 1; i > 0; i--) {
		sum -= v[i];
		add += v[0];
		num++;
		long long dif = sum + add - K;
		if (dif <= 0) {
			ans = min(ans, num - 1LL);
		}
		else {
			ans = min(ans, num - 1 + (dif + num - 1) / num);
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