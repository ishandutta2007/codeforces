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
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cout << 1 << endl;
		cin >> v[i];
		if (!v[i]) {
			return 0;
		}
		v[i] = max(v[i], 0);
	}
	L = 2;
	R = M;
	for (int i = 0; i < 30; i++) {
		long long int mid = (L + R + 1) / 2;
		cout << mid << endl;
		cin >> K;
		if (K == 0)return 0;
		if (v[i%N]) {
			if (K == 1) {
				L = mid + 1;
			}
			else {
				R = mid - 1;
			}
		}
		else {
			if (K == 1) {
				R = mid - 1;
			}
			else {
				L = mid + 1;
			}
		}
	}
	return 0;
}