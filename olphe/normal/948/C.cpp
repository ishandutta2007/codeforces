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
	vector<long long int>g(N + 2);
	vector<long long int>sum(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> g[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	sum[N + 1] = LLONG_MAX;
	vector<long long int>num(N + 2);
	vector<long long int>add(N + 2);
	for (int i = 1; i <= N; i++) {
		L = i - 1;
		R = N + 1;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (sum[mid] - sum[i - 1] <= g[i]) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		num[i]++;
		num[R]--;
		add[R] += g[i] - (sum[L] - sum[i - 1]);
	}
	for (int i = 1; i <= N; i++) {
		num[i] += num[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		cout << num[i] * (sum[i] - sum[i - 1]) + add[i] << " ";
	}
	cout << endl;
	return 0;
}