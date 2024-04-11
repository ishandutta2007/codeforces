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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>v(N);
	for (auto &i : v) {
		cin >> i;
		if (i <= M)i = 1;
		else i = 0;
	}
	for (int i = 1; i < N; i++)v[i] = (v[i - 1]+v[i])*v[i];
	v.push_back(0);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (v[i] == 0) {
			ans += max(0LL, v[i - 1] - K + 1);
		}
	}
	cout << ans << endl;
}