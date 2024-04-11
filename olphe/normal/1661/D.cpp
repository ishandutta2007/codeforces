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
	long long add = 0;
	long long num = 0;
	vector<long long>w(N);
	long long ans = 0;
	long long mx = 0;
	for (int i = N - 1; i >= K - 1; i--) {
		add += w[i];
		num += add;
		//cout << i << " " << num << endl;
		long long c = max(0LL, (v[i] - num + K - 1) / K);
		ans += c;
		add -= c;
		num += c * K;
		if (i > K)w[i - K - 1] += c;
		if (i == K - 1) {
			for (int j = K - 2; j >= 0; j--) {
				add += w[j];
				num += add;
				mx = max(mx, (v[j] - num + j) / (j + 1));
			}
		}
	}
	ans += mx;
	cout << ans << endl;
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