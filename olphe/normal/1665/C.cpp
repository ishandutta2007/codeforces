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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



void Solve() {
	cin >> N;
	vector<int>num(N);
	for (int i = 1; i < N; i++) {
		cin >> K;
		num[K - 1]++;
	}
	priority_queue<int>PQ;
	for (auto i : num)if (i)PQ.push(i);
	PQ.push(1);
	L = 0, R = N;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		auto Q = PQ;
		int er = mid;
		int ed = 0;
		for (int i = er; i > ed; i--) {
			if (Q.empty())break;
			int c = Q.top();
			Q.pop();
			if (c > i) {
				ed += c - i;
			}
		}
		if (Q.empty())R = mid;
		else L = mid;
	}
	cout << R << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}