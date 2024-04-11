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

//const long long int MOD = 1000000007;
const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> L >> R >> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>w(M);
	for (auto &i : w)cin >> i;
	w.push_back(MOD*MOD);
	int index = 0;
	long long int ans = 0;
	if (N <= K) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i <= min(K, N - 1); i++) {
		while (w[index] < v[i] + L)index++;
		int ch = index + K - i;
		if (ch >= M) {
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, w[ch] + R);
	}
	cout << ans << endl;
}