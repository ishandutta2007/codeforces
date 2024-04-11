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
	string s;
	cin >> s;
	vector<int>zero;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')zero.push_back(i);
	}
	if (zero.empty()) {
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i < zero.size(); i++) {
		if (zero[i - 1] + 1 != zero[i]) {
			cout << 2 << endl;
			return;
		}
	}
	cout << 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}