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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>cost(32, LLONG_MAX / 3);
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i < 32; i++) {
		cost[i] = min(cost[i], cost[i - 1] * 2);
	}
	stack<int>s;
	for (int i = 0; i < N; i++) {
		if (M >> i & 1) {
			s.push(i);
		}
	}
	K = LLONG_MAX;
	while (!s.empty()) {
		int cn = s.top();
		long long int box = 0;
		s.pop();
		for (int i = 31; i > cn; i--) {
			if (M >> i & 1) {
				box += cost[i];
			}
		}
		long long int bag = LLONG_MAX;
		for (int i = 31; i > cn; i--) {
			bag = min(bag, cost[i]);
		}
		K = min(K, box + bag);
	}
	long long int box = 0;
	for (int i = 0; i < 32; i++) {
		if (M >> i & 1) {
			box += cost[i];
		}
	}
	K = min(K, box);
	cout << K << endl;
	return 0;
}