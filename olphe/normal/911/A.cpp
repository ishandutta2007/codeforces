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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	int m = INT_MAX;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		m = min(m, v[i]);
	}
	int l = -1;
	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (v[i] == m) {
			if (l == -1) {
				l = i;
			}
			else {
				ans = min(ans, i - l);
				l = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}