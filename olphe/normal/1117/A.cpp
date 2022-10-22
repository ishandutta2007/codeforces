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
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>w(N);
	M = *max_element(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		w[i] = v[i] == M;
		if (i) {
			w[i - 1] *= w[i];
			w[i] += w[i - 1];
		}
		ans = max(ans, w[i]);
	}
	cout << ans << endl;
	return 0;
}