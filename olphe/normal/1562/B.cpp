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
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int p[11111];

void Solve() {
	cin >> N;
	string s;
	cin >> s;
	int num[256] = {};
	for (auto i : s) {
		num[i]++;
		if (i == '1' || i == '4' || i == '6' || i == '8' || i == '9') {
			cout << 1 << endl;
			cout << i << endl;
			return;
		}
	}
	if (num['2'] >= 2) {
		cout << 2 << endl;
		cout << 22 << endl;
		return;
	}
	if (num['3'] >= 2) {
		cout << 2 << endl;
		cout << 33 << endl;
		return;
	}
	if (num['5'] >= 2) {
		cout << 2 << endl;
		cout << 55 << endl;
		return;
	}
	if (num['7'] >= 2) {
		cout << 2 << endl;
		cout << 77 << endl;
		return;
	}
	int ans = MOD;
	for (int i = 1; i < 1 << N; i++) {
		string t;
		for (int j = 0; j < N; j++) {
			if (i >> j & 1)t.push_back(s[j]);
		}
		if (p[stoi(t)] != stoi(t)) {
			ans = min(ans, stoi(t));
		}
	}
	cout << to_string(ans).size() << endl;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 10000; i++) {
		if (p[i] == 0)p[i] = i;
		else continue;
		for (int j = i * i; j <= 10000; j += i) {
			p[j] = i;
		}
	}
	cin >> T;
	while (T--) {
		Solve();
	}
}