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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L;
	vector<long long int>v(L);
	for (auto &i : v)cin >> i;
	for (int i = 1; i < L; i++)v[i] += v[i - 1];
	K = v.back();
	M = *min_element(v.begin(), v.end());
	if (N + M <= 0) {
		for (int i = 0; i < L; i++) {
			if (N + v[i] <= 0) {
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	if (K >= 0) {
		cout << -1 << endl;
		return 0;
	}
	long long int ans = (N + M) / (-K);
	if ((N + M) % (-K))ans++;
	N += ans * K;
	ans *= L;
	//cout << N << endl;
	if (N <= 0) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < L; i++) {
		if (N + v[i] <= 0) {
			cout << ans + i + 1 << endl;
			return 0;
		}
	}
	return 0;
}