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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>sum(N);
	for (int i = 0; i < N; i++) {
		cin >> sum[i];
	}
	for (int i = 1; i < N; i++) {
		sum[i] += sum[i - 1];
	}
	sum.push_back(INT_MAX);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> K;
		L = 0;
		R = N;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (sum[mid - 1] >= K) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		cout << L + 1 << endl;
	}
	return 0;
}