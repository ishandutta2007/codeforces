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
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve(){
	cin >> N;
	vector<pair<int, int>>odd;
	vector<pair<int, int>>even;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) & 1)odd.emplace_back(i + 1, j + 1);
			else even.emplace_back(i + 1, j + 1);
		}
	}
	for (int loop = 0; loop < N * N; loop++) {
		cin >> K;
		if (K == 1) {
			if (even.size()) {
				cout << 2 << " " << even.back().first << " " << even.back().second << endl;
				even.pop_back();
			}
			else {
				cout << 3 << " " << odd.back().first << " " << odd.back().second << endl;
				odd.pop_back();
			}
		}
		else if (K == 2) {
			if (odd.size()) {
				cout << 1 << " " << odd.back().first << " " << odd.back().second << endl;
				odd.pop_back();
			}
			else {
				cout << 3 << " " << even.back().first << " " << even.back().second << endl;
				even.pop_back();
			}
		}
		else {
			if (odd.size()) {
				cout << 1 << " " << odd.back().first << " " << odd.back().second << endl;
				odd.pop_back();
			}
			else {
				cout << 2 << " " << even.back().first << " " << even.back().second << endl;
				even.pop_back();
			}
		}
	}
	return;
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