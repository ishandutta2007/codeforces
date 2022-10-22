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
	vector<pair<long long int, long long int>>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	v.push_back({ LLONG_MAX,0 });
	vector<long long int>sum(N + 1);
	for (int i = 1; i <= N; i++) {
		sum[i] = v[i].second + sum[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		L = i;
		R = N + 2;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (v[mid].first - v[i].first >= K) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		M = max(M, sum[L] - sum[i - 1]);
	}
	cout << M << endl;
	return 0;
}