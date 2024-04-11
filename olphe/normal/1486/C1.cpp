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

void Solve() {
	cin >> N;
	cout << "? 1 " << N << endl;
	cin >> M;
	int ok = -1, ng = -1;
	if (M == 1) {
		ng = 1, ok = N;
	}
	else if (M == N) {
		ok = 1, ng = M;
	}
	else {
		cout << "? 1 " << M << endl;
		cin >> K;
		if (K == M) {
			ok = 1, ng = M;
		}
		else {
			ok = N, ng = M;
		}
	}
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (M < mid) {
			cout << "? " << M << " "<<mid << endl;
		}
		else {
			cout << "? " << mid << " " << M << endl;
		}
		cin >> K;
		if (K == M) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout<<"! " << ok << endl;
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