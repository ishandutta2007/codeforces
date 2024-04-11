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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	L = R = 0;
	while (N--) {
		cin >> K;
		L = max(L, K);
	}
	cin >> M;
	while (M--) {
		cin >> K;
		R = max(R, K);
	}
	if (L == R) {
		cout << "Alice\n";
		cout << "Bob\n";
	}
	else if (L > R) {
		cout << "Alice\n";
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
		cout << "Bob\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}