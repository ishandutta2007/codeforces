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

	cin >> N >> M;
	vector<int>a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	a.push_back(INT_MIN);
	sort(a.begin(),a.end());
	for (int i = 0; i < M; i++) {
		cin >> K;
		L = 0;
		R = N+1;
		while (R - L > 1) {
			int mid = (R + L + 1) / 2;
			if (a[mid] <= K) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		cout << L << " ";
	}
	cout << endl;
	return 0;
}