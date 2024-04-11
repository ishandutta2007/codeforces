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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>box;
	long long int by = 1;
	for (int i = 1; i < N; i++) {
		if (gcd(i, N) == 1) {
			box.push_back(i);
			by *= i;
			by %= N;
		}
	}
	if (by!=1&&by == box.back()) {
		box.pop_back();
		by = 1;
	}
	if (by == 1) {
		cout << box.size() << endl;
		for (auto i : box)cout << i << " ";
		cout << endl;
		return;
	}
	else {
		cout << N << " " << "NG" << endl;
	}
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