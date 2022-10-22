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
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		ans = max(ans, v[i + 1] - v[i]);
	}
	ans = max(ans, v[0] * 2);
	ans = max(ans, ((int)K - v.back())*2);
	cout << setprecision(15) << (long double)ans / 2 << endl;
	return 0;
}