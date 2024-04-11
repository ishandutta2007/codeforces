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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int N, K;
	cin >> N >> K;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	long long int ans = N * K - K * (K - 1) / 2;
	long long int ret = 1;
	vector<int>w;
	for (int i = 0; i < N; i++) {
		if (v[i] > N - K)w.push_back(i);
	}
	for (int i = 1; i < w.size(); i++) {
		ret *= w[i] - w[i - 1];
		ret %= MOD;
	}
	cout << ans << " " << ret << endl;
}