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

	vector<string>s(8);
	for (auto &i : s)cin >> i;
	vector<int>v(256);
	v['Q'] = v['q'] = 9;
	v['R'] = v['r'] = 5;
	v['B'] = v['b'] = 3;
	v['N'] = v['n'] = 3;
	v['P'] = v['p'] = 1;
	for (auto i : "qrbnp") {
		v[i] *= -1;
	}
	for (auto i : s) {
		for (auto j : i) {
			N += v[j];
		}
	}
	if (N > 0) {
		cout << "White" << endl;
	}
	else if (N == 0) {
		cout << "Draw" << endl;
	}
	else {
		cout << "Black" << endl;
	}
}