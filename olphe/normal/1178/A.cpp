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
#include "functional"

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

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	M = accumulate(v.begin(), v.end(), 0LL);
	if (v[0] * 2 > M) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	K = v[0];
	vector<int>ans({ 1 });
	for (int i = 1; i < N; i++) {
		if (v[i] * 2 <= v[0]) {
			K += v[i];
			ans.push_back(i + 1);
		}
	}
	if (K * 2 > M) {
		cout << ans.size() << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
		return 0;
	}
	cout << 0 << endl;
}