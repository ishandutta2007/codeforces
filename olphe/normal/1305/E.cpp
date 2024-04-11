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
constexpr long  double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N == 1) {
		if (M == 0)cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	vector<long long int>v(N);
	v[0] = 1, v[1] = 2;
	for (int i = 2; i < N; i++) {
		int add = i / 2;
		if (add <= M) {
			v[i] = i + 1;
			M -= add;
		}
		else if (M == 0) {
			v[i] = 1000000000 - 50000000 + i * 10000;
		}
		else {
			v[i] = i * 2 + 1 - M * 2;
			M = 0;
		}
	}
	if (M) {
		cout << -1 << endl;
		return 0;
	}
	for (auto i : v)cout << i << " ";
	cout << endl;
}