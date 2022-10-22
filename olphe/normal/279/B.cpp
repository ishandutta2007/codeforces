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

	cin >> N >> K;
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		v[i] += v[i - 1];
	}
	v.push_back(INT_MAX);
	for (int i = 1; i <= N; i++) {
		L = i - 1;
		R = N + 2;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (v[mid] - v[i - 1] > K) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		M = max(M, L - i + 1);
	}
	cout << M << endl;
	return 0;
}